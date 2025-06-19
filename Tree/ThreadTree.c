#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElemType;

typedef struct ThreadNode {
	ElemType data;
	//ThreadNode *和ThreadTree是一样的
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode, *ThreadTree;

void createTree(ThreadTree *T, char *str) {
	static int idx = 0;
	ElemType ch = str[idx++];
	if (ch == '#')
	{
		*T = NULL;
	} else {
		//ThreadNode *和ThreadTree是一样的
		*T = (ThreadTree)malloc(sizeof(ThreadNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild, str);
		if ((*T)->lchild != NULL) {
			(*T)->ltag = 0;
		}
		createTree(&(*T)->rchild, str);
		if ((*T)->rchild != NULL) {
			(*T)->rtag = 0;
		}
	}
}

void inThread(ThreadTree T, ThreadTree *prev) {
	if (T != NULL) {
		inThread(T->lchild,  prev);
		if (T->lchild == NULL) {
			T->ltag = 1;
			T->lchild = *prev;
		}
		if ((*prev)->rchild == NULL) {
			(*prev)->rtag = 1;
			(*prev)->rchild = T;
		}
		(*prev) = T;
		inThread(T->rchild, prev);
	}
}

void createInThread(ThreadTree *head, ThreadTree T) {
	ThreadTree prev;
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	(*head)->ltag = 0;
	(*head)->rtag = 1;
	(*head)->rchild = (*head);
	if (T == NULL) {
		(*head)->lchild = (*head);
	} else {
		(*head)->lchild = T;
		prev = (*head);
		inThread(T, &prev);
		prev->rtag = 1;
		prev->rchild = *head;
		(*head)->rchild = prev;
	}
}

void inOrder(ThreadTree T) {
	ThreadTree curr;
	curr = T->lchild;
	while (curr != T) {
		while (curr->ltag == 0) {
			curr = curr->lchild;
		}
		printf("%c ", curr->data);
		while (curr->rtag == 1 && curr->rchild != T) {
			curr = curr->rchild;
			printf("%c ", curr->data);
		}
		curr = curr->rchild;
	}
	printf("\nover\n");
}


int main(int argc, char const *argv[])
{
	ThreadTree Head;
	ThreadTree Tree;
	char str[] = "ABDH##I##EJ###CF##G##";
	createTree(&Tree, str);
	createInThread(&Head, Tree);
	inOrder(Head);
	return 0;
}