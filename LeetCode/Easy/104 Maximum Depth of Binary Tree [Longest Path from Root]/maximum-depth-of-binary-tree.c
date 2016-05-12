/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b){
    return a>b?a:b;
}

int maxDepth(struct TreeNode* root) {
    return findDepth(root,0);
}

int findDepth(struct TreeNode* root, int count){
    if(root==NULL)
        return count;
    else
        return max(findDepth(root->left,count+1),findDepth(root->right,count+1));
}
