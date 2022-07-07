#pragma once
#include"data_type.h"

//桶排序和基数排序
/*
* 桶排序要求已知待排序元素的取值范围，比如取值范围在0~M-1,那么就需要M个桶。
* 桶的实现是链表的结点，便于分配和收集这两个操作。
* 基数排序是多关键值得桶排序，比如一个三位整数，百位、十位、个位就是三个基数，需要进行三趟桶排序。
  三趟排序可以重复利用桶，所以空间代价还是O(M).
* 一般地，如果有d个关键字，那么就要进行d趟桶排序，分为主位优先MSD；次位优先LSD。
* 用整理扑克牌做例子，主位是花色，次位是面值，那么LSD效率比MSD要高一点，因为LSD基于分配收集策略，MSD基于分治策略，分别排序再合并结果
* 如果有N个关键字，那么一趟排序就需要N个分配和M个收集，总的时间代价就是O(d*(N+M));
* 基数分解问题：
  如果我们按取值范围来分配桶，那么可能带来巨大的空间浪费，比如对20个不超过三位的整数进行排序，我们需要1000个桶
  如果我们以10为基数把三位整数分解，那么取值范围变成了0~9，只需要分配10个桶，相应的我们需要三趟排序。
  一般地，以R为基数分解，就只需要R个桶。
*
*/

//实现三位整数的基数排序
#define MAX_digit 4//每个元素最多的关键字数
#define Radix 10

//这是一个bucket
typedef struct Node* ptr_to_Node;
struct Node {
	int key;
	ptr_to_Node next;
};

//bucket头结点
struct head_node {
	ptr_to_Node head;
	ptr_to_Node tail;
};

typedef struct head_node bucket[Radix];

//约定次位D=1，主位D<=MAX_digit
int get_digit(int e, int D)
{
	int i, d;
	for (i = 1; i <= D; i++) {
		d = e % Radix;
		e = e / Radix;
	}
	return d;
}

void LSD_radix_sort(int arr[], int n)
{
	int D, Di, i;
	bucket B;
	ptr_to_Node temp, p, List = NULL;

	for (i = 0; i < Radix; i++)//初始化每个桶为空链表
		B[i].head = B[i].tail = NULL;

	for (i = 0; i < n; i++) {//把arr[]逆序存入List
		temp = (ptr_to_Node)malloc(sizeof(struct Node));
		temp->key = arr[i];
		temp->next = List;
		List = temp;
	}

	//从这里开始排序
	for (D = 1; D <= MAX_digit; D++) {
		//分配过程
		p = List;
		while (p) {
			Di = get_digit(p->key, D);
			temp = p;//从List中摘除
			p = p->next;
			temp->next = NULL;
			if (B[Di].head == NULL)
				B[Di].head = B[Di].tail = temp;
			else {
				B[Di].tail->next = temp;
				B[Di].tail = temp;
			}
		}

		//收集过程
		List = NULL;
		for (Di = Radix - 1; Di >= 0; Di--) {
			if (B[Di].head) {
				B[Di].tail->next = List;
				List = B[Di].head;
				B[Di].head = B[Di].tail = NULL;//清空桶
			}
		}
	}

	for (i = 0; i < n; i++) {//把List放回arr[]并释放空间
		temp = List;
		List = List->next;
		arr[i] = temp->key;
		free(temp);
	}
}
