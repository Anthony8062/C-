#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATASIZE 8
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

void DeleteNode(listNode_h *L, listNode * p)
{
	listNode *pre;

	if (L->head == NULL)
	{
		printf("Delete Node Empty\n");
		return;
	}

	if (L->head->link == NULL)
	{
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (p == NULL)
	{
		return;
	}
	else
	{
		pre = L->head;
		while (pre->link != p)
		{
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
	}
}

void reverse(listNode_h *L)
{
	listNode *p;
	listNode *r;
	listNode *q;

	p = L->head;
	r = NULL;
	q = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;

		p = p->link;
		q->link = r;
	}
		
	L->head = q;
}

void PrintList(listNode_h *L)
{
	listNode *p;
	p = L->head;

	printf("L : [ ");

	while (p != NULL)
	{
		printf("%3s", p->data);
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

listNode *SearchNode(listNode_h *L, char *nVal)
{
	listNode *temp;
	temp = L->head;

	while (temp != NULL)
	{
		if (strcmp(temp->data, nVal) == 0)
		{
			printf("Search Node Success : %s \n", temp->data);
			return temp;
		}
			
		else
		{
			temp = temp->link;
		}
	}

	printf("Search Node Fail : %s \n", nVal);

	return temp;
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
	listNode * p;

	PrintList(L);

	InsertFirstNode(L, "수"); PrintList(L);
	InsertFirstNode(L, "화"); PrintList(L);
	InsertFirstNode(L, "월"); PrintList(L);

	InsertLastNode(L, "목"); PrintList(L);
	InsertLastNode(L, "금"); PrintList(L);
	InsertLastNode(L, "토"); PrintList(L);
	InsertLastNode(L, "일"); PrintList(L);

	p = SearchNode(L, "수");
	DeleteNode(L, p); PrintList(L);

	reverse(L); PrintList(L);

	DeleteListNode(L);

	getchar();

	return 0;
}