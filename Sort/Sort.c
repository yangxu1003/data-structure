#include "Sort.h"
#include "Stack.h"
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}

// �������� 
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; ++i)
	{
		//���˰�end+1�����ݲ��뵽����[0,end]
		int end = i;
		int tmp = a[end + 1];//����Ҫ�Ƚϵ�����
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}

}

// ϣ������ O(N^1.3~N^2)
void ShellSort(int* a, int n)
{
	assert(a);

	//1.gap>1�൱��Ԥ����  2.gap=1 �൱�ڲ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;// +1��֤�����һ����gap = 1

		//Ԥ����
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];

			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}

}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// ѡ������
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	int max, min;

	while (begin < end)
	{
		//[begin,end]�������ҵ����ֵ����Сֵ��С��
		
		max = begin;
		min = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] < a[min])
			{
				min = i;//����С��
			}
			if (a[max] < a[i])
			{
				max = i;
			}
		}

		Swap(&a[begin], &a[min]);
		if (max == begin)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);

		++begin;
		--end;
	}
}

// ������
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	//���� �����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end >= 0)
	{
		Swap(&a[0], &a[end]);//��β����
		AdjustDwon(a, end, 0);//����ѡ���δ����
		--end;
	}
}

// ð������
void BubbleSort(int* a, int n)
{
	int end = n;

	while (end > 1)
	{
		int flag = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i] < a[i - 1])
			{
				Swap(&a[i], &a[i - 1]);
				flag = 1;
			}
		}
		//û�з���������ֱ���˳� 
		if (flag == 0)
		{
			break;
		}

		--end;
	}
	
}

int getMidindex(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right]) // left < mid < right
		{
			return mid;
		}
		else if(a[left] > a[right]) //  right < left < mid
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right]) // right < mid < left
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else 
		{
			return right;
		}
	}

}

// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
	//ȡ�м�����key
	int midindex = getMidindex(a, left, right);
	Swap(&a[midindex], &a[right]);

	int keyindex = right;
	
	while (left < right)
	{
		//������ȿ�ʼ�ұ�key���
		while (a[left] <= a[keyindex] && left < right)
		{
			++left;
		}

		//���ұ��ұ�keyС��
		while (a[right] >= a[keyindex] && left < right)
		{
			--right;
		}

		Swap(&a[left], &a[right]);
	}

	//��key����
	Swap(&a[left], &a[keyindex]);

	return left;
}

// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	//ȡ�м�����key
	int midindex = getMidindex(a, left, right);
	Swap(&a[midindex], &a[right]);

	//��(�ӵ���˼ʱ���ֵ�������ˣ����Ը������µ�ֵ��
	int key = a[right];

	while (left < right)
	{

		while (left < right && a[left] <= key)
		{
			++left;
		}
		//����ҵ���key��ģ���ұߵĿӣ���ʱ���left��Ϊ�µĿ�
		a[right] = a[left];

		while (left < right && a[right] >= key)
		{
			--right;
		}
		//�ұ��ҵ���keyС�ģ�����left�Ŀӣ���ʱ�ұ�right��Ϊ�µĿ�
		a[left] = a[right];
	}
	//���ʼ��keyֵ�������Ŀ�
	a[left] = key;

	return left;
}


// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	//�������������ڰѴ�Ķ��ź����ˣ�С�Ķ���ǰ����
	int keyindex = right;

	int cur = left;
	int prev = cur - 1;

	while (cur < right)
	{
		//cur�ҵ���keyС�ľ�ͣ������++prev,Ȼ�󽻻�cur��prev
		if (a[cur] < a[keyindex] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}

		++cur;

	}

	Swap(&a[++prev], &a[keyindex]);

	return prev;

}

// ��������ݹ�ʵ�� ʱ�临�ӵ�O(N*logN) �ռ临�Ӷ�(logN)
void QuickSort(int* a, int left, int right)
{
	//��ֻʣһ��Ԫ��ʱ���˳�
	if (left >= right)
	{
		return;
	}

	if ((left - right + 1) > 10)
	{
		int div = PartSort3(a, left, right);

		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		//С��10�����ò�������
		InsertSort(a , right - left + 1);
		return;
	}
		
}


// �������� �ǵݹ�ʵ��
//�ǵݹ��ȶ����������ջ��������ݴ洢�ڶ��ϵ�
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		//[begin,end]����
		int div = PartSort3(a, begin, end);
		//[begin,div-1] div [div+1,end]

		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}

		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
	}

	StackDestory(&st);
}


void _MergeSort(int* a, int left, int right, int* tmp)
{
	//����
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	//1���ݹ�ֽ�Ϊ[left,mid],[mid+1,right]
	
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//2���鲢����
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = begin1;
	
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
			
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}

}

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

void MergeArr(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int left = begin1 , right = end2;
	int index = begin1;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];

		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}

// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);

	//����gap�����Ԫ�غϲ�
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//����[i,i+gap-1],[i+gap,i+2gap+1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//�ϲ�ʱֻ�е�һ�飬����Ҫ�ϲ�
			if (begin2 >= n)
			{
				break;
			}
			//�ϲ�ʱ�ڶ���ֻ�в���Ԫ�غϲ�
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			//�ϲ�
			MergeArr(a, begin1, end1, begin2, end2, tmp);
		}

		PrintArray(a, n);
		gap *= 2;
	}
	free(tmp);
}

// ��������
void CountSort(int* a, int n)
{
	//�ҳ����������С��
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	//length�����Ŀռ��С
	int length = max - min + 1;
	//��������
	int* countArr = (int*)malloc(sizeof(int) * length);
	memset(countArr, 0, sizeof(int) * length);//��ʼ��

	//ͳ�ƴ���
	for (int i = 0; i < n; ++i)
	{
		countArr[a[i] - min] ++;
	}

	int index = 0;
	for (int i = 0; i < length; ++i)
	{
		while (countArr[i]--)
		{
			a[index++] = i + min;
		}
	}
}