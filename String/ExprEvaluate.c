#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

char expr[] = "82/2+56*-";

typedef struct
{
	ElemType *data;
	int top;
}Stack;

typedef enum
{
	LEFT_BRAC, RIGHT_BRAC, ADD, SUB, MUL, DIV, MOD, EOS, NUM
}contentType;

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

int getValue(Stack *s)
{
	int index = 0;
	char symbol;
	int op1, op2;
	contentType token;
	token = getToken(&symbol, &index);
	ElemType result;
	while (token != EOS)
	{
		if (token == NUM)
		{
			pushStack(s, symbol - '0');
		} else {
			popStack(s, &op2);
			popStack(s, &op1);
			switch (token)
			{
				case ADD:
					pushStack(s, op1 + op2);
					break;
				case SUB:
					pushStack(s, op1 - op2);
					break;
				case MUL:
					pushStack(s, op1 * op2);
					break;
				case DIV:
					pushStack(s, op1 / op2);
					break;
				case MOD:
					pushStack(s, op1 % op2);
					break;
				default:
					break;
			}
		}
		token = getToken(&symbol, &index);
	}
	popStack(s, &result);
	printf("%d\n", result);
	return 1;
}

int main(int argc, char const *argv[])
{
	Stack *S = initStack();
	getValue(S);
	return 0;
}