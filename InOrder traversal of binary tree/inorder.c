/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */


int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }


    return 1 + TreeSize(root->left) + TreeSize(root->right);
}


void _inorderTraversal(struct TreeNode* root, int* array, int* i)
{
    if (root == NULL)
    {
        return;
    }


    _inorderTraversal(root->left, array, i);
    array[(*i)++] = root->val;
    _inorderTraversal(root->right, array, i);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = TreeSize(root);
    int* array = (int*)malloc(sizeof(int) * size);


    int i = 0;
    _inorderTraversal(root, array, &i);


    *returnSize = size;
    return array;
}