#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Recursive function to search in BST
struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->val == key) {
        return root; // Found or empty tree
    }
    if (key < root->val) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Driver code
int main() {
    struct TreeNode* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int key = 60;
    struct TreeNode* result = search(root, key);

    if (result != NULL) {
        printf("Key %d found in BST.\n", key);
    } else {
        printf("Key %d not found in BST.\n", key);
    }

    return 0;
}
