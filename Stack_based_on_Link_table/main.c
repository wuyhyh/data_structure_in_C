#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int elemtype;

typedef struct Snode* ptr_to_Snode;
struct Snode {
	elemtype data;
	ptr_to_Snode next;
};
typedef ptr_to_Snode Stack;

//使用一个带有头结点的链表来表示栈
Stack create_Stack()
{
	Stack S = (Stack)malloc(sizeof(struct Snode));
	S->next = NULL;
}

bool is_empty_Stack(Stack S)
{
	return S->next == NULL;
}

bool push(Stack S, elemtype e)
{
	Stack temp = (Stack)malloc(sizeof(struct Snode));
	temp->data = e;

	Stack ptr = S;
	temp->next = ptr->next;
	ptr->next = temp;
	return true;
}

elemtype pop(Stack S)
{
	if (is_empty_Stack(S)) {
		printf("Stack is empty\n");
		return NULL;
	}
	else {
		Stack ptr = S;
		Stack temp = S->next;
		elemtype value = temp->data;
		ptr->next = temp->next;
		free(temp);
		return value;
	}
}

int main()
{
	Stack ss = create_Stack();
	if (is_empty_Stack(ss))
		printf("empty\n");

	push(ss, 122);
	push(ss, 4555);
	push(ss, 78);
	push(ss, 22222);

	for (int i = 0; i < 4; i++) {
		printf("%d ", pop(ss));
	}

	return 0;
}