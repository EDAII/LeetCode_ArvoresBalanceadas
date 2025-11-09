/**
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxGlobal;

int dfs(struct TreeNode* no, int* menor, int* maior, int* soma) {
    if (!no) {
        *soma = 0;
        return 1;
    }

    int menorEsq, maiorEsq, somaEsq;
    int menorDir, maiorDir, somaDir;
    int bstEsq = 1, bstDir = 1;

    if (no->left) {
        bstEsq = dfs(no->left, &menorEsq, &maiorEsq, &somaEsq);
    } else {
        somaEsq = 0;
        maiorEsq = no->val - 1;
        menorEsq = no->val;
    }

    if (no->right) {
        bstDir = dfs(no->right, &menorDir, &maiorDir, &somaDir);
    } else {
        somaDir = 0;
        menorDir = no->val + 1;
        maiorDir = no->val;
    }

    if (bstEsq && bstDir && no->val > maiorEsq && no->val < menorDir) {
        *soma = no->val + somaEsq + somaDir;

        *menor = (no->left) ? menorEsq : no->val;
        *maior = (no->right) ? maiorDir : no->val;

        if (*soma > maxGlobal) {
            maxGlobal = *soma;
        }
        return 1;
    }

    *soma = 0;
    return 0;
}

int maxSumBST(struct TreeNode* raiz) {
    maxGlobal = 0;
    int menor, maior, soma;
    dfs(raiz, &menor, &maior, &soma);
    return maxGlobal;
}
