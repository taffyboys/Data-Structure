#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType *data;
    int length;
}SeqList;

//初始化线性表
SeqList *initList()
{
    SeqList *L = (SeqList *)malloc(sizeof(SeqList));
    L->data = (ElemType *)malloc(MAXSIZE*sizeof(ElemType));
    L->length = 0;
    return L;
}

//尾部添加元素
int appendElem(SeqList *L, int num)
{
    if (L->length>=MAXSIZE)
    {
        printf("SeqList full!\n");
        return 0;
    }
    L->data[L->length] = num;
    (L->length)++;
    return 1;
}

//插入元素
int insertElem(SeqList *L, int position, int Elem)
{
    if ((L->length) >= MAXSIZE)
    {
        printf("SeqList full!\n");
        return 0;
    }
    if (position<1 || position>(L->length + 1))
    {
        printf("Position Error!\n");
        return 0;
    }
    if (position <= L->length+1)
    {
        for (int i=(L->length); i>position-1; i--)
        {
            L->data[i] = L->data[i-1];
        }
        L->data[position-1] = Elem;
        (L->length)++;
    }
    return 0;
}

//删除元素
int deletElem(SeqList *L, int position, ElemType *e)
{
    if (position<1 || position>L->length)\
    {
        printf("Position Error!");
        return 0;
    }
    *e = L->data[position-1];
    for (int i=position; i<L->length; i++)
    {
        L->data[i-1] = L->data[i];
    }
    L->length--;
    return 1;
}

//查找元素
int findElem(SeqList *L, ElemType e)
{
    if (L->length==0)
    {
        printf("Empty List!");
    }
    for (int i=0; i<L->length; i++)
    {
        if (e==L->data[i])
        {
            return i+1;
        }
    }
    return 0;
}

//输出线性表
int printList(SeqList *L)
{
    for (int i = 0; i < (L->length); i++)
    {
        printf("%d ", L->data[i]);
    }
    return 1;
}

int main()
{
    SeqList *L = initList();
    printf("Memory Size:%zu\n", sizeof(L));
    printf("data length:%d\n", L->length);
    appendElem(L, 11);
    appendElem(L, 45);
    appendElem(L, 14);
    appendElem(L, 19);
    appendElem(L, 81);
    printList(L);
    printf("Data length:%d\n", L->length);
    insertElem(L, 6, 404);
    printList(L);
    printf("Data length:%d\n", L->length);
    int deletedElem=0;
    deletElem(L, 5, &deletedElem);
    printList(L);
    printf("Deleted Element is:%d, ", deletedElem);
    printf("Data length:%d\n", L->length);
    int wantedElem=19;
    int location=findElem(L, wantedElem);
    printf("The wantedElem{%d} is located in{%d}\n", wantedElem, location);
    printf("Memory Size:%zu\n", sizeof(L));
    free(L);
    return 0;
}
