#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode
{
	struct listNode *llink;
	char data[8];
	struct listNode *rlink;
}linkedNode;

typedef struct
{
	listNode *head;
}linkedList_h;

linkedList_h *CreateNode()
{
	linkedList_h *DL = (linkedList_h *)malloc(sizeof(linkedList_h));
	DL->head = NULL;

	return DL;
}

void PrintNode(linkedList_h *DL)
{
	listNode *p = DL->head;

	printf("DL = (");

	while (p != NULL)
	{
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}

	printf("\n");
}

void InsertNode(linkedList_h *DL, linkedNode *p, char *data)
{
	linkedNode *NewNode = (linkedNode *)malloc(sizeof(linkedNode));
	strcpy_s(NewNode->data, data);

	if (DL->head == NULL)
	{
		DL->head = NewNode;
		NewNode->llink = NULL;
		NewNode->rlink = NULL;
	}
	else
	{
		NewNode->rlink = p->rlink;
		p->rlink = NewNode;
		NewNode->llink = p;
		NewNode->rlink = NULL;
		if (NewNode->rlink != NULL)
		{
			NewNode->rlink->llink = NewNode;
		}
	}
}

linkedNode *SelectNode(linkedList_h *DL, char *data)
{
	linkedNode *p;
	p = DL->head;

	while (p->rlink != NULL)
	{
		if (!(strcmp(p->data, data)))
			return p;
		else
			p = p->rlink;
	}
}

void DeleteNode(linkedList_h *DL, linkedNode *old)
{
	if (DL->head == NULL) return;
	else if (old == NULL) return;
	else
	{
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		free(old);
	}
}

int main(void)
{
	linkedList_h *DL = CreateNode();
	listNode *p;

	printf("���߿��� ����Ʈ ����");
	PrintNode(DL); getchar();
	
	printf("���߿��� ����Ʈ �� ��� ����");
	InsertNode(DL, NULL, "��");
	PrintNode(DL); getchar();

	printf("���߿��� ����Ʈ ȭ ��� ����");
	p = SelectNode(DL, "��");
	InsertNode(DL, p, "ȭ");
	PrintNode(DL); getchar();

	printf("���߿��� ����Ʈ �� ��� ����");
	p = SelectNode(DL, "ȭ");
	InsertNode(DL, p, "��");
	PrintNode(DL); getchar();

	printf("���߿��� ����Ʈ �� ��� ����");
	p = SelectNode(DL, "��");
	InsertNode(DL, p, "��");
	PrintNode(DL); getchar();

	printf("���߿��� ����Ʈ �� ��� ����");
	p = SelectNode(DL, "��");
	InsertNode(DL, p, "��");
	PrintNode(DL); getchar();

	printf("���߿��� ����Ʈ �� ��� ����");
	p = SelectNode(DL, "��");
	DeleteNode(DL, p);
	PrintNode(DL); getchar();

	return 0;
}