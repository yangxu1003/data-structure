/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
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

	int div = PartSort3(a, left, right);

	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);

}

int* sortArray(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
	QuickSort(nums, 0, numsSize - 1);

	return nums;
}