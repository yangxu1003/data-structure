#include "Heap.h"

void Swap(HPDataType* p, HPDataType* q)
{
	HPDataType temp = *p;
	*p = *q;
	*q = temp;
}

//ǰ�᣺������������С��
void AdjustDown(HPDataType* a, int n, int root)
{
	//�ҳ����Һ��ӳ�С��һ��
	int parent = root;
	int child = parent * 2 + 1;//����

	while (child < n)
	{
		//�ҳ����Һ�����С��һ��
		if ((child + 1 < n) && a[child + 1] < a[child])
		{
			child = child + 1;
		}

		//�������С�ڸ��׾ͽ���
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;//�����µ�
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}



//��ʼ��
void HeapInit(Heap* php, HPDataType* arr, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(php->_a, arr, sizeof(HPDataType) * n);
	php->_size = n;
	php->_capacity = n;

	//������
	//i�Ǵ����һ����Ҷ�ӽ���������ʼ��
	for (int i = (n-1-1) / 2; i >= 0; i--)
	{
		AdjustDown(php->_a, n, i);//�µ�
	}
}

//����
void HeapDestory(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_size = php->_capacity = 0;
}

//���ϵ���
void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;//���׽��

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

//����
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	//����ռ䲻������
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* temp = (HPDataType*)realloc(php->_a, sizeof(HPDataType) * php->_capacity);

		php->_a = temp;
	}

	php->_a[php->_size++] = x;//��ֵ��size+1

	AdjustUp(php->_a, php->_size, php->_size - 1);//����
}


//ɾͷ
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;

	AdjustDown(php->_a, php->_size, 0);
}

//ȡ�Ѷ���Ԫ��
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	return php->_a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* php)
{
	assert(php);
	return php->_size;
}

// �ѵ��п� 1Ϊ�գ�0Ϊ�ǿ�
int HeapEmpty(Heap* php)
{
	assert(php);
	return php->_size == 0 ? 1 : 0;
}

// ������ǰK��������K������С��
void PrintTopK(int* a, int n, int k)
{
	Heap hp;
	//��k������С��
	HeapInit(&hp, a, k);

	for (int i = k; i < n; i++)
	{
		//ÿ�κͶѶ�Ԫ�رȽϣ��ȶѶ����
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