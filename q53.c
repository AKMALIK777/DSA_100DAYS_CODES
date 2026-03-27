#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue for building tree
struct Queue {
    struct Node **arr;
    int front, rear, size;
};

// Create new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue functions
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);
    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct Node* curr = dequeue(q);
        if (curr) {
            curr->left = newNode(arr[i++]);
            if (curr->left) enqueue(q, curr->left);
            if (i < n) {
                curr->right = newNode(arr[i++]);
                if (curr->right) enqueue(q, curr->right);
            }
        }
    }
    return root;
}

// Structure for BFS with HD
struct Pair {
    struct Node* node;
    int hd;
};

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // Map using array (HD range assumed -1000 to 1000)
    int offset = 1000;
    int maxHD = -1000, minHD = 1000;
    int *columns[2001];   // store node values
    int sizes[2001] = {0};

    struct Pair queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair p = queue[front++];
        struct Node* node = p.node;
        int hd = p.hd;

        if (!columns[hd + offset]) {
            columns[hd + offset] = (int*)malloc(1000 * sizeof(int));
        }
        columns[hd + offset][sizes[hd + offset]++] = node->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left) queue[rear++] = (struct Pair){node->left, hd - 1};
        if (node->right) queue[rear++] = (struct Pair){node->right, hd + 1};
    }

    // Print columns
    for (int hd = minHD; hd <= maxHD; hd++) {
        for (int i = 0; i < sizes[hd + offset]; i++) {
            printf("%d ", columns[hd + offset][i]);
        }
        printf("\n");
    }
}

// Driver
int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, N);
    verticalOrder(root);

    return 0;
}
