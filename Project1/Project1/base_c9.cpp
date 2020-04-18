#include <stdio.h>
#include <stdlib.h>
#include <string>

#define LIST_SIZE 8

typedef struct ListNode
{
	char data[LIST_SIZE];
	struct ListNode *link;
} listNode;

typedef struct
{
	listNode *head;
} listNode_h;

listNode_h *CreateNode()
{
	listNode_h *L = (listNode_h *)malloc(sizeof(listNode_h));
	L->head = NULL;

	return L;
}

void DeleteNode(listNode_h *L)
{
	listNode *P;

	while (L->head != NULL)
	{
		P = L->head;
		L->head = L->head->link;
		free(P);
		P->link = NULL;
	}
}

void InsertFirstNode(listNode_h *L, char *nVal)
{
	listNode * NewNode = (listNode *)malloc(sizeof(listNode));
	strcpy(NewNode->data, nVal);
	
	NewNode->link = L->head;
	L->head = NewNode;	
}

void InsertMiddleNode(listNode_h *L, listNode *Pre, char *nVal)
{
	listNode *NewNode = (listNode *)malloc(sizeof(listNode));
	strcpy(NewNode->data, nVal);
	NewNode->link = NULL;

	if (L->head == NULL)
	{
		return;
	}

	else if (Pre == NULL)
	{
		L->head = NewNode;
	}
	else
	{
		NewNode->link = Pre->link;
		Pre->link = NewNode;
	}
}

void InsertLastNode(listNode_h *L, char *nVal)
{
	listNode *p;
	listNode *NewNode = (listNode *)malloc(sizeof(listNode));
	strcpy(NewNode->data, nVal);
	NewNode->link = NULL;

	if (L->head == NULL)
	{
		return;
	}
	else
	{
		p = L->head;
		while (p->link != NULL)
		{
			p = p->link;
		}

		p->link = NewNode;
	}
}

listNode *SearchNode(listNode_h *L, char *nVal)
{
	listNode *p;
	p = L->head;

	while (p != NULL)
	{
		if (strcmp(p->data, nVal) == 0)
		{
			printf("Search Node Success %s", p->data);
			return p;
		}
		else
		{
			p = p->link;
		}
	}

	printf("Search Node Fail : %s \n", nVal);
	return p;
}



int main()
{
	listNode_h *L = CreateNode();

	InsertFirstNode(L, "±Ý");


	DeleteNode(L);

	getchar();

	return 0;
}