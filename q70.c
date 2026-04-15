#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure to represent an edge
typedef struct {
    int u, v, w;
} Edge;

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    Edge edges[E];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    // Initialize distances
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    int hasCycle = 0;
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasCycle = 1;
            break;
        }
    }

    if (hasCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        printf("Shortest distances from source %d:\n", src);
        for (int i = 0; i < V; i++) {
            if (dist[i] == INF)
                printf("%d : INF\n", i);
            else
                printf("%d : %d\n", i, dist[i]);
        }
    }

    return 0;
}
