#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// adjacency list
typedef struct {
    Node** list;
    int V;
} Graph;

// create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// initialize graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->list = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++)
        graph->list[i] = NULL;
    return graph;
}

// add undirected edge
void addEdge(Graph* graph, int u, int v) {
    Node* node = createNode(v);
    node->next = graph->list[u];
    graph->list[u] = node;

    node = createNode(u);
    node->next = graph->list[v];
    graph->list[v] = node;
}

// DFS with parent tracking
bool dfsCycle(Graph* graph, int v, bool visited[], int parent) {
    visited[v] = true;
    Node* temp = graph->list[v];
    while (temp) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            if (dfsCycle(graph, neighbor, visited, v))
                return true;
        } else if (neighbor != parent) {
            return true; // cycle found
        }
        temp = temp->next;
    }
    return false;
}

// check if graph has cycle
bool hasCycle(Graph* graph) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfsCycle(graph, i, visited, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    Graph* graph = createGraph(V);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (hasCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
