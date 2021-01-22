#include "Queue.h"
//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

//销毁队列
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

//队尾入队
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//申请新空间
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("内存不足\n");
		exit(-1);
	}

	newNode->_data = x;
	newNode->_next = NULL;
	//判空
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail = newNode;
	}
	else
	{
		//不为空插入队尾，将队尾指针重置
		pq->_tail->_next = newNode;
		pq->_tail = newNode;
	}
}

//队头出队
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_head);
	//释放队头使其指向下一个结点
	QueueNode* next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;
	//判断只剩一个元素的时候
	if (pq->_head == NULL)
	{
		pq->_tail = NULL;
	}
}

//取队头元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_head);

	return pq->_head->_data;
}

//取队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_tail);

	return pq->_tail->_data;
}

//返回1是空  返回0是非空
int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->_head == NULL ? 1 : 0;
}

//获取数据个数
int QueueSize(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->_head;
	int size = 0;//计数
	while (cur)
	{
		++size;
		cur = cur->_next;
	}

	return size;
}