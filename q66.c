#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // visited array
int recStack[MAX];   // recursion stack
int V;               // number of vertices

// Utility function for DFS
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int u = 0; u < V; u++) {
        if (adj[v][u]) { // edge v -> u
            if (!visited[u] && dfs(u)) {
                return 1; // cycle found
            } else if (recStack[u]) {
                return 1; // cycle found
            }
        }
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
}

// Function to detect cycle
int isCyclic() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    // initialize visited and recursion stack
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    if (isCyclic())
        printf("YES\n");  // cycle exists
    else
        printf("NO\n");   // no cycle

    return 0;
}
