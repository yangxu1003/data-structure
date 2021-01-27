/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
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

	int div = PartSort3(a, left, right);

	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);

}

int* sortArray(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
	QuickSort(nums, 0, numsSize - 1);

	return nums;
}