#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Search for index of value in inorder[]
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

// Recursive function to build tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end) return NULL;

    // Pick current node from postorder (root is at end)
    struct Node* node = newNode(postorder[*postIndex]);
    (*postIndex)--;

    // If leaf node
    if (start == end) return node;

    // Find index in inorder
    int inIndex = search(inorder, start, end, node->data);

    // Build right subtree first (since postorder is left-right-root)
    node->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    node->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return node;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int inorder[N], postorder[N];
    for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < N; i++) scanf("%d", &postorder[i]);

    int postIndex = N - 1;
    struct Node* root = buildTree(inorder, postorder, 0, N - 1, &postIndex);

    preorder(root);
    return 0;
}
