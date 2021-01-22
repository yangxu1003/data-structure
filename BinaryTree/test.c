#include "BTree.h"
#include "Queue.h"

//ǰ��
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

//����
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

//����
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

//������������
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

//Ҷ�ӽ�����
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//��ĳ����������������Ϊ��ʱ���˽����Ҷ�ӽ�㣬����1
	if(root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}

	return TreeSize(root->_left) + TreeSize(root->_right);
}

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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

		//������������������
		root->_left = BinaryTreeCreate(a, pi);
		root->_right = BinaryTreeCreate(a, pi);

		return root;
	}
}

// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreeDestory(root->_left);
		BinaryTreeDestory(root->_right);
		free(root);
	}
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//��k��ת������k-1������������Ľ������
	//K=1��Ͳ��÷ֽ��ˣ�
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

// ����������ֵΪx�Ľڵ�
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

	//��ǰ��㲻Ϊ��Ҳ������x,����������
	BTNode* temp = BinaryTreeFind(root->_left, x);
	if (temp != NULL)
	{
		return temp;
	}

	//���������ؿգ�����������
	return BinaryTreeFind(root->_right, x);
	
}

// �������
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

// �ж϶������Ƿ�����ȫ������
//�Ƿ���1�����Ƿ���0
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
			break;//����������
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