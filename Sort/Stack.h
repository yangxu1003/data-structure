#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; //栈顶下标
	int _capacity;//容量
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