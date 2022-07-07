#pragma once
#include"data_type.h"

//冒泡排序
/*
* 冒泡排序的规则是：
	1.先考虑数组的N-1个位置，从第0个位置上的元素开始，看看是否其后相邻的元素更小，更小就上浮交换二者
	2.然后再看第1个位置上的元素和它后面的元素要不要交换。
	3.倒数第二个位置的元素和最后一个元素比较并发生可能的交换后一轮扫描结束，这时最大的元素固定到了第N-1个位置
	4.第二轮扫描从第0个位置到N-2个位置，每次扫描会排定一个最大元素，直到只有一个元素。
* 改进的思路是，有时序列已经有序，不再需要扫描，算法可以提前结束。
  用一个flag表示有没有发生过交换，如果一次交换都没有发生过，说明已经有序了，那就提前结束。
*/

void bubble_sort(elemtype arr[], int n)
{
	for (int pos = n - 1; pos >= 0; pos--) {
		for (int i = 0; i < pos; i++) {
			if (arr[i + 1] < arr[i])
				swap(&arr[i], &arr[i + 1]);
		}
	}
}

void bubble_sort1(elemtype arr[], int n)
{
	for (int pos = n - 1; pos >= 0; pos--) {
		bool falg = false;//用来标识有没有发生过交换
		for (int i = 0; i < pos; i++) {
			if (arr[i + 1] < arr[i]) {
				swap(&arr[i], &arr[i + 1]);
				falg = true;
			}
		}
		if (falg == false)
			break;
	}
}

//选择排序
/*
* 选择排序的规则是：
	1.找到数组中的最小元素，然后把他和数组的第一个位置上的元素交换；（如果他自己最小就和自己交换）
	2.然后再从剩下的数组中找到最小的元素，和数组的第二个位置上的元素交换；
	3.数组中所有元素都被选取了一次算法结束;
* 选择排序的操作次数是确定的：N(N-1)/2次比较，N次交换，这意味着两个特点：
	1.运行时间和输入的性质完全没有关系，逆序数少的差不多已经有序的序列并不会减少操作时间
	2.数据的移动是最少的，只发生N次交换。
*
*/

void selection_sort(elemtype arr[], int n)
{
	for (int pos = 0; pos < n; pos++) {
		int min = pos;
		for (int i = pos + 1; i < n; i++) {
			if (arr[i] < arr[min])
				min = i;
		}
		swap(&arr[min], &arr[pos]);
	}
}

//插入排序
/*
* 插入排序的规则是：
	*整理牌的时候我们把后面摸得牌插入到一个合适的位置。
	1.当前索引左边的部分是有序部分，但他们的最终位置还不确定，为了给插入的元素留出位置，可能需要移动他们的位置。
	2.当索引到达最右端的时候，排序就完成了。
* 插入排序在输入基本有序时会快很多，表现与输入有很大的关系。
* 插入排序在最好的情况下需要N-1次比较，0次交换；最坏情况要N^2/2次比较和N^2/2次交换；平均是N^2/4次比较和交换
* 插入排序比选择排序要快一点点。
*/

void insertion_sort(elemtype arr[], int n)//这种写法速度最快
{
	for (int pos = 1; pos < n; pos++) {
		if (arr[pos - 1] > arr[pos]) {//看看要不要移动元素
			elemtype temp = arr[pos];
			int i;
			for (i = pos; arr[i - 1] > temp; i--) //移动腾出位置
				arr[i] = arr[i - 1];
			arr[i] = temp;
		}
	}
}

void insertion_sort1(elemtype arr[], int n)
{
	for (int pos = 1; pos < n; pos++) {
		elemtype temp = arr[pos];
		int i;
		for (i = pos; i > 0 && arr[i - 1] > temp; i--) //把arr[pos],插入到arr[pos-1]~arr[0]之中
			arr[i] = arr[i - 1];
		arr[i] = temp;
	}
}
