#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 7

typedef struct stack
{
	int _stack[STACK_SIZE];
	int top;
}Stack;

Stack *StackCreate()
{
	Stack *q = (Stack*)malloc(sizeof(Stack));
	q->top = -1;

	return q;
}

bool Empty(Stack *q)
{
	if (q->top < 0)
		return 1;
	else
		return 0;
}

bool Full(Stack *q)
{
	if (q->top == STACK_SIZE-1)
		return 1;
	else
		return 0;
}

void Push(Stack *q, int nVal)
{
	if (Full(q))
	{
		printf("Stack Size Full\n");
		return;
	}
	else
	{
		q->_stack[++(q->top)] = nVal;
	}
}

void Pop(Stack *q)
{
	if (Empty(q))
	{
		printf("Stack Size Empty\n");
		return;
	}
	else
	{
		q->_stack[--(q->top)];
	}
}

void Print(Stack *q)
{
	if (Empty(q))
	{
		printf("Stack Size Empty\n");
		return;
	}
	
	int i;
	int j = q->top;
	printf("stack = ");
	for (i = 0; i <= j; i++)
	{
		printf("%3d", q->_stack[i]);
	}
	printf("\n");
}

int main(void)
{
	Stack *st = StackCreate();
	
	Print(st);

	Push(st, 1); Print(st);
	Push(st, 2); Print(st);
	Push(st, 3); Print(st);
	Push(st, 4); Print(st);
	Push(st, 7); Print(st);
	Push(st, 8); Print(st);
	Push(st, 9); Print(st);
	
	Pop(st); Print(st);
	Pop(st); Print(st);
	Pop(st); Print(st);
	Pop(st); Print(st);
	Pop(st); Print(st);
	Pop(st); Print(st);

	getchar();

	return 0;
}