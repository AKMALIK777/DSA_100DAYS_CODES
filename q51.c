#include <stdio.h>
#include <stdlib.h>

// Define structure for a tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
struct TreeNode* LCA(struct TreeNode* root, int p, int q) {
    if (root == NULL) return NULL;

    if (p < root->val && q < root->val)
        return LCA(root->left, p, q);
    else if (p > root->val && q > root->val)
        return LCA(root->right, p, q);
    else
        return root; // Split point → LCA
}

int main() {
    int N;
    scanf("%d", &N);

    struct TreeNode* root = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct TreeNode* lca = LCA(root, p, q);
    if (lca != NULL)
        printf("%d\n", lca->val);
    else
        printf("LCA not found\n");

    return 0;
}
