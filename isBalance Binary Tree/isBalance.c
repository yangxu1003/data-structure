/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool _isBalanced(struct TreeNode* root, int* depth)
{
    //×Ôµ×ÏòÉÏ
    if (root == NULL)
    {
        *depth = 0;
        return true;
    }
    else
    {
        int leftDepth = 0;
        if (_isBalanced(root->left, &leftDepth) == false)
        {
            return false;
        }


        int rightDepth = 0;
        if (_isBalanced(root->right, &rightDepth) == false)
        {
            return false;
        }


        if (abs(leftDepth - rightDepth) > 1)
        {
            return false;
        }


        *depth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
        return  true;
    }
}


bool isBalanced(struct TreeNode* root) {
    int depth = 0;
    return _isBalanced(root, &depth);
}