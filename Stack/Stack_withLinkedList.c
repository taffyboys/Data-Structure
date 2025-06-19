#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100;

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
}Stack;

Stack *initStack()
{
    Stack *S = (Stack *)malloc(sizeof(Stack));
    S->data = 0;
    S->next = NULL;
    return S;
}

int isEmpty(Stack *S)
{
    if(S->next==NULL)
    {
        printf("Stack is Empty\n");
        return 1;
    } else {
        printf("Stack is not Empty\n");
        return 0;
    }
}

int pushStack(Stack *S, ElemType e)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = e;
    p->next = S->next;
    S->next = p;
    return 1;
}

int popStack(Stack *S, ElemType *e)
{
    if(S->next == NULL)
    {
        printf("Stack is empty\n");
        return 0;
    }
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p = S->next;
    *e = p->data;
    S->next = p->next;
    free(p);
    return 1;
}

int getTop(Stack *S, ElemType *e)
{
    if(S->next == NULL)
    {
        printf("Stack is empty\n");
        return 0;
    }
    *e = S->next->data;
    return 1;
}

int main()
{
    Stack *S = initStack();
    ElemType e;
    pushStack(S, 10);
    pushStack(S, 20);
    pushStack(S, 30);
    pushStack(S, 40);
    popStack(S, &e);
    isEmpty(S);
    getTop(S, &e);
    printf("Top element is %d\n", e);
}
