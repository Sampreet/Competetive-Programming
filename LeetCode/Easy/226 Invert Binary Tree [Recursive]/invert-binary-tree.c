/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==NULL){
        return root;
    }
    struct TreeNode* temp=root->right;
    root->right=root->left;
    root->left=temp;
    temp=invertTree(root->right);
    temp=invertTree(root->left);
    return root;
}
