#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;

int insertTail(Node *L, ElemType e)
{
    Node *p = L;
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = NULL;
    while(p->next!=NULL)
    {
        p = p->next;
    }
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

int freeList(Node *L)
{
    Node *p = L->next;
    Node *q = (Node *)malloc(sizeof(Node));
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
    printf("Free List Success\n");
    return 1;
}

void removeFuction(Node *L, int n) //2015年题目
{
    Node *p = L;
    int *array = (int *)calloc(n+1, sizeof(int));
    int index=0;
    while(p->next!=NULL)
    {
        index = abs(p->next->data);
        if(*(array+index) == 0)
        {
            *(array+index) = 1;
            p = p->next;
        } else {
            Node *s = (Node *)malloc(sizeof(Node));
            s = p->next;
            p->next = s->next;
            free(s);
        }
    }
    free(array);
}

int delMidElem(Node *L)
{
    Node *fast = L->next;
    Node *slow = L;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *e = slow->next;
    slow->next = e->next;
    free(e);
    return 1;
}


int main()
{
    Node *List = (Node *)malloc(sizeof(Node));
    insertTail(List, 21);
    insertTail(List, -15);
    insertTail(List, 5);
    insertTail(List, 1);
    insertTail(List, 15);
    insertTail(List, 15);
    insertTail(List, 10);
    insertTail(List, -1);
    printList(List);
    removeFuction(List, 21);
    printList(List);
    return 0;
}
