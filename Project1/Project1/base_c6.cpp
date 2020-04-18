#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 4

typedef struct
{
	char queue[QUEUESIZE];
	int front, rear;
} QueueType;

QueueType *CreateQueue()
{
	QueueType *Q = (QueueType *)malloc(sizeof(QueueType));
	Q->front = 0;
	Q->rear = 0;

	printf("Create Queue Success\n");

	return Q;
}

void DeleteQueue(QueueType *Q)
{
	free(Q);
	printf("Delete Queue Success\n");
}

int Empty(QueueType *Q)
{
	if (Q->front == Q->rear)
		return 1;
	else
		return 0;
}

int Full(QueueType *Q)
{
	if ((Q->rear + 1) % QUEUESIZE == Q->front)
		return 1;
	else
		return 0;
}

void enQueue(QueueType *Q, char nVal)
{
	if (Full(Q))
		printf("Circular Queue size full\n");
	else
	{
		Q->rear = (Q->rear + 1) % QUEUESIZE;
		Q->queue[Q->rear] = nVal;
	}
}

char deQueue(QueueType *Q)
{
	if (Empty(Q))
	{
		printf("Circular Queue size empty\n");
		exit(1);
	}
	else
	{
		Q->front = (Q->front + 1) % QUEUESIZE;
		return Q->queue[Q->front];
	}
}

void PrintQueue(QueueType *Q)
{
	int i;

	printf("Queue : [ ");

	int first = (Q->front + 1) % QUEUESIZE;
	int last = (Q->rear + 1) % QUEUESIZE;

	for (i = first; i != last; i = (i + 1) % QUEUESIZE)
	{
		printf("%3c", Q->queue[i]);
	}

	printf(" ]\n");
}

int main()
{
	QueueType *Q = CreateQueue();
	char data;

	PrintQueue(Q);
	enQueue(Q, 'A'); PrintQueue(Q);
	enQueue(Q, 'B'); PrintQueue(Q);
	enQueue(Q, 'C'); PrintQueue(Q);
	
	data = deQueue(Q); printf("Queue : %c ", data);	PrintQueue(Q);
	data = deQueue(Q); printf("Queue : %c ", data);	PrintQueue(Q);
	data = deQueue(Q); printf("Queue : %c ", data); PrintQueue(Q);

	enQueue(Q, 'A'); PrintQueue(Q);
	enQueue(Q, 'B'); PrintQueue(Q);
	enQueue(Q, 'C'); PrintQueue(Q);

	DeleteQueue(Q);

	getchar();

	return 0;
}