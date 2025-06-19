#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *prev, *next;
}Node;

int insertHead(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    p->prev = L;
    if(L->next!=NULL)
    {
        L->next->prev = p;
    }
    L->next = p;
    return 1;
}

int insertTail(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    Node *Tail = L;
    while(Tail->next!=NULL)
    {
        Tail = Tail->next;
    }
    p->data = e;
    p->prev = Tail;
    p->next = NULL;
    Tail->next = p;
    return 1;
}

int insertNode(Node *L, int pos, ElemType e)
{
    Node *p = L;
    for(int i=0; i<pos-1; i++)
    {
        p = p->next;
    }

    Node *s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    s->prev = p;
    p->next->prev = s;
    p->next = s;
    return 1;
}

void printList(Node *L)
{
    Node *p = L->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *List = (Node *)malloc(sizeof(Node));
    insertHead(List, 10);
    insertHead(List, 20);
    insertHead(List, 30);
    insertTail(List, 11);
    insertTail(List, 22);
    insertTail(List, 33);
    insertNode(List, 5, 114);
    printList(List);
    return 0;
}
