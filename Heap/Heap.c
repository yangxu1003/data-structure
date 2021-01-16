#include "Heap.h"

void Swap(HPDataType* p, HPDataType* q)
{
	HPDataType temp = *p;
	*p = *q;
	*q = temp;
}

//前提：左右子树都是小堆
void AdjustDown(HPDataType* a, int n, int root)
{
	//找出左右孩子出小的一个
	int parent = root;
	int child = parent * 2 + 1;//左孩子

	while (child < n)
	{
		//找出左右孩子中小的一个
		if ((child + 1 < n) && a[child + 1] < a[child])
		{
			child = child + 1;
		}

		//如果孩子小于父亲就交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;//继续下调
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}



//初始化
void HeapInit(Heap* php, HPDataType* arr, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(php->_a, arr, sizeof(HPDataType) * n);
	php->_size = n;
	php->_capacity = n;

	//构建堆
	//i是从最后一个非叶子结点的索引开始的
	for (int i = (n-1-1) / 2; i >= 0; i--)
	{
		AdjustDown(php->_a, n, i);//下调
	}
}

//销毁
void HeapDestory(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_size = php->_capacity = 0;
}

//向上调整
void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;//父亲结点

	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//插入
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	//如果空间不够增容
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* temp = (HPDataType*)realloc(php->_a, sizeof(HPDataType) * php->_capacity);

		php->_a = temp;
	}

	php->_a[php->_size++] = x;//赋值，size+1

	AdjustUp(php->_a, php->_size, php->_size - 1);//传入
}


//删头
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;

	AdjustDown(php->_a, php->_size, 0);
}

//取堆顶的元素
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	return php->_a[0];
}

// 堆的数据个数
int HeapSize(Heap* php)
{
	assert(php);
	return php->_size;
}

// 堆的判空 1为空，0为非空
int HeapEmpty(Heap* php)
{
	assert(php);
	return php->_size == 0 ? 1 : 0;
}

// 找最大的前K个，建立K个数的小堆
void PrintTopK(int* a, int n, int k)
{
	Heap hp;
	//建k个数的小堆
	HeapInit(&hp, a, k);

	for (int i = k; i < n; i++)
	{
		//每次和堆顶元素比较，比堆顶大就
		if (a[i] > HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}

	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

}