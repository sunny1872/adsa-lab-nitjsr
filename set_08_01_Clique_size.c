// find_clique.c  -- finds whether graph has clique of size m (n <= 64)
#include <stdio.h>
#include <stdint.h>

int n, m;
uint64_t adj[64];
int found = 0;

static inline int popcnt(uint64_t x){ return __builtin_popcountll(x); }

/* Bron–Kerbosch with pivot and early stop: R(current clique size), P(candidates), X(excluded) */
void bronk(int r, uint64_t P, uint64_t X){
    if(found) return;
    if(r + popcnt(P) < m) return;   // pruning: even taking all P cannot reach m
    if(P == 0 && X == 0){
        if(r >= m) found = 1;
        return;
    }
    // choose pivot u from P|X (vertex with max neighbors in P)
    uint64_t U = P | X;
    int pivot = -1, best = -1;
    for(uint64_t tmp = U; tmp; tmp &= tmp - 1){
        int u = __builtin_ctzll(tmp);
        int cnt = popcnt(P & adj[u]);
        if(cnt > best){ best = cnt; pivot = u; }
    }
    uint64_t candidates = P & ~(pivot >= 0 ? adj[pivot] : 0ULL);
    while(candidates){
        int v = __builtin_ctzll(candidates);
        candidates &= candidates - 1;
        uint64_t vbit = 1ULL << v;
        bronk(r + 1, P & adj[v], X & adj[v]);
        if(found) return;
        P &= ~vbit;
        X |= vbit;
    }
}

int main(void){
    int e;
    if(scanf("%d %d %d",&n,&e,&m)!=3) return 0;
    if(n <= 0 || m <= 0){ printf("NO\n"); return 0; }
    if(m == 1){ printf("YES\n"); return 0; }
    if(n > 64){ fprintf(stderr,"This program supports n <= 64\n"); return 0; }
    for(int i=0;i<n;i++) adj[i]=0;
    for(int i=0,u,v;i<e;i++){
        scanf("%d %d",&u,&v); // assume 0-based vertices
        if(u<0||v<0||u>=n||v>=n) continue;
        adj[u] |= (1ULL<<v);
        adj[v] |= (1ULL<<u);
    }
    uint64_t P = (n==64?~0ULL:((1ULL<<n)-1ULL)); // all vertices
    bronk(0, P, 0ULL);
    printf(found ? "YES\n" : "NO\n");
    return 0;
}
