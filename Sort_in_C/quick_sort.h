#pragma once
#include"data_type.h"
#include"primary_sort.h"

//快速排序
//K&R中的写法，使用快慢指针
void q_sort(int arr[], int left, int right)
{
	if (left >= right)//递归截止条件
		return;

	int i;
	int last;
	int pivot = left + (right - left) / 2;

	swap(&arr[pivot], &arr[left]);//以最左边的元素作为切分点
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (arr[i] < arr[left]) {//last是慢指针，i是快指针
			last++;//如果i处的元素大于切分元素，i就快速突进
			swap(&arr[i], &arr[last]);//如果i处的元素小于切分元素，那么就可以通知last移动腾出一个交换位置
		}
	}

	//排定切分元素
	swap(&arr[left], &arr[last]);//last标记了切分元素的最终位置，其左侧元素都小于切分元素
	q_sort(arr, left, last - 1);
	q_sort(arr, last + 1, right);
}

void quick_sort(int arr[], int n)
{
	q_sort(arr, 0, n - 1);
}

//快速排序的性能与pivot的选取有关
//选取最左、中间、最右三个元素的中位数作为pivot
int median3(int arr[], int left, int right)
{
	//调整使: arr[left] < arr[center] < arr[right]
	int center = left + (right - left) / 2;
	if (arr[left] > arr[center])
		swap(&arr[left], &arr[center]);
	if (arr[left] > arr[right])
		swap(&arr[left], &arr[right]);
	if (arr[center] > arr[right])
		swap(&arr[center], &arr[right]);

	swap(&arr[right - 1], &arr[center]);//把pivot放到倒数第二个位置
	int pivot = arr[center];
	return pivot;
}

//在数组规模较小时，改为插入排序，陈越写法
void q_sort1(int arr[], int left, int right)
{
	int pivot;
	int cutoff = 50;
	int lo, hi;

	if (cutoff <= (right - left + 1)) {
		pivot = median3(arr, left, right);//这一步结束把pivot放到了倒数第二个位置，并且倒数第一个位置上的元素也大于pivot
		lo = left;
		hi = right - 1;
		while (true) {
			while (arr[++lo] < pivot);
			while (arr[--hi] > pivot);

			if (lo < hi)
				swap(&arr[lo], &arr[hi]);
			else
				break;
		}

		//排定pivot的位置
		swap(&arr[lo], &arr[right - 1]);//pivot放在arr[right-1],lo时pivot的最终位置
		q_sort1(arr, left, lo - 1);
		q_sort1(arr, lo + 1, right);
	}
	else
		insertion_sort(arr + left, right - left + 1);//这里arr + left是递归的需要
}

//sedgewick写法，只进行快速排序
void q_sort2(int arr[], int left, int right)
{
	if (left >= right)//递归截止条件
		return;

	int pivot = median3(arr, left, right);//这一步结束把pivot放到了倒数第二个位置，并且倒数第一个位置上的元素也大于pivot
	int lo = left;
	int hi = right - 1;
	while (true) {
		while (arr[++lo] < pivot);
		while (arr[--hi] > pivot);

		if (lo < hi)
			swap(&arr[lo], &arr[hi]);
		else
			break;
	}

	//排定pivot的位置
	swap(&arr[lo], &arr[right - 1]);//pivot放在arr[right-1],lo时pivot的最终位置
	q_sort2(arr, left, lo - 1);
	q_sort2(arr, lo + 1, right);
}

void q_sort3(int arr[], int left, int right)
{
	int cutoff = 100;
	if (left + cutoff >= right) {//子数组规模较小时改为插入排序
		insertion_sort(arr + left, right - left + 1);
		return;//递归截止条件
	}

	int pivot = median3(arr, left, right);//这一步结束把pivot放到了倒数第二个位置，并且倒数第一个位置上的元素也大于pivot
	int lo = left;
	int hi = right - 1;
	while (true) {
		while (arr[++lo] < pivot);
		while (arr[--hi] > pivot);

		if (lo < hi)
			swap(&arr[lo], &arr[hi]);
		else
			break;
	}

	//排定pivot的位置
	swap(&arr[lo], &arr[right - 1]);//pivot放在arr[right-1],lo时pivot的最终位置
	q_sort3(arr, left, lo - 1);
	q_sort3(arr, lo + 1, right);
}

//三向切分快速排序，处理重复元素较多的情况。
/*
* 数组中重复元素较多时，快速排序有希望改进到线性
*/

void q_sort_3way(int arr[], int left, int right)
{
	//printf("Say my name. Heisenberg\n");
	if (right <= left)
		return;

	int less_than = left;
	int greater_than = right;
	int equal = left + 1;

	int standard = arr[left];

	while (equal <= greater_than) {
		if (arr[equal] < standard)
			swap(&arr[equal++], &arr[less_than++]);
		else if (arr[equal] > standard)
			swap(&arr[equal], &arr[greater_than--]);
		else
			equal++;
	}

	q_sort_3way(arr, left, less_than - 1);
	q_sort_3way(arr, greater_than + 1, right);
}
