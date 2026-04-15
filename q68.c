#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int indegree[MAX];   // in-degree array
int V;               // number of vertices

// Function to perform Kahn's Algorithm
void topologicalSort() {
    int queue[MAX], front = 0, rear = 0;
    int count = 0;

    // enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Ordering: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        // decrease in-degree of neighbors
        for (int u = 0; u < V; u++) {
            if (adj[v][u]) {
                indegree[u]--;
                if (indegree[u] == 0) {
                    queue[rear++] = u;
                }
            }
        }
    }

    // if count != V, graph has a cycle
    if (count != V) {
        printf("\nGraph is not a DAG (contains cycle)\n");
    } else {
        printf("\n");
    }
}

int main() {
    int E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // initialize adjacency matrix and indegree
    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;  // increase in-degree of v
    }

    topologicalSort();

    return 0;
}
