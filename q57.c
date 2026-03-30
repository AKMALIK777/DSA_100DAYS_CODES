#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        if (curr != NULL) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[rear++] = curr->left;
            if (i < n) {
                curr->right = newNode(arr[i++]);
                if (curr->right) queue[rear++] = curr->right;
            }
        }
    }
    free(queue);
    return root;
}

// Function to convert tree to its mirror
void mirror(struct Node* root) {
    if (root == NULL) return;
    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recurse for children
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    // Convert to mirror
    mirror(root);

    // Print inorder traversal
    inorder(root);
    printf("\n");

    return 0;
}
