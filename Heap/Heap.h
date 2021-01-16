#pragma once
					
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

typedef int HPDataType;
typedef struct Heap
{ 
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void AdjustUp(HPDataType* a, int n, int child);
void AdjustDown(HPDataType* a, int n, int root);
void Swap(HPDataType* p, HPDataType* q);

//��ʼ��
void HeapInit(Heap* php, HPDataType* _a, int n);
//����
void HeapDestory(Heap* php);
//β��
void HeapPush(Heap* php, HPDataType x);
//ͷɾ
void HeapPop(Heap* php);
//ȡջ��Ԫ��
HPDataType HeapTop(Heap* php);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);
void TestTopk();
