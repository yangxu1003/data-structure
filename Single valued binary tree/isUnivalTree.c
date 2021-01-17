/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isUnivalTree(struct TreeNode* root) {
    //看成整体，分为root,左子树，右子树
    if (root == NULL)
    {
        return true;
    }

    //当前树
    if (root->left && root->val != root->left->val)
    {
        return false;
    }
    if (root->right && root->val != root->right->val)
    {
        return false;
    }

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}