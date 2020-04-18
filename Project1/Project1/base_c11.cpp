#include <stdio.h>
#include <stdlib.h>
//LinkedList Queue
typedef struct Node
{
	unsigned int data;
	struct Node *link;

	void SetNode(int nData)
	{
		data = nData;
		link = NULL;
	}
};

typedef struct
{
	Node *front;
	Node *rear;
}QueueType;

QueueType *CreateNode()
{
	QueueType *Q = (QueueType *)malloc(sizeof(QueueType));
	Q->front = Q->rear = NULL;

	return Q;
}

bool Empty(QueueType *Q)
{
	if (Q->rear == NULL) return 1;
	else return 0;
}

void enQueue(QueueType *Q, int ndata)
{
	Node *NewNode = (Node *)malloc(sizeof(Node));
	NewNode->SetNode(ndata);

	if (Empty(Q))
	{
		printf("Queue Buffer is Empty, So New enQueue\n");
		Q->front = Q->rear = NewNode;
	}
	else
	{
		Q->rear->link = NewNode;
		Q->rear = NewNode;
	}
}

int deQueue(QueueType *Q)
{
	if (Empty(Q))
	{
		printf("-> So deQueue Fail\n");
		exit(1);
	}
	else
	{
		Q->front = Q->front->link;
		if (Q->front == NULL) Q->rear = NULL;
	}
}

void PrintQueue(QueueType *Q)
{
	if (Empty(Q))
	{
		printf("Queue Buffer is Empty\n");
		printf("-> So Print Fail\n");
		return;
	}

	Node *ptr;
	for (ptr = Q->front; ptr != Q->rear; ptr = ptr->link)
	{
		printf("%3d", ptr->data);
	}
	printf("\n");
}

int main(void)
{
	QueueType *Q = CreateNode();
	PrintQueue(Q);

	enQueue(Q, 1);
	enQueue(Q, 2);
	enQueue(Q, 3);
	enQueue(Q, 4);
	PrintQueue(Q);

	enQueue(Q, 5);
	enQueue(Q, 6);
	enQueue(Q, 7);
	PrintQueue(Q);

	deQueue(Q);
	deQueue(Q);
	deQueue(Q);
	deQueue(Q);
	PrintQueue(Q);

	enQueue(Q, 10);
	enQueue(Q, 11);
	enQueue(Q, 12);
	enQueue(Q, 13);
	enQueue(Q, 14);
	enQueue(Q, 15);
	PrintQueue(Q);

	getchar();
	return 0;
}