/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isUnivalTree(struct TreeNode* root) {
    //�������壬��Ϊroot,��������������
    if (root == NULL)
    {
        return true;
    }

    //��ǰ��
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