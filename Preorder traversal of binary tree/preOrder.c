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


void _preorderTraversal(struct TreeNode* root, int* array, int* i)
{
    if (root == NULL)
    {
        return;
    }


    array[(*i)++] = root->val;
    _preorderTraversal(root->left, array, i);
    _preorderTraversal(root->right, array, i);
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) {


    int size = TreeSize(root);
    *returnSize = size;
    int* array = (int*)malloc(sizeof(int) * size);


    int i = 0;
    _preorderTraversal(root, array, &i);



    return array;
}