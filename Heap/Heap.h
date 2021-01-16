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

//初始化
void HeapInit(Heap* php, HPDataType* _a, int n);
//销毁
void HeapDestory(Heap* php);
//尾插
void HeapPush(Heap* php, HPDataType x);
//头删
void HeapPop(Heap* php);
//取栈顶元素
HPDataType HeapTop(Heap* php);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k);
void TestTopk();
