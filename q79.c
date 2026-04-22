#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure for adjacency list
Node* adj[MAX];

// Min-heap node
typedef struct HeapNode {
    int vertex;
    int dist;
} HeapNode;

// Min-heap
typedef struct MinHeap {
    int size;
    int capacity;
    int *pos;
    HeapNode **array;
} MinHeap;

// Create new adjacency node
Node* newNode(int v, int w) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

// Swap two heap nodes
void swapHeapNode(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Create min heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc((capacity+1) * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (HeapNode**)malloc((capacity+1) * sizeof(HeapNode*));
    return minHeap;
}

// Create heap node
HeapNode* newHeapNode(int v, int dist) {
    HeapNode* heapNode = (HeapNode*)malloc(sizeof(HeapNode));
    heapNode->vertex = v;
    heapNode->dist = dist;
    return heapNode;
}

// Heapify
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2*idx;
    int right = 2*idx + 1;

    if (left <= minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right <= minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        HeapNode* smallestNode = minHeap->array[smallest];
        HeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->vertex] = idx;
        minHeap->pos[idxNode->vertex] = smallest;

        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Extract min
HeapNode* extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;

    HeapNode* root = minHeap->array[1];
    HeapNode* lastNode = minHeap->array[minHeap->size];
    minHeap->array[1] = lastNode;

    minHeap->pos[root->vertex] = minHeap->size;
    minHeap->pos[lastNode->vertex] = 1;

    minHeap->size--;
    minHeapify(minHeap, 1);

    return root;
}

// Decrease key
void decreaseKey(MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    while (i > 1 && minHeap->array[i]->dist < minHeap->array[i/2]->dist) {
        minHeap->pos[minHeap->array[i]->vertex] = i/2;
        minHeap->pos[minHeap->array[i/2]->vertex] = i;
        swapHeapNode(&minHeap->array[i], &minHeap->array[i/2]);
        i = i/2;
    }
}

// Check if vertex is in heap
int isInMinHeap(MinHeap* minHeap, int v) {
    return minHeap->pos[v] <= minHeap->size;
}

// Dijkstra’s algorithm
void dijkstra(int src, int n) {
    int dist[MAX];
    for (int v = 1; v <= n; v++) dist[v] = INT_MAX;
    dist[src] = 0;

    MinHeap* minHeap = createMinHeap(n);
    for (int v = 1; v <= n; v++) {
        minHeap->array[v] = newHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }
    minHeap->size = n;

    while (minHeap->size > 0) {
        HeapNode* heapNode = extractMin(minHeap);
        int u = heapNode->vertex;

        Node* crawl = adj[u];
        while (crawl != NULL) {
            int v = crawl->vertex;
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
                crawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + crawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            crawl = crawl->next;
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize adjacency list
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Node* node1 = newNode(v, w);
        node1->next = adj[u];
        adj[u] = node1;

        Node* node2 = newNode(u, w);
        node2->next = adj[v];
        adj[v] = node2;
    }

    int src;
    scanf("%d", &src);

    dijkstra(src, n);

    return 0;
}
