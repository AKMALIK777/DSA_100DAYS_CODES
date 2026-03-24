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

// Build tree from level-order input (-1 represents NULL)
struct TreeNode* buildTree(int arr[], int n, int index) {
    if (index >= n || arr[index] == -1) return NULL;

    struct TreeNode* root = newNode(arr[index]);
    root->left = buildTree(arr, n, 2 * index + 1);
    root->right = buildTree(arr, n, 2 * index + 2);

    return root;
}

// Find LCA in Binary Tree
struct TreeNode* LCA(struct TreeNode* root, int p, int q) {
    if (root == NULL) return NULL;

    if (root->val == p || root->val == q) return root;

    struct TreeNode* leftLCA = LCA(root->left, p, q);
    struct TreeNode* rightLCA = LCA(root->right, p, q);

    if (leftLCA && rightLCA) return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct TreeNode* root = buildTree(arr, N, 0);

    struct TreeNode* lca = LCA(root, p, q);
    if (lca != NULL)
        printf("%d\n", lca->val);
    else
        printf("LCA not found\n");

    return 0;
}
