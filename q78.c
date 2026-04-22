#include <stdio.h>
#include <limits.h>

#define MAX 1000

int adj[MAX][MAX];   // adjacency matrix
int n, m;

int primMST() {
    int key[MAX];       // minimum weight edge to include vertex
    int parent[MAX];    // parent array (not used for weight, but for MST edges)
    int inMST[MAX];     // whether vertex is included in MST

    // Initialize arrays
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
        parent[i] = -1;
    }

    // Start from vertex 1
    key[1] = 0;

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        // Pick vertex u not in MST with minimum key
        int min = INT_MAX, u = -1;
        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        inMST[u] = 1;
        totalWeight += key[u];  // add edge weight

        // Update keys of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // undirected graph
    }

    int result = primMST();
    printf("%d\n", result);

    return 0;
}
