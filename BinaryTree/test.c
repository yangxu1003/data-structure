#include "BTree.h"
#include "Queue.h"

//前序
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}

//中序
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

//后序
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}

//二叉树结点个数
int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + TreeSize(root->_left) + TreeSize(root->_right);
	}
}

//叶子结点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//当某个结点的左右子树均为空时，此结点是叶子结点，返回1
	if(root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}

	return TreeSize(root->_left) + TreeSize(root->_right);
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data= a[*pi];
		++(*pi);

		//创建左子树和右子树
		root->_left = BinaryTreeCreate(a, pi);
		root->_right = BinaryTreeCreate(a, pi);

		return root;
	}
}

// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreeDestory(root->_left);
		BinaryTreeDestory(root->_right);
		free(root);
	}
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//第k层转换成求k-1层的左右子树的结点数，
	//K=1层就不用分解了，
	if (root == NULL)
	{
		return 0;
	}
	
	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->_data == x)
	{
		return root;
	}

	//当前结点不为空也不等于x,遍历左子树
	BTNode* temp = BinaryTreeFind(root->_left, x);
	if (temp != NULL)
	{
		return temp;
	}

	//左子树返回空，遍历右子树
	return BinaryTreeFind(root->_right, x);
	
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_data);

		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}

		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}

}

// 判断二叉树是否是完全二叉树
//是返回1，不是返回0
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{
			break;//遇到空跳出
		}
	
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueueDestory(&q);
			return 0;
		}
	}

	QueueDestory(&q);
	return 1;
}

int main()
{
	char str[100];
	scanf("%s", str);

	int i = 0;
	BTNode* root = BinaryTreeCreate(str, &i);

	InOrder(root);
	printf("\n");

	return 0;
}