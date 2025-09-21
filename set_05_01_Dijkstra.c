#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF LLONG_MAX
#define MAXN 100005
#define MAXM 200005

typedef long long ll;

typedef struct Edge {
    int v;
    ll w;
    struct Edge* next;
} Edge;

Edge* adj[MAXN];   // adjacency list
int parent[MAXN];  // parent array
ll dist[MAXN];     // distance array

// Priority queue node
typedef struct {
    int v;
    ll d;
} PQNode;

// Min-heap for priority queue
PQNode heap[MAXM];
int heapSize = 0;

void swapPQ(int i, int j) {
    PQNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void pushPQ(int v, ll d) {
    heap[++heapSize].v = v;
    heap[heapSize].d = d;
    int i = heapSize;
    while (i > 1 && heap[i].d < heap[i/2].d) {
        swapPQ(i, i/2);
        i /= 2;
    }
}

PQNode popPQ() {
    PQNode top = heap[1];
    heap[1] = heap[heapSize--];
    int i = 1;
    while (1) {
        int l = 2*i, r = 2*i+1, smallest = i;
        if (l <= heapSize && heap[l].d < heap[smallest].d) smallest = l;
        if (r <= heapSize && heap[r].d < heap[smallest].d) smallest = r;
        if (smallest != i) {
            swapPQ(i, smallest);
            i = smallest;
        } else break;
    }
    return top;
}

int isEmptyPQ() {
    return heapSize == 0;
}

void addEdge(int u, int v, ll w) {
    Edge* e = (Edge*) malloc(sizeof(Edge));
    e->v = v;
    e->w = w;
    e->next = adj[u];
    adj[u] = e;
}

void dijkstra(int source, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;
    parent[source] = source;
    pushPQ(source, 0);

    while (!isEmptyPQ()) {
        PQNode cur = popPQ();
        int u = cur.v;
        ll d = cur.d;

        if (d > dist[u]) continue;

        for (Edge* e = adj[u]; e != NULL; e = e->next) {
            int v = e->v;
            ll w = e->w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pushPQ(v, dist[v]);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) adj[i] = NULL;

    while (m--) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int source = 1;
    dijkstra(source, n);

    if (dist[n] == INF) {
        printf("-1\n");
        return 0;
    }

    // Reconstruct path
    int path[MAXN], len = 0;
    int node = n;
    while (parent[node] != node) {
        path[len++] = node;
        node = parent[node];
    }
    path[len++] = source;

    // Print path in correct order
    for (int i = len - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");

    return 0;
}
