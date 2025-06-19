//#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
	ElemType *data;
	int top;
}Stack;

char expr[] = "x/(i-j)*(y+z)";

Stack *initStack()
{
	Stack *S = (Stack *)malloc(sizeof(Stack));
	S->data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	S->top = -1;
	return S;
}

int isEmpty(Stack *s)
{
	if (s->top==-1)
	{
		printf("Is Empty\n");
		return 1;
	} else {
		return 0;
	}
}

int pushStack(Stack *s, ElemType e)
{
	if (s->top == MAXSIZE-1)
	{
		printf("Is Full\n");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}

int popStack(Stack *s, ElemType *e)
{
	if (isEmpty(s))
	{
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}

int getTop(Stack *s, ElemType *e)
{
	if (isEmpty(s))
	{
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}

typedef enum
{
	LEFT_BRAC, RIGHT_BRAC, ADD, SUB, MUL, DIV, MOD, EOS, NUM
}contentType;

contentType getToken(char *symbol, int *index)
{
	*symbol = expr[*index];
	*index = *index+1;
	switch(*symbol)
	{
		case '(': 
			return LEFT_BRAC;
		case ')': 
			return RIGHT_BRAC;
		case '+': 
			return ADD;
		case '-': 
			return SUB;
		case '*': 
			return MUL;
		case '/': 
			return DIV;
		case '%': 
			return MOD;
		case '\0': 
			return EOS;
		default: 
			return NUM;
	}
}

int print_token(contentType token)
{
	switch(token)
	{
		case ADD:
			printf("+");
			break;
		case SUB:
			printf("-");
			break;
		case MUL:
			printf("*");
			break;
		case DIV:
			printf("/");
			break;
		case MOD:
			printf("%%");
			break;
		default:
			return 0;
	}
	return 1;
}

void postfix(Stack *s)
{
	int in_stack[] = {0, 19, 12, 12, 13, 13, 13, 0};
	int out_stack[] = {20, 19, 12, 12, 13, 13, 13, 0};
	int index = 0;
	char symbol;
	ElemType e;
	contentType token;
	s->top = 0;
	s->data[0] = EOS;
	token = getToken(&symbol, &index);
	while(token != EOS)
	{
		if (token == NUM)
		{
			printf("%c", symbol);
		} else if (token == RIGHT_BRAC) {
			while(s->data[s->top] != LEFT_BRAC) {
				popStack(s, &e);
				print_token(e);
			}
			popStack(s, &e);
		} else {
			while (in_stack[s->data[s->top]] >= out_stack[token])
			{
				popStack(s, &e);
				print_token(e);
			}
			pushStack(s, token);
		}
		token = getToken(&symbol, &index);
	}
	popStack(s, &e);
	token = e;
	while(token != EOS)
	{
		print_token(token);
		popStack(s, &e);
		token = e;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	printf("Hello Expression\n");
	Stack *S = initStack();
	printf("%s\n", expr);
	postfix(S);
	return 0;
}