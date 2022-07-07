#pragma once
#include"data_type.h"

//归并排序
/*
* 归并操作把两个数组合成一个数组。
* 归并排序总能保证对一个数组排序所需时间为O(NlogN),缺点是需要一个O(N)的辅助空间
*
* 最简单的想法是创建一个适当大小的数组，然后把两个输入数组的元素一个个从小到大放入这个大数组中。
* 这样做主要的问题是我们对一个大数组进行排序时，需要很多次归并，每一次归并都需要一个辅助数组，这是很大的代价。
*
* 能不能原地归并呢？
* 我们使用一个辅助数组auxiliary，输入的形式是：arr[left,right],middle = left + (right - left)/2,
  我们把[left,middle]和[middle+1,right]归并到辅助数组aux中,然后再复制回原数组arr.
*
*/

//原地归并的抽象方法，注意，并不能直接用于归并排序，辅助数组aux[]应放到最外面。
void merge(int arr[], int aux[], int left, int right)
{
	int middle = left + (right - left) / 2;
	int i = left;
	int j = middle + 1;

	//把arr[]复制到aux[]中
	for (int k = left; k <= right; k++)
		aux[k] = arr[k];

	//把aux[]的左右两部分归并回arr[]
	for (int k = left; k <= right; k++) {
		if (i > middle)//左半边消耗完了
			arr[k] = aux[j++];
		else if (j > right)//右半边消耗完了
			arr[k] = aux[i++];
		else if (aux[j] < aux[i])//选择小的放入
			arr[k] = aux[j++];
		else
			arr[k] = aux[i++];
	}
}

//归并排序
//自顶向下的归并排序
void m_sort(int arr[], int aux[], int lo, int hi)
{
	if (lo >= hi)//结束条件
		return;

	int mid = lo + (hi - lo) / 2;
	m_sort(arr, aux, lo, mid);
	m_sort(arr, aux, mid + 1, hi);
	merge(arr, aux, lo, hi);
}

void merge_sort(int arr[], int n)
{
	int* aux = (int*)malloc(n * sizeof(int));
	m_sort(arr, aux, 0, n - 1);
	free(aux);
}

//自底向上的归并排序
int min_one(int a, int b)
{
	return (a < b) ? a : b;
}

//代码量很小
void merge_sort_BU(int arr[], int n)
{
	int* aux = (int*)malloc(n * sizeof(int));//归并的小数组规模翻倍
	for (int size = 1; size < n; size = size + size) {
		for (int lo = 0; lo < n - size; lo += (size + size)) //妙啊
			merge(arr, aux, lo, min_one(lo + size + size - 1, n - 1));
	}
	free(aux);
}
