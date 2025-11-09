#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inOrder(struct TreeNode* root, int* arr, int* size) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left, arr, size);
    arr[(*size)++] = root->val;
    inOrder(root->right, arr, size);
}

struct TreeNode* construirBalanceada(int* arr, int inicio, int fim) {
    if (inicio > fim) {
        return NULL;
    }
    
    int meio = (inicio + fim) / 2;

    struct TreeNode* no = malloc(sizeof(struct TreeNode));
    no->val = arr[meio];
    no->left = construirBalanceada(arr, inicio, meio - 1);
    no->right = construirBalanceada(arr, meio + 1, fim);
    return no;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    int arr[10000];
    int size = 0;

    inOrder(root, arr, &size);
    return construirBalanceada(arr, 0, size - 1);
}
