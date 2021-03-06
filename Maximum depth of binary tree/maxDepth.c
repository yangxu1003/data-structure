/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }

    int leftDepth = maxDepth(root->left) + 1; //加上根结点的深度
    int rightDepth = maxDepth(root->right) + 1;

    return leftDepth > rightDepth ? leftDepth : rightDepth;
}