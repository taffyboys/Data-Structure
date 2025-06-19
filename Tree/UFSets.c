#include <stdio.h>
#define MAXSIZE 100

typedef int ElemType ;

//ElemType UFSets[MAXSIZE];

void initSets(ElemType *Sets) {
    for (int i=0; i<MAXSIZE; i++) {
        Sets[i] = -1;
    }
}

int FindRoot(ElemType *Sets, ElemType index) {
    while (Sets[index] >= 0) {
        index = Sets[index];
    }
    return index;
}

int Union(ElemType *Sets, int Root1, int Root2) {
    if (Root1 == Root2) {
        return 0;
    }
    Sets[Root1] = Root2;
    return 1;
}

int main() {
    ElemType UFSets[]={-1,  0, -1, -1,
                        1,  1,  2,  3,
                        3,  3, 4, 4,
                       7};
    ElemType r = FindRoot(UFSets, 4);
    printf("%d\n", r);
    Union(UFSets, 0, 3);
    r = FindRoot(UFSets, 4);
    printf("%d\n", r);
    return 0;
}