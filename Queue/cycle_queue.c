#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;

int initQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
}

int isEmpty(Queue *Q)
{
	if (Q->front==Q->rear)
	{
		printf("Empty\n");
		return 1;
	} else {
		printf("Not Empty\n");
		return 0;
	}
}

int enQueue(Queue *Q, ElemType e)
{
	if ((Q->rear+1)%MAXSIZE==Q->front)
	{
		printf("Is Full\n");
		return 0;
	} else {
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear+1)%MAXSIZE;
		return 1;
	}
}

int deQueue(Queue *Q, ElemType *e)
{
	if (Q->rear==Q->front)
	{
		printf("Is Empty\n");
		return 0;
	} else {
		*e = Q->data[Q->front];
		Q->front = (Q->front+1)%MAXSIZE;
		return 1;
	}
}

int main(int argc, char const *argv[])
{
	Queue Q;
	initQueue(&Q);
	enQueue(&Q, 11);
	enQueue(&Q, 22);
	enQueue(&Q, 33);
	enQueue(&Q, 44);
	//enQueue(&Q, 55);
	ElemType e;
	deQueue(&Q, &e);
	deQueue(&Q, &e);
	//printf("De elem is:%d\n", e);
	deQueue(&Q, &e);
	deQueue(&Q, &e);
	deQueue(&Q, &e);
	return 0;
}