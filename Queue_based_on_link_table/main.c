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

//使用一个带有头结点的链表作为队列的基础

typedef struct Qnode* ptr_to_Qnode;
struct Qnode {
	ptr_to_Lnode front;
	ptr_to_Lnode rear;
};
typedef ptr_to_Qnode Queue;

Queue create_Queue()
{
	Queue Q = (Queue)malloc(sizeof(struct Qnode));
	Q->rear = NULL;
	Q->front = NULL;
	return Q;
}

bool is_empty_Queue(Queue Q)
{
	return Q->front == NULL;
}

bool add_Queue(Queue Q,elemtype e)
{
	if (is_empty_Queue(Q)) {
		List temp = (List)malloc(sizeof(struct Lnode));
		temp->data = e;
		temp->next = NULL;
		Q->rear = temp;
		Q->front = temp;
		return true;
	}
	else {
		List temp = (List)malloc(sizeof(struct Lnode));
		temp->data = e;
		temp->next = NULL;
		Q->rear->next = temp;
		Q->rear = temp;
	}
}

elemtype delete_Queue(Queue Q)
{
	if (is_empty_Queue(Q)) {
		printf(("Queue is empty\n"));
		return INT_MAX;
	}
	else {
		if (Q->front == Q->rear) {//只有一个元素
			List temp = Q->front;
			elemtype value = temp->data;
			Q->front = NULL;
			Q->rear = NULL;
			free(temp);
			return value;
		}
		else {
			List temp = Q->front;
			elemtype value = temp->data;
			Q->front = Q->front->next;
			free(temp);
			return value;
		}
	}
}

int main()
{
	Queue ss = create_Queue();
	if (is_empty_Queue(ss))
		printf("empty\n");

	add_Queue(ss, 12);
	add_Queue(ss, 13);
	add_Queue(ss, 14);

	if (!is_empty_Queue(ss))
		printf("!empty\n");

	printf("%d ", delete_Queue(ss));
	printf("%d ", delete_Queue(ss));
	printf("%d ", delete_Queue(ss));
	if (is_empty_Queue(ss))
		printf("empty\n");
	printf("\n%d ", delete_Queue(ss));

	return 0;
}