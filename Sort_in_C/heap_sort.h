#pragma once
#include"data_type.h"

//堆排序
/*
* 堆排序是在选择排序上的改进。
* 我们把输入的数组进行建堆，然后逐渐删除最小堆，收集删除的元素得到排序的结果。
* 这种想法的问题是，我们需要一个额外的数组来收集删除的元素再复制回原数组。
* 改进的方法是使用最大堆，删除最大堆以后把删除的元素放到数组的最后一位，只需要一个临时变量暂存一下删除的堆顶元素
*
* 建堆需要O(N),N次删除操作O(NlogN).
*
*/

void sink(int arr[], int n, int k)
{
	while (2 * k + 1 <= n) {
		int i = 2 * k + 1;
		if (i < n && (arr[i] < arr[i + 1]))
			i++;//i指向较大的那个子结点

		if (arr[i] < arr[k])
			break;
		else
			swap(&arr[i], &arr[k]);
		k = i;
	}
}

void heap_sort(int arr[], int n)
{
	int size = n - 1;
	for (int k = size / 2 - 1; k >= 0; k--)
		sink(arr, size, k);

	while (size > 0) {
		swap(&arr[0], &arr[size]);
		size--;
		sink(arr, size, 0);
	}
}
