#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

typedef char ElemType;

typedef struct TreeNode {
    ElemType data;
    struct TreeNode *lchild, *rchild;
}TreeNode, *BiTree;

typedef struct Stack {
    BiTree *data;
    int top;
}Stack;

Stack *initStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (BiTree *)malloc(sizeof(BiTree)*MAXSIZE);
    s->top = -1;
    return s;
}

int isStackEmpty(Stack *s) {
    if(s->top == -1) {
        printf("Empty\n");
        return 1;
    } else {
        return 0;
    }
}

int push(Stack *s, BiTree node) {
    if(s->top >= MAXSIZE-1) {
        printf("Full\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = node;
    return 1;
}

int pop(Stack *s, BiTree *node) {
    if(s->top == -1) {
        printf("Empty\n");
        return 0;
    }
    *node = s->data[s->top];
    s->top--;
    return 1;
}

void iterPreOrder(Stack *s, BiTree T) {
    while(T != NULL || isStackEmpty(s) != 1) {
        while(T != NULL) {
            printf("%c ", T->data);
            push(s, T);
            T = T->lchild;
        }
        pop(s, &T); //若是左孩子找不到，就回到上一个节点
        T = T->rchild; //找右孩子
    }
}

void iterInOrder(Stack *s, BiTree T) {
    while(T != NULL || isStackEmpty(s) != 1) {
        while(T != NULL) {
            push(s, T);
            T = T->lchild;
        }
        pop(s, &T); //若是左孩子找不到，就回到上一个节点
        printf("%c ", T->data);
        T = T->rchild; //找右孩子
    }
}

void iterPostOrder(Stack *s, BiTree T) {
    BiTree lastVisit = NULL;
    while (T != NULL || isStackEmpty(s) != 1) {
        while (T != NULL) {
            push(s, T);
            T = T->lchild;
        }
        BiTree peekNode = s->data[s->top];
        if (peekNode->rchild == NULL || peekNode->rchild == lastVisit) {
            printf("%c ", peekNode->data);
            lastVisit = peekNode; // 记录上次访问过的点
            pop(s, &T);
            T = NULL; // 防止重复进入左子树
        } else {
            T = peekNode->rchild;
        }
    }
}

typedef struct QueueNode {
    BiTree data;
    struct QueueNode *next;
}QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
}Queue;

Queue *initQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    QueueNode *n= (QueueNode *)malloc(sizeof(QueueNode));
    n->next = NULL;
    n->data = NULL;
    q->front = n;
    q->rear = n;
    return q;
}
// 我造的不是循环队列
int enQueue(Queue *Q, BiTree T) {
    QueueNode *s = (QueueNode *)malloc(sizeof(QueueNode));
    s->data = T;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return 1;
}

int deQueue(Queue *Q, BiTree *T) {
    if (Q->front == Q->rear) {
        return 0;
    }
    QueueNode *s = Q->front->next;
    *T = s->data;
    Q->front->next = s->next;
    if (s == Q->rear) {
        Q->rear = Q->front;
    }
    free(s);
    return 1;
}

int isQueueEmpty(Queue *Q) {
    if (Q->front==Q->rear)
	{
		return 1;
	} else {
		return 0;
	}
}

int getQueueSize(Queue *Q) {
    int count = 0;
    QueueNode *p = Q->front->next;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void levelOrder(BiTree T) {
    Queue *Q = initQueue();
    BiTree p;
    enQueue(Q, T);
    while (!isQueueEmpty(Q)) {
        deQueue(Q, &p);
        printf("%c ", p->data);
        if (p->lchild != NULL) {
            enQueue(Q, p->lchild);
        }
        if (p->rchild!= NULL) {
            enQueue(Q, p->rchild);
        }
    }
}


int getDepth(BiTree T) {
    Queue *Q = initQueue();
    BiTree p;
    int depth = 0;
    enQueue(Q, T);
    while (!isQueueEmpty(Q)) {
        int count = getQueueSize(Q);
        while (count != 0) {
            deQueue(Q, &p);
            if (p->lchild != NULL) {
                enQueue(Q, p->lchild);
            }
            if (p->rchild!= NULL) {
                enQueue(Q, p->rchild);
            }
            count--;
        }
        depth++;
    }
    return depth;
}


//递归实现创建二叉树
void createTree(BiTree *T, char str[]) {
    ElemType ch;
    static int idx = 0;
    ch = str[idx++];
    if (ch == '#') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTree));
        (*T)->data = ch;
        //因为lchild本来就是指针，而函数需要传入指针的指针，所以要取地址
        createTree(&(*T)->lchild, str);
        createTree(&(*T)->rchild, str);
    }
}

//递归前序遍历
void preOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c ", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

void inOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    inOrder(T->lchild);
    printf("%c ", T->data);
    inOrder(T->rchild);
}

void postOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c ", T->data);
}

int main() {
    printf("Hello BiTree!\n");
    char str[] = "ABDH#K###E##CFI###G#J##";
    //char str[] = "ABDI#J##E##CF#GK#L##H####";
    Stack *S = initStack();
    BiTree T;
    createTree(&T, str);
    char chpre[] = "preOrder:";
    printf("%-12s", chpre);
    preOrder(T);
    char chin[] = "inOrder:";
    printf("\n%-12s", chin);
    inOrder(T);
    char chpost[] = "postOrder:";
    printf("\n%-12s", chpost);
    postOrder(T);
    printf("\n");
    printf("非递归前序: ");
    iterPreOrder(S, T);
    printf("非递归中序: ");
    iterInOrder(S, T);
    printf("非递归后序: ");
    iterPostOrder(S, T);
    printf("层次遍历:   ");
    levelOrder(T);
    printf("\n");
    int depth = getDepth(T);
    printf("深度为:     %d\n", depth);
    return 0;
}
