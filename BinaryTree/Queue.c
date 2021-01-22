#include "Queue.h"
//��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

//���ٶ���
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}

	pq->_head = pq->_tail = NULL;
}

//��β���
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//�����¿ռ�
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("�ڴ治��\n");
		exit(-1);
	}

	newNode->_data = x;
	newNode->_next = NULL;
	//�п�
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail = newNode;
	}
	else
	{
		//��Ϊ�ղ����β������βָ������
		pq->_tail->_next = newNode;
		pq->_tail = newNode;
	}
}

//��ͷ����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_head);
	//�ͷŶ�ͷʹ��ָ����һ�����
	QueueNode* next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;
	//�ж�ֻʣһ��Ԫ�ص�ʱ��
	if (pq->_head == NULL)
	{
		pq->_tail = NULL;
	}
}

//ȡ��ͷԪ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_head);

	return pq->_head->_data;
}

//ȡ��βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_tail);

	return pq->_tail->_data;
}

//����1�ǿ�  ����0�Ƿǿ�
int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->_head == NULL ? 1 : 0;
}

//��ȡ���ݸ���
int QueueSize(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->_head;
	int size = 0;//����
	while (cur)
	{
		++size;
		cur = cur->_next;
	}

	return size;
}