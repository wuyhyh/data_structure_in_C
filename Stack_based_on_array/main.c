#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int elemtype;

typedef struct Snode* ptr_to_Stack;
struct Snode {
	elemtype* data;
	int maxsize;
	int top;
};
typedef ptr_to_Stack Stack;

Stack create_Stack(int maxsize)
{
	Stack S = (Stack)malloc(sizeof(struct Snode));
	S->data = (elemtype*)malloc(maxsize * sizeof(elemtype));
	S->maxsize = maxsize;
	S->top = -1;//约定栈顶指针放在小地址
	return S;
}

bool is_empty_Stack(Stack S)
{
	return S->top == -1;
}

bool is_full_Stack(Stack S)
{
	return S->top == (S->maxsize - 1);
}

bool push(Stack S, elemtype e)
{
	if (is_full_Stack(S)) {
		printf("Stack is full\n");
		return false;
	}
	else {
		S->data[++S->top] = e;
		return true;
	}
}

elemtype pop(Stack S)
{
	if (is_empty_Stack(S) ){
		printf("Stack is empty\n");
		return INT_MAX;
	}
	else {
		return S->data[S->top--];
	}
}

int main()
{
	Stack ss = create_Stack(100);
	if (is_empty_Stack(ss))
		printf("empty\n");

	push(ss, 120);
	push(ss, 2000);
	push(ss, 23);

	for(int i=0;i<3;i++)
		printf("%d ", pop(ss));

	return 0;
}