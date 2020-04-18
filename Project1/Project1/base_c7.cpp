#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATASIZE 4
#define _CRT_SECURE_NO_WARNINGS

typedef struct ListNode
{
	char data[DATASIZE];
	struct ListNode *link;
} listNode;

typedef struct
{
	listNode *head;
} listNode_h;

listNode_h *CreateListNode()
{
	listNode_h *NewNode = (listNode_h *)malloc(sizeof(listNode_h));

	NewNode->head = NULL;

	return NewNode;
}

void DeleteListNode(listNode_h *L)
{
	listNode *p;

	while (L->head != NULL)
	{
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void PrintList(listNode_h *L)
{
	listNode *p;
	p = L->head;

	printf("L : [ ");

	while (p != NULL)
	{
		printf("%3s",p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}

	printf(" ]\n");
}

void InsertFirstNode(listNode_h *L, char * nVal)
{
	listNode *NewNode = (listNode *)malloc(sizeof(listNode));

	strcpy_s(NewNode->data, nVal);

	NewNode->link = L->head;
	L->head = NewNode;
}

void InsertMiddleNode(listNode_h *L, listNode *pre, char *nVal)
{
	listNode *NewNode = (listNode *)malloc(sizeof(listNode));

	strcpy_s(NewNode->data, nVal);

	if (L->head == NULL)
	{
		NewNode->link = NULL;
		L->head = NewNode;
	}
	else if (pre == NULL)
	{
		L->head = NewNode;
	}
	else
	{
		NewNode->link = pre->link;
		pre->link = NewNode;
	}
}

void InsertLastNode(listNode_h *L, char *nVal)
{
	listNode *temp;
	listNode *NewNode = (listNode *)malloc(sizeof(listNode));

	strcpy_s(NewNode->data, nVal);
	NewNode->link = NULL;

	if (L->head == NULL)
	{
		L->head = NewNode;
		return;
	}

	temp = L->head;
	while (temp->link != NULL)
	{
		temp = temp->link;
	}

	temp->link = NewNode;
}

int main()
{
	listNode_h *L = CreateListNode();

	PrintList(L);

	InsertFirstNode(L, "수"); PrintList(L);
	InsertFirstNode(L, "화"); PrintList(L);
	InsertFirstNode(L, "월"); PrintList(L);

	InsertLastNode(L, "목"); PrintList(L);
	InsertLastNode(L, "금"); PrintList(L);
	InsertLastNode(L, "토"); PrintList(L);
	InsertLastNode(L, "일"); PrintList(L);

	DeleteListNode(L);

	getchar();

	return 0;
}