#include <stdio.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct stack
{
    ElemType data[MAXSIZE];
    int top;
}Stack;

int initStack(Stack *S)
{
    S->top = -1;
}

int isEmpty(Stack *S)
{
    if(S->top==-1)
    {
        return 1;
    } else {
        return 0;
    }
}

int pushStack(Stack *S, ElemType e)
{
    if(S->top == MAXSIZE-1)
    {
        printf("Stack is full!");
        return 0;
    }
    S->top++;
    S->data[S->top] = e;
    return 1;
}

int popStack(Stack *S, ElemType *e)
{
    if(S->top == -1)
    {
        printf("Stack is empty!");
        return 0;
    }
    *e = S->data[S->top];
    S->top--;
    return 1;
}

int getTop(Stack *S, ElemType *e)
{
    if(S->top == -1)
    {
        printf("Stack is empty!");
        return 0;
    }
    *e = S->data[S->top];
    return 1;
}

int main()
{
    Stack S;
    initStack(&S);
    pushStack(&S, 10);
    pushStack(&S, 20);
    pushStack(&S, 30);
    ElemType e;
    getTop(&S, &e);
    printf("Top index is %d\n", S.top);
    printf("Top element is %d\n", e);
    popStack(&S, &e);
    printf("Top index is %d\n", S.top);
    printf("Poped element is %d\n", e);
    getTop(&S, &e);
    printf("Top element is %d\n", e);
    printf("Stack is empty:%d\n", isEmpty(&S));
    return 0;
}
