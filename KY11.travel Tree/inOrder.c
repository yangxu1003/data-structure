#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode
{
    char val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

//先序建树
BTNode* CreateBinaryTree(char* str, int* pi)
{
    if (str[*pi] == '#')
    {
        ++(*pi);
        return NULL;
    }
    else
    {
        BTNode* root = (BTNode*)malloc(sizeof(BTNode));
        root->val = str[*pi];
        ++(*pi);

        root->left = CreateBinaryTree(str, pi);
        root->right = CreateBinaryTree(str, pi);

        return root;
    }
}

//中序遍历输出
void InOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}


int main()
{
    char str[100];
    scanf("%s", str);

    int i = 0;
    BTNode* root = CreateBinaryTree(str, &i);

    InOrder(root);
    printf("\n");
    return 0;
}