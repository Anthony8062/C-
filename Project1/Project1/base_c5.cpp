#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 4

typedef struct
{
	char queue[QUEUESIZE];
	int rear, front;
} QueueType;

QueueType* CreateQueue()
{
	QueueType *Q = (QueueType*)malloc(sizeof(QueueType));
	
	Q->front = -1;
	Q->rear = -1;

	return Q;
}

void DeleteQueue(QueueType *Q)
{
	free(Q);
	printf("Queue Delete Success");
}

int Full(QueueType *Q)
{
	if (Q->rear == QUEUESIZE - 1)
		return 1;
	else
		return 0;
}

int Empty(QueueType *Q)
{
	if (Q->front == Q->rear)
		return 1;
	else
		return 0;
}

void enQueue(QueueType *Q, char nVal)
{
	if (Full(Q))
		printf("Queue size full\n");
	else
	{
		Q->queue[++Q->rear] = nVal;
	}
}

char deQueue(QueueType *Q)
{
	if (Empty(Q))
		exit(1);
	else
	{
		return Q->queue[++Q->front];
	}
}

void PrintQueue(QueueType *Q)
{
	int i;
	printf("Queue [ ");

	for (i = Q->front + 1; i <= Q->rear; i++)
	{
		printf("%2c", Q->queue[i]);
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
	enQueue(Q, 'D'); PrintQueue(Q);
	enQueue(Q, 'E'); PrintQueue(Q);

	data = deQueue(Q); printf("deQueue : %c , ", data); PrintQueue(Q);
	data = deQueue(Q); printf("deQueue : %c , ", data); PrintQueue(Q);
	data = deQueue(Q); printf("deQueue : %c , ", data); PrintQueue(Q);


	DeleteQueue(Q);

	getchar();

	return 0;
}