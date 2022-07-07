#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int elemtype;

typedef struct Qnode* ptr_to_Qnode;
struct Qnode {
	elemtype* data;
	int maxsize;
	int front;
	int rear;
};
typedef ptr_to_Qnode Queue;

Queue create_Queue(int maxsize)
{
	Queue Q = (Queue)malloc(sizeof(struct Qnode));
	Q->data = (elemtype*)malloc(maxsize * sizeof(elemtype));
	Q->maxsize = maxsize;
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

bool is_empty_Queue(Queue Q)
{
	return Q->front == Q->rear;
}

bool is_full_Queue(Queue Q)//留一个空位表示满
{
	return (Q->rear + 1) % Q->maxsize == (Q->front);
}

bool add_Queue(Queue Q, elemtype e)
{
	if (is_full_Queue(Q)) {
		printf("Queue is full\n");
		return false;
	}
	else {
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % Q->maxsize;
		return true;
	}
}

elemtype delete_Queue(Queue Q)
{
	if (is_empty_Queue(Q)) {
		printf("Queue is empty\n");
		return INT_MAX;
	}
	else {
		elemtype value = Q->data[Q->front];
		Q->front = (Q->front+1) % Q->maxsize;
		return value;
	}
}

int main()
{
	Queue ss = create_Queue(5);
	if (is_empty_Queue(ss))
		printf("empty\n");
	
	add_Queue(ss, 12);
	add_Queue(ss, 14);
	add_Queue(ss, 16);
	add_Queue(ss, 18);
	if (is_full_Queue(ss))
		printf("full\n");

	for (int i = 0; i < 4; i++) {
		printf("%d ", delete_Queue(ss));
	}

	add_Queue(ss, 20);
	add_Queue(ss, 22);

	printf("\n%d ", delete_Queue(ss));
	printf("%d ", delete_Queue(ss));
	
	return 0;
}