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

// 插入排序 
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; ++i)
	{
		//单趟把end+1的数据插入到区间[0,end]
		int end = i;
		int tmp = a[end + 1];//保存要比较的数字
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

// 希尔排序 O(N^1.3~N^2)
void ShellSort(int* a, int n)
{
	assert(a);

	//1.gap>1相当于预排序  2.gap=1 相当于插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;// +1保证了最后一次是gap = 1

		//预排序
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

// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	int max, min;

	while (begin < end)
	{
		//[begin,end]区间里找到最大值和最小值的小标
		
		max = begin;
		min = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] < a[min])
			{
				min = i;//找最小的
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

// 堆排序
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
	//升序 建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end >= 0)
	{
		Swap(&a[0], &a[end]);//首尾互换
		AdjustDwon(a, end, 0);//调整选出次大的数
		--end;
	}
}

// 冒泡排序
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
		//没有发生交换，直接退出 
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

// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	//取中间数当key
	int midindex = getMidindex(a, left, right);
	Swap(&a[midindex], &a[right]);

	int keyindex = right;
	
	while (left < right)
	{
		//从左边先开始找比key大的
		while (a[left] <= a[keyindex] && left < right)
		{
			++left;
		}

		//从右边找比key小的
		while (a[right] >= a[keyindex] && left < right)
		{
			--right;
		}

		Swap(&a[left], &a[right]);
	}

	//与key交换
	Swap(&a[left], &a[keyindex]);

	return left;
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	//取中间数当key
	int midindex = getMidindex(a, left, right);
	Swap(&a[midindex], &a[right]);

	//坑(坑的意思时这的值被拿走了，可以覆盖填新的值）
	int key = a[right];

	while (left < right)
	{

		while (left < right && a[left] <= key)
		{
			++left;
		}
		//左边找到比key大的，填到右边的坑，此时左边left成为新的坑
		a[right] = a[left];

		while (left < right && a[right] >= key)
		{
			--right;
		}
		//右边找到比key小的，填到左边left的坑，此时右边right成为新的坑
		a[left] = a[right];
	}
	//将最开始的key值填入最后的坑
	a[left] = key;

	return left;
}


// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	//这个过程走完等于把大的都放后面了，小的都放前面了
	int keyindex = right;

	int cur = left;
	int prev = cur - 1;

	while (cur < right)
	{
		//cur找到比key小的就停下来，++prev,然后交换cur和prev
		if (a[cur] < a[keyindex] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}

		++cur;

	}

	Swap(&a[++prev], &a[keyindex]);

	return prev;

}

// 快速排序递归实现 时间复杂的O(N*logN) 空间复杂度(logN)
void QuickSort(int* a, int left, int right)
{
	//当只剩一个元素时，退出
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
		//小于10个数用插入排序
		InsertSort(a , right - left + 1);
		return;
	}
		
}


// 快速排序 非递归实现
//非递归稳定，不会存在栈溢出，数据存储在堆上的
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

		//[begin,end]区间
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
	//出口
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	//1、递归分解为[left,mid],[mid+1,right]
	
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//2、归并有序
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

// 归并排序递归实现
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

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);

	//相邻gap距离的元素合并
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//分组[i,i+gap-1],[i+gap,i+2gap+1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//合并时只有第一组，不需要合并
			if (begin2 >= n)
			{
				break;
			}
			//合并时第二组只有部分元素合并
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			//合并
			MergeArr(a, begin1, end1, begin2, end2, tmp);
		}

		PrintArray(a, n);
		gap *= 2;
	}
	free(tmp);
}

// 计数排序
void CountSort(int* a, int n)
{
	//找出最大数和最小数
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
	//length代表开的空间大小
	int length = max - min + 1;
	//计数数组
	int* countArr = (int*)malloc(sizeof(int) * length);
	memset(countArr, 0, sizeof(int) * length);//初始化

	//统计次数
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