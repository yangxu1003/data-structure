#include "Heap.h"

void HeapSort(int* a, int n)
{
	//1.排降序建小堆   2.排升序建大堆

	//1.建堆,i为每个小堆的root
	//时间复杂度O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	//2.堆顶元素和最后一个元素互换，在对end-1个元素下调
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//首尾互换，把最小的放到最后

		//再继续选次小的
		AdjustDown(a, end, 0);
		--end;
	}
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	//随机生成10000个数存入数组，保证元素都小于1000000
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	//确定10个最大的数
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;

	PrintTopK(a, n, 10);
}

int main()
{
	TestTopk();

	/*int arr[] = { 27,15,19,18,28,34,65,49,25,27 };
	Heap hp;
	HeapInit(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	HeapPush(&hp, 13);

	printf("%d\n", HeapEmpty(&hp));*/

	/*HeapDestory(&hp);*/
	return 0;
}