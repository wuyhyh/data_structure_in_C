#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int elemtype;

typedef struct Lnode* ptr_to_Lnode;
struct Lnode {
	elemtype data;
	ptr_to_Lnode next;
};
typedef ptr_to_Lnode List;

//List L = NULL;这就是创建空表

bool is_empty_List(List L)
{
	return L == NULL;
}

int length(List L)
{
	int cnt = 0;
	List ptr = L;
	while (ptr) {
		ptr = ptr->next;
		cnt++;
	}
	return  cnt;
}

List find(List L, elemtype e)
{
	List ptr = L;
	while (ptr) {
		if (ptr->data == e)
			return ptr;
		ptr = ptr->next;
	}
	return NULL;//not find
}

List find_kth(List L,int k)
{
	if (k < 1||k>length(L)) {
		printf("out of boundary\n");
		return NULL;
	}
	else {
		List ptr = L;
		int cnt = 1;
		while (ptr && cnt < k) {
			ptr = ptr->next;
			cnt++;
		}//退出要么找到了要么到了末尾
		if (ptr) {
			return ptr;
		}
		else {
			return NULL;//not find
		}
	}
}

List insert_List(List L, int k, elemtype e)
{
	if (k < 1||k>length(L)+1) {
		printf("out of boundary\n");
		return L;
	}
	else {
		if (k == 1) {
			List temp = (List)malloc(sizeof(struct Lnode));
			temp->data = e;
			temp->next = L;
			L = temp;
			return L;
		}
		else {
			List ptr = L;
			int cnt = 1;
			while (ptr && cnt < k - 1){
				ptr = ptr->next;
				cnt++;
			}
			List pre = ptr;
			List temp = (List)malloc(sizeof(struct Lnode));
			temp->data = e;
			temp->next = pre->next;
			pre->next = temp;
			return L;
		}
	}
}

bool delete_List(List L, int k)
{
	if (is_empty_List(L)) {
		printf("List is empty\n");
		return false;
	}

	if (k < 1 || k>length(L)) {
		printf("out of boundary\n");
		return false;
	}
	else {
		if (k == 1) {
			List ptr = L;
			L = L->next;
			free(ptr);
			return true;
		}
		else {
			List ptr = L;
			int cnt = 1;
			while (ptr && cnt < k - 1) {
				ptr = ptr->next;
				cnt++;
			}
			List pre = ptr;
			List temp = pre->next;
			pre->next = temp->next;
			free(temp);
			return true;
		}
	}
}

void print_List(List L)
{
	List ptr = L;
	while (ptr) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');
}

int main()
{
	List ss = NULL;
	if (is_empty_List(ss))
		printf("empty\n");

	ss = insert_List(ss, 1, 100);
	print_List(ss);

	for (int i = 1; i <= 9; i++) {
		ss = insert_List(ss, 1, rand()%50);
	}
	print_List(ss);
	printf("%d\n", length(ss));

	ss = insert_List(ss, 4, 300);
	print_List(ss);

	delete_List(ss, 5);
	print_List(ss);

	List a = find(ss, 34);
	if (a)
		printf("%d\n", a->data);

	List a1 = find_kth(ss, 5);
	if (a1)
		printf("%d\n", a1->data);

	return 0;
}