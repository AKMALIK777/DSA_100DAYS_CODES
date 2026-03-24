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

// Recursive function to count leaf nodes
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0; // Empty tree
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // Leaf node
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Driver code
int main() {
   
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));

    return 0;
}
