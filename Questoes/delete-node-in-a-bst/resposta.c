/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buscarMenor(struct TreeNode* no) {
    while (no->left != NULL) {
        no = no->left;
    }
    return no;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else { // Remoção
        if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        }

        struct TreeNode* noMenor = buscarMenor(root->right);
        root->val = noMenor->val;
        root->right = deleteNode(root->right, noMenor->val);
    }
    return root;
}
