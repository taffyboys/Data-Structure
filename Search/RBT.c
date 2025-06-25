#include <stdio.h>

typedef enum { red, black } Color;

typedef struct RBNode {
    int key;
    struct RBNode *parent;
    struct RBNode *lchild;
    struct RBNode *rchild;
    Color color;
} RBNode;

int main() {
    printf("Hello, Red-Black Tree!\n");
    return 0;
}