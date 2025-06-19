#include <stdio.h>

#define MAXSIZE 5
typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;

void initQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
}

int isEmpty(Queue *Q)
{
	if(Q->front==Q->rear)
	{
		printf("Queue is empty\n");
		return 1;
	} else {
		printf("Queue is not empty\n");
		return 0;
	}
}

int isFull(Queue *Q)
{
	if(Q->front>0)
	{
		int step = Q->front;
		for(int i=Q->front; i<=Q->rear; i++)
		{
			Q->data[i-step] = Q->data[i];
		}
		Q->front = 0;
		Q->rear = Q->rear - step;
		return 0;
	} else if(Q->rear==MAXSIZE)
	{
		printf("Queue is full\n");
		return 1;
	} else {
		return 0;
	}
}

ElemType deQueue(Queue *Q)
{
	if(Q->front==Q->rear)
	{
		printf("Queue is empty\n");
		return 0;
	}
	int e = Q->data[(Q->front)];
	Q->front++;
	return e;
}

int enQueue(Queue *Q, ElemType e)
{
	if(Q->rear == MAXSIZE)
	{
		if(isFull(Q))
		{
			return 0;
		}
	}
	Q->data[Q->rear] = e;
	Q->rear++;
	return 1;
}

int main(int argc, char const *argv[])
{
	printf("Hello world! Good morning.\n");
	Queue Q;
	initQueue(&Q);
	printf("front:%d, rear:%d\n", Q.front, Q.rear);
	enQueue(&Q, 1);
	enQueue(&Q, 2);
	enQueue(&Q, 3);
	enQueue(&Q, 4);
	enQueue(&Q, 5);
	isEmpty(&Q);
	printf("front:%d, rear:%d\n", Q.front, Q.rear);
	ElemType e = deQueue(&Q);
	printf("Out element:%d\n", e);
	e = deQueue(&Q);
	printf("Out element:%d\n", e);
	printf("front:%d, rear:%d\n", Q.front, Q.rear);
	enQueue(&Q, 114);
	printf("front:%d, rear:%d\n", Q.front, Q.rear);
	printf("Last element is:%d\n", Q.data[Q.rear-1]);
	return 0;
}