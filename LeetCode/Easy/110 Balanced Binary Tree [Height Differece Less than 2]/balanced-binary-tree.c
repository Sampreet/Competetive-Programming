/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isBalancedTree(struct TreeNode *root, int* height)
{
    int lh = 0, rh = 0;
    int l = 0, r = 0;

    if(root == NULL){
        *height = 0;
        return 1;
    }

    l = isBalancedTree(root->left, &lh);
    r = isBalancedTree(root->right,&rh);

    *height = (lh > rh? lh: rh) + 1;

    if((lh - rh >= 2) || (rh - lh >= 2))
        return 0;

    else
        return l&&r;
}

bool isBalanced(struct TreeNode* root) {
    int height=0;
    return isBalancedTree(root,&height);
}
