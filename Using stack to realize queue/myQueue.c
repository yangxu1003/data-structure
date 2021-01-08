typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top; //栈顶下标
	int _capacity;
}Stack;

//初始化
void StackInit(Stack* pst);
//销毁
void StackDestory(Stack* pst);
//入栈
void StackPush(Stack* pst, STDataType x);
//出栈
void StackPop(Stack* pst);
//获取数据个数
int StackSize(Stack* pst);

//返回1是空  返回0是非空
int StackEmpty(Stack* pst);

//获取栈顶的数据
STDataType StackTop(Stack* pst);

//初始化
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = malloc(sizeof(STDataType) * 4);
	pst->_top = 0;
	pst->_capacity = 4;
}

//销毁
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}

//入栈
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	//空间不够增容
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDataType* temp = realloc(pst->_a, sizeof(STDataType) * pst->_capacity);
		if (temp == NULL)
		{
			printf("内存不足\n");
			exit(-1);
		}
		else
		{
			pst->_a = temp;
		}
	}

	pst->_a[pst->_top] = x;
	pst->_top++;
}

//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);

	--pst->_top;
}

//获取数据个数
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}

//返回1是空  返回0是非空
int StackEmpty(Stack* pst)
{
	assert(pst);

	//return pst->_top == 0 ? 1 : 0;
	return !pst->_top;
}

//获取栈顶的数据
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);

	return pst->_a[pst->_top - 1];
}

typedef struct {
	Stack _pushSt;
	Stack _popSt;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->_pushSt);
	StackInit(&q->_popSt);

	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->_pushSt, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int val = myQueuePeek(obj);
	StackPop(&obj->_popSt);

	return val;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->_popSt))
	{
		while (!StackEmpty(&obj->_pushSt))
		{
			StackPush(&obj->_popSt, StackTop(&obj->_pushSt));
			StackPop(&obj->_pushSt);
		}
	}
	return StackTop(&obj->_popSt);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->_pushSt) && StackEmpty(&obj->_popSt);
}

void myQueueFree(MyQueue* obj) {
	StackDestory(&obj->_pushSt);
	StackDestory(&obj->_popSt);

	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/