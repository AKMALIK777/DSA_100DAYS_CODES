#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // visited array
int stack[MAX];      // stack to store topological order
int top = -1;        // stack pointer
int V;               // number of vertices

// DFS utility
void dfs(int v) {
    visited[v] = 1;
    for (int u = 0; u < V; u++) {
        if (adj[v][u] && !visited[u]) {
            dfs(u);
        }
    }
    // push to stack after exploring neighbors
    stack[++top] = v;
}

// Function to perform Topological Sort
void topologicalSort() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Ordering: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
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

    // initialize visited array
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    topologicalSort();

    return 0;
}
