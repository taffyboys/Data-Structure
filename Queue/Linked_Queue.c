#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Queuenode
{
	//节点
	ElemType data;
	struct Queuenode *next;
}Queuenode;

typedef struct
{
	//头尾指针
	Queuenode *front;
	Queuenode *rear;
}Queue;

Queue *initQueue()
{
	Queue *q = (Queue*)malloc(sizeof(Queue));
	Queuenode *node = (Queuenode*)malloc(sizeof(Queuenode)); //造了一个头节点
	node->next = NULL;
	node->data = 0;
	q->front = node; //都指向头节点
	q->rear = node;
	return q;
}

int isEmpty(Queue *Q)
{
	if (Q->front==Q->rear)
	{
		printf("Is Empty\n");
		return 1;
	} else {
		printf("Not Empty\n");
		return 0;
	}
}

int enQueue(Queue *Q, ElemType e)
{
	Queuenode *s = (Queuenode*)malloc(sizeof(Queuenode));
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return 1;
}

int deQueue(Queue *q, ElemType *e)
{
	if (isEmpty(q))
	{
		return 0;
	}
	Queuenode *s = q->front->next;
	*e = s->data;
	q->front->next = s->next;
	if (s==q->rear)
	{
		q->rear = q->front;
	}
	free(s);
	return 1;
}

int main(int argc, char const *argv[])
{
	Queue *Q = initQueue();
	//isEmpty(Q);
	enQueue(Q, 11);
	//isEmpty(Q);
	enQueue(Q, 22);
	enQueue(Q, 33);
	enQueue(Q, 44);
	ElemType e;
	deQueue(Q, &e);
	deQueue(Q, &e);
	printf("De elme is:%d\n", e);
	deQueue(Q, &e);
	deQueue(Q, &e);
	deQueue(Q, &e);
	return 0;
}