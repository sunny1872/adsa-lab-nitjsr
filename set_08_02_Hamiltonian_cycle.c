// ham_cycle.c  -- decide existence of Hamiltonian cycle (exact, bitmask DP)
// Input: n e
// then e lines: u v   (0-based vertices, undirected)
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void){
    int n,e;
    if(scanf("%d %d",&n,&e)!=2) return 0;
    if(n<=0){ printf("NO\n"); return 0; }
    if(n==1){
        int u,v, self=0;
        for(int i=0;i<e;i++){ scanf("%d %d",&u,&v); if(u==0 && v==0) self=1; }
        printf(self ? "YES\n" : "NO\n");
        return 0;
    }
    if(n>22){ fprintf(stderr,"n too large for exact DP (use n<=22)\n"); printf("UNKNOWN\n"); return 0; }

    uint32_t *adj = calloc(n, sizeof(uint32_t));
    for(int i=0;i<e;i++){
        int u,v; scanf("%d %d",&u,&v);
        if(u>=0 && u<n && v>=0 && v<n){
            adj[u] |= (1u<<v);
            adj[v] |= (1u<<u);
        }
    }

    int N = 1<<n;
    // dp[mask][v] as bit: whether there is a path starting at 0, visiting mask, ending at v
    // store as array of chars for memory
    unsigned char *dp = calloc((size_t)N * n, 1);
    dp[(1<<0) * n + 0] = 1;

    for(int mask = 1; mask < N; ++mask){
        if(!(mask & 1)) continue; // must include start 0
        for(int u = 0; u < n; ++u){
            if(!(mask & (1<<u))) continue;
            if(!dp[mask * n + u]) continue;
            uint32_t can = adj[u] & (~(uint32_t)mask); // neighbors not yet visited
            while(can){
                int v = __builtin_ctz(can);
                can &= can - 1;
                dp[((mask | (1<<v)) * n) + v] = 1;
            }
        }
    }

    int full = N - 1;
    int ok = 0;
    for(int v = 1; v < n; ++v){
        if(dp[full * n + v] && (adj[v] & 1u)){ ok = 1; break; }
    }

    printf(ok ? "YES\n" : "NO\n");

    free(adj); free(dp);
    return 0;
}
