#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct {
    ElemType *elem;
    int Len;
}Table ;

int Binary_Search(Table ST, ElemType key) {
    int low = 0;
    int high = ST.Len - 1;
    int mid = (low + high)/2;
    while (low <= high) {
        if (ST.elem[mid] == key) {
            return mid;
        }
        else if (ST.elem[mid] < key) {
            low = ++mid;
        } else {
            high = --mid;
        }
    }
    return -1;
}

int main() {
    int len = 12;
    Table ST;
    ST.elem = (ElemType *)malloc(len * sizeof(ElemType));
    ST.Len = len;
    ElemType arr[12] = {1, 3, 4 ,6 ,10, 14, 15, 17, 18, 19,  22, 24};
    // for (int i = 0; i<ST.Len; ++i) {
    //     ST.elem[i] = arr[i];
    // }
    memcpy(ST.elem, arr, ST.Len * sizeof(ElemType));

    int index = Binary_Search(ST, 17);
    printf("index = %d\n", index);
    free(ST.elem);
    return 0;
}