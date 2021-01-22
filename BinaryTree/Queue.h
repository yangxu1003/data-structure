#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "BTree.h"
//链式结构
typedef BTNode* QDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;

}QueueNode;
//队列的结构
typedef struct Queue
{
	QueueNode* _head;//队头指针
	QueueNode* _tail;//队尾指针
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

