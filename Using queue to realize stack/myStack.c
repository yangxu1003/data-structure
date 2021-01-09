typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;

}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//返回1是空  返回0是非空
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

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

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("内存不足\n");
		exit(-1);
	}

	newNode->_data = x;
	newNode->_next = NULL;

	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail = newNode;
	}
	else
	{
		pq->_tail->_next = newNode;
		pq->_tail = newNode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_head);

	QueueNode* next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;

	if (pq->_head == NULL)
	{
		pq->_tail = NULL;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_head);

	return pq->_head->_data;
}

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
int QueueSize(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->_head;
	int size = 0;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}

	return size;
}


typedef struct {
	Queue _q1;
	Queue _q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->_q1);
	QueueInit(&st->_q2);

	return st;
}


/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->_q1))
	{
		QueuePush(&obj->_q1, x);
	}
	else
	{
		QueuePush(&obj->_q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* empty = &obj->_q1;
	Queue* nonEmpty = &obj->_q2;
	//将非空的赋给nonEmpty
	if (QueueEmpty(&obj->_q2))
	{
		empty = &obj->_q2;
		nonEmpty = &obj->_q1;
	}
	//将非空的移到空的队列，使非空的队列只剩一个元素
	while (QueueSize(nonEmpty) > 1)
	{
		QueuePush(empty, QueueFront(nonEmpty));
		QueuePop(nonEmpty);
	}

	int val = QueueFront(nonEmpty);
	QueuePop(nonEmpty);
	return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->_q1))
	{
		return QueueBack(&obj->_q1);
	}
	else
	{
		return QueueBack(&obj->_q2);
	}

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(&obj->_q1) && QueueEmpty(&obj->_q2))
	{
		return true;
	}
	return false;
	// return QueueEmpty(&obj->_q1) && QueueEmpty(&obj->_q2);
}

void myStackFree(MyStack* obj) {
	QueueDestory(&obj->_q1);
	QueueDestory(&obj->_q2);

	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/