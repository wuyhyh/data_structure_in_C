#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int elemtype;

typedef struct Lnode* ptr_to_Lnode;
struct Lnode {
	elemtype data;
	ptr_to_Lnode next;
};
typedef ptr_to_Lnode List;

List create_List()
{
	List L = (List)malloc(sizeof(struct Lnode));
	L->next = NULL;
	return L;
}

bool is_empty_List(List L)
{
	return L->next == NULL;//只有头结点
}

int length(List L)
{
	List ptr = L->next;
	int cnt = 0;

	while (ptr) {
		ptr = ptr->next;
		cnt++;
	}
	return cnt;
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

List find_kth(List L, int k)
{
	if (k<1 || k>length(L)) {
		printf("out of boundary\n");
		return NULL;
	}
	else {
		List ptr = L;
		int cnt = 0;
		while (ptr&&cnt<k) {
			ptr = ptr->next;
			cnt++;
		}
		if (ptr) {
			return ptr;
		}
		else {
			return NULL;//not find
		}
	}
}

bool insert_List(List L, int k, elemtype e)
{
	if (k<1 || k>length(L) + 1) {
		printf("out of boundary\n");
		return false;
	}
	else {
		int cnt = 0;
		List ptr = L;
		while (ptr && cnt < k-1) {
			ptr = ptr->next;
			cnt++;
		}
		List pre = ptr;
		List temp = (List)malloc(sizeof(struct Lnode));
		temp->data = e;
		temp->next = pre->next;
		pre->next = temp;
		return true;
	}
}

bool delete_List(List L, int k)
{
	if (is_empty_List(L)) {
		printf("List is empty\n");
		return false;
	}

	if (k<1 || k>length(L)) {
		printf("out of boundary\n");
		return false;
	}
	else {
		int cnt = 0;
		List ptr = L;
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

void print_List(List L)
{
	List ptr = L->next;
	while (ptr) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');
}


int main()
{
	List ss = create_List();
	if (is_empty_List(ss))
		printf("empty\n");
	printf("%d\n", length(ss));

	for(int i=0;i<10;i++)
		insert_List(ss, 1, rand()%123);
	print_List(ss);
	printf("%d\n", length(ss));

	insert_List(ss, -122, 223);
	insert_List(ss, 5, 1000);
	print_List(ss);

	delete_List(ss, 7);
	print_List(ss);

	List a = find(ss, 25);
	if (a)
		printf("%d\n", a->data);

	List b = find_kth(ss, 6);
	if (b)
		printf("%d\n", b->data);

	return 0;
}