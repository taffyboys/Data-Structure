#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define Sentinel -1
typedef int ElemType ;

typedef struct {
    ElemType *elem;
    int Len;
}Table ;

int Seq_Search(Table ST, ElemType key) {
    ST.elem[0] = key;
    int i = ST.Len;
    while (ST.elem[i] != key) {
        --i;
    }
    return i;
}


int main() {
    int Len = 6;
    Table ST;
    ST.elem = (ElemType *)malloc((Len + 1) * sizeof(ElemType));
    ST.Len = Len;
    ST.elem[0] = Sentinel;
    ST.elem[1] = 10;
    ST.elem[2] = 20;
    ST.elem[3] = 30;
    ST.elem[4] = 40;
    ST.elem[5] = 50;
    ElemType key = 30;
    int index = Seq_Search(ST, key);
    printf("The key is locate in \033[1;32m%d\033[0m\n", index);
    return 0;
}