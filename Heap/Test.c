#include "Heap.h"

void HeapSort(int* a, int n)
{
	//1.�Ž���С��   2.�����򽨴��

	//1.����,iΪÿ��С�ѵ�root
	//ʱ�临�Ӷ�O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	//2.�Ѷ�Ԫ�غ����һ��Ԫ�ػ������ڶ�end-1��Ԫ���µ�
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//��β����������С�ķŵ����

		//�ټ���ѡ��С��
		AdjustDown(a, end, 0);
		--end;
	}
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	//�������10000�����������飬��֤Ԫ�ض�С��1000000
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	//ȷ��10��������
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