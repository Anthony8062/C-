#include <stdio.h>

#define STACKSIZE 100

int stack[STACKSIZE];
int top = -1;

int Empty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

int Full()
{
	if (top == STACKSIZE - 1)
		return 1;
	else
		return 0;
}

void Push(int nValue)
{
	if (Full())
	{
		printf("\nStack size Full\n");
		return;
	}
	
	stack[++top] = nValue;
}

int Pop()
{
	if (Empty())
	{
		printf("\nStack size already empty\n");
		return 0;
	}

	return stack[top--];
}

void PrintStack()
{
	printf("\nSTACK [ ");
	for (int i = 0; i <= top; i++)
	{
		printf("%2d", stack[i]);
	}
	printf(" ]\n");
}

int main()
{
	int Value;

	PrintStack();

	Push(1); PrintStack();
	Push(2); PrintStack();
	Push(3); PrintStack();
	Push(4); PrintStack();
	Push(5); PrintStack();

	Value = Pop(); PrintStack();
	printf("Pop -> %2d", Value);
	
	Value = Pop(); PrintStack();
	printf("Pop -> %2d", Value);

	Value = Pop(); PrintStack();
	printf("Pop -> %2d", Value);

	getchar();

	return 0;
}