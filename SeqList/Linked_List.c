#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

void printf_red(const char *s)
{
    printf("\033[0m\033[1;31m%s\033[0m", s);
}

void printf_green(const char *s)
{
    printf("\033[0m\033[1;32m%s\033[0m", s);
}

void printf_yellow(const char *s)
{
    printf("\033[0m\033[1;33m%s\033[0m", s);
}

void printf_blue(const char *s)
{
    printf("\033[0m\033[1;34m%s\033[0m", s);
}

void printf_pink(const char *s)
{
    printf("\033[0m\033[1;35m%s\033[0m", s);
}

void printf_cyan(const char *s)
{
    printf("\033[0m\033[1;36m%s\033[0m", s);
}

typedef struct Node
{
    ElemType data;
//    int length;
    struct Node *next;
}Node;

Node *initList()
{
    Node* head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

// 头插法
int insertHead(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}

// 尾插法
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

// 指定位置插入
int inserList(Node *L, int index, int e)
{
    Node *p = L;
    for (int i=0; i<index-1 && p->next!=NULL; i++)
    {
        p = p->next; // 循环到末尾时p的索引为index-1
    }
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next; // s的指向index
    p->next = s; // p指向s，顺序不能变
    return 1;
}

int deletElem(Node *L, int index, ElemType *e)
{
    Node *p = L;
    for(int i=0; i<index-1 && p->next!=NULL; i++)
    {
        p = p->next;
    }
    Node *s = (Node *)malloc(sizeof(Node));
    s = p->next;
    *e = s->data;
    p->next = s->next;
    free(s);
    return 1;
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
    printf_cyan("Free List Success\n");
    return 1;
}


// 按序号找节点
Node *getElem(Node *L, int index)
{
    Node *p = L;
    for (int i=0; i<index && p->next!=NULL; i++)
    {
        p = p->next;
    }
    return p;
}

// 按值查找节点
Node *locateElem(Node *L, ElemType e)
{
    Node *p = L->next;
    while(p->data!=e && p!=NULL)
    {
        p = p->next;
    }
    return p;
}

void getLength(Node *L)
{
    Node *p = L->next;
    int length = 0;
    while(p != NULL)
    {
        p = p->next;
        length++;
    }
    printf("length:%d\n", length);
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
    Node *List = initList();
    insertHead(List, 10);
    insertHead(List, 20);
    insertHead(List, 30);
    insertTail(List, 11);
    insertTail(List, 22);
    insertTail(List, 33);
    inserList(List, 6, 114);
    printList(List);
    getLength(List);
    Node *e3 = getElem(List, 3);
    printf("The third Element is:%d\n", e3->data);
    Node *e6 = locateElem(List, 33);
    printf("The node data 33 is:%d\n", e6->data);
    ElemType deletedData=0;
    deletElem(List, 4, &deletedData);
    printList(List);
    getLength(List);
    printf("Deleted data is:%d\n", deletedData);
    freeList(List);
    getLength(List);
    printf_green("Success\n");
    return 0;
}
