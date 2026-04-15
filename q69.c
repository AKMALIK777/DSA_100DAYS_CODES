#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for heap node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

// Min-heap structure
typedef struct {
    HeapNode *nodes;
    int size;
} MinHeap;

int V; // number of vertices
int adj[MAX][MAX]; // adjacency matrix

// Utility: swap two heap nodes
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify down
void heapifyDown(MinHeap *heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->nodes[left].dist < heap->nodes[smallest].dist)
        smallest = left;
    if (right < heap->size && heap->nodes[right].dist < heap->nodes[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap->nodes[i], &heap->nodes[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Heapify up
void heapifyUp(MinHeap *heap, int i) {
    int parent = (i - 1) / 2;
    if (i && heap->nodes[i].dist < heap->nodes[parent].dist) {
        swap(&heap->nodes[i], &heap->nodes[parent]);
        heapifyUp(heap, parent);
    }
}

// Extract minimum
HeapNode extractMin(MinHeap *heap) {
    HeapNode root = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

// Insert node
void insertHeap(MinHeap *heap, int vertex, int dist) {
    heap->nodes[heap->size].vertex = vertex;
    heap->nodes[heap->size].dist = dist;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

// Dijkstra’s Algorithm
void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    MinHeap heap;
    heap.nodes = (HeapNode*)malloc(V * sizeof(HeapNode));
    heap.size = 0;

    insertHeap(&heap, src, 0);

    while (heap.size > 0) {
        HeapNode node = extractMin(&heap);
        int u = node.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !visited[v]) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    insertHeap(&heap, v, dist[v]);
                }
            }
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d : INF\n", i);
        else
            printf("%d : %d\n", i, dist[i]);
    }

    free(heap.nodes);
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

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w; // directed edge u -> v
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}
