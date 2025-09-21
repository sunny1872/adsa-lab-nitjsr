#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100005
#define MAXM 200005

typedef struct Edge {
    int v;
    int w;
    struct Edge* next;
} Edge;

typedef struct {
    int v;
    int w;
} PQNode;

Edge* adj[MAXN];
int visited[MAXN];

// Min-heap for priority queue
PQNode heap[MAXM];
int heapSize = 0;

void swapPQ(int i, int j) {
    PQNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void pushPQ(int v, int w) {
    heap[++heapSize].v = v;
    heap[heapSize].w = w;
    int i = heapSize;
    while (i > 1 && heap[i].w < heap[i/2].w) {
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
        if (l <= heapSize && heap[l].w < heap[smallest].w) smallest = l;
        if (r <= heapSize && heap[r].w < heap[smallest].w) smallest = r;
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

void addEdge(int u, int v, int w) {
    Edge* e = (Edge*) malloc(sizeof(Edge));
    e->v = v;
    e->w = w;
    e->next = adj[u];
    adj[u] = e;
}

int spanningTree(int V) {
    for (int i = 0; i < V; i++) visited[i] = 0;

    int res = 0;
    pushPQ(0, 0);  // start from vertex 0

    while (!isEmptyPQ()) {
        PQNode p = popPQ();
        int u = p.v;
        int wt = p.w;

        if (visited[u]) continue;

        res += wt;
        visited[u] = 1;

        for (Edge* e = adj[u]; e != NULL; e = e->next) {
            if (!visited[e->v]) {
                pushPQ(e->v, e->w);
            }
        }
    }

    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // undirected
    }

    int mstWeight = spanningTree(n);
    printf("%d\n", mstWeight);

    return 0;
}
