#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);   // number of vertices
    scanf("%d", &m);   // number of edges

    // Initialize adjacency matrix with 0s
    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Assuming vertices are 1-indexed in input
        adj[u - 1][v - 1] = 1;   // Directed edge u → v

        // For undirected graph, also add reverse edge
        // Uncomment the next line if graph is undirected:
        // adj[v - 1][u - 1] = 1;
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
