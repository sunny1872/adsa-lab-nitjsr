#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // adjust as needed

int main() {
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);

    // adjacency list using static arrays
    int adj[MAX][MAX];
    int deg[MAX];
    int count[MAX];
    int i, j;

    // initialize arrays
    for (i = 0; i < nodes; i++) {
        deg[i] = 0;
        count[i] = 0;
        for (j = 0; j < nodes; j++)
            adj[i][j] = -1;  // -1 means no edge
    }

    // read edges
    for (i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][count[u]++] = v;
        deg[v]++;
    }

    // queue for nodes with indegree 0
    int queue[MAX];
    int front = 0, rear = 0;

    // push all nodes with 0 indegree
    for (i = 0; i < nodes; i++) {
        if (deg[i] == 0)
            queue[rear++] = i;
    }

    // Kahn's algorithm
    while (front < rear) {
        int node = queue[front++];
        printf("%d,", node);

        for (i = 0; i < count[node]; i++) {
            int child = adj[node][i];
            if (child != -1 && deg[child] > 0) {
                deg[child]--;
                if (deg[child] == 0)
                    queue[rear++] = child;
            }
        }
    }

    printf("\n");
    return 0;
}
