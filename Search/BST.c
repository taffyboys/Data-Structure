#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode{
    int data;
    struct BSTNode *left, *right;
} BSTNode, *BSTree;

BSTNode *Search(BSTree T, int key) {
    while (T != NULL && T->data != key) {
        if (T->data > key) {
            T = T->left;
        } else {
            T = T->right;
        }
    }
    return T;
}

int Insert(BSTree *T, int key) {
    if (*T == NULL) {
        *T = (BSTree)malloc(sizeof(BSTNode));
        (*T)->data = key;
        (*T)->left = NULL;
        (*T)->right = NULL;
        return 1;
    } else if (key == (*T)->data) {
        return 0;
    } else if (key < (*T)->data) {
        return Insert(&((*T)->left), key);
    } else {
        return Insert(&((*T)->right), key);
    }
}

void CreatBST(BSTree *T, int arr[], int n) {
    *T = NULL;
    for (int i = 0; i < n; ++i) {
        Insert(T, arr[i]);
    }
}

int main() {
    int arr[] = {50, 66, 60, 26, 21, 30, 70, 68};
    int len = sizeof(arr)/sizeof(arr[0]);
    BSTree T;
    CreatBST(&T, arr, len);
    BSTNode *s = Search(T, 21);
    if (s) {
        printf("%d\n", s->data);
    } else {
        printf("Not found\n");
    }
    return 0;
}