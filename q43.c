#include <stdio.h>
#include <stdlib.h>

// Define a node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Queue structure for level-order construction
typedef struct {
    Node* arr[100];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear == 99) return; // overflow check
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    Node* temp = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return temp;
}

// Create new node
Node* newNode(int data) {
    if (data == -1) return NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order array
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);
    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;
    while (i < n && !isEmpty(&q)) {
        Node* current = dequeue(&q);

        // Left child
        if (i < n) {
            current->left = newNode(arr[i]);
            if (current->left) enqueue(&q, current->left);
            i++;
        }

        // Right child
        if (i < n) {
            current->right = newNode(arr[i]);
            if (current->right) enqueue(&q, current->right);
            i++;
        }
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Driver code
int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, N);

    inorder(root);
    printf("\n");

    return 0;
}
