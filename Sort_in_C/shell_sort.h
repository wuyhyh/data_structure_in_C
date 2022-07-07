#pragma once
#include"data_type.h"

//希尔排序
/*
* 我们知道排序的本质是消除所有的逆序对，插入排序只涉及交换相邻的元素，这样一次只可能减少1个逆序对；
* 如果交换不相邻的元素，就可能减少不止1个逆序对，排序将更快。
* 希尔排序是对插入排序的改进，将数组分成多个固定间隔的子序列，分别插入排序，然后再逐渐减少间隔。
* 确定间隔的方法有很多中，不同的增量序列可能带来很大的不同：
*/

//增量序列：d = 1/2*(3^k-1)
void shell_sort(elemtype arr[], int n)
{
	int h = 1;
	while (h < n / 3)
		h = 3 * h + 1;

	while (h >= 1) {
		//插入排序
		for (int pos = h; pos < n; pos++) {
			elemtype temp = arr[pos];
			int i;
			for (i = pos; i >= h && arr[i - h] > temp; i -= h) //把arr[pos],插入到arr[pos-1]~arr[0]之中
				arr[i] = arr[i - h];
			arr[i] = temp;
		}

		h = h / 3;
	}
}

void shell_sort1(elemtype arr[], int n)
{
	int sedgewick[] = { 929,505,209,109,41,19,5,1 };
	int si;
	for (si = 0; sedgewick[si] >= n; si++)//确保初始增量不大于数组长度
		;

	for (int h = sedgewick[si]; h >= 1; h = sedgewick[++si]) {
		//插入排序
		for (int pos = h; pos < n; pos++) {
			elemtype temp = arr[pos];
			int i;
			for (i = pos; i >= h && arr[i - h] > temp; i -= h) //把arr[pos],插入到arr[pos-1]~arr[0]之中
				arr[i] = arr[i - h];
			arr[i] = temp;
		}
	}
}

void shell_sort2(elemtype arr[], int n)//比插入排序还慢
{
	int seq[10] = { 0 };
	int h = 1;
	for (int i = 0, j = 1; i < 10; i++, j *= 2)
		seq[i] = j;

	int si;
	for (si = 0; seq[si] >= n; si++)//确保初始增量不大于数组长度
		;

	for (int h = seq[si]; h >= 1; h = seq[++si]) {
		//插入排序
		for (int pos = h; pos < n; pos++) {
			elemtype temp = arr[pos];
			int i;
			for (i = pos; i >= h && arr[i - h] > temp; i -= h) //把arr[pos],插入到arr[pos-1]~arr[0]之中
				arr[i] = arr[i - h];
			arr[i] = temp;
		}
	}
}
