#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "BTree.h"
//��ʽ�ṹ
typedef BTNode* QDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;

}QueueNode;
//���еĽṹ
typedef struct Queue
{
	QueueNode* _head;//��ͷָ��
	QueueNode* _tail;//��βָ��
}Queue;


void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//����1�ǿ�  ����0�Ƿǿ�
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

