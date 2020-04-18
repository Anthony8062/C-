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
	linkedNode *head;
}linkedNode_h;

linkedNode_h *CreateNode()
{
	linkedNode_h *NewNode = (linkedNode_h *)malloc(sizeof(linkedNode_h));
	NewNode->head = NULL;

	return NewNode;
}

void DeleteNode(linkedNode_h *DL, linkedNode *old)
{
	if (DL->head == NULL) return;
	else if (old == NULL) return;
	else
	{
		if (old->rlink == NULL)
		{
			old->llink->rlink = NULL;
		}
		else
		{
			old->rlink->llink = old->llink;
			old->llink->rlink = old->rlink;
			free(old);
		}
	}
}

void InsertNode(linkedNode_h *DL, linkedNode *p, char *strData)
{
	linkedNode *NewNode = (linkedNode *)malloc(sizeof(linkedNode));
	strcpy_s(NewNode->data, strData);

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
		if (NewNode->rlink != NULL) NewNode->rlink->llink = NewNode;
	}
}

linkedNode *SelectNode(linkedNode_h *DL, char *strData)
{
	linkedNode *Temp;
	Temp = DL->head;

	while (Temp != NULL)
	{
		if (!(strcmp(Temp->data, strData)))
			return Temp;
		else
			Temp = Temp->rlink;
	}
}

void PrintNode(linkedNode_h *DL)
{
	if (DL->head == NULL)
	{
		printf("Node Yet No Existence\n");
		return;
	}

	linkedNode *Temp;
	Temp = DL->head;

	printf("DL : (");
	while (Temp != NULL)
	{
		printf("%s", Temp->data);
		if (Temp->rlink != NULL) printf(", ");
		Temp = Temp->rlink;
	}
	printf(")\n");
}

int main(void)
{
	linkedNode_h *DL = CreateNode();
	linkedNode *p;

	PrintNode(DL);

	printf("���� ���� ����Ʈ '��' ���� -> ");
	InsertNode(DL, NULL, "��"); PrintNode(DL); getchar();

	printf("���� ���� ����Ʈ 'ȭ' ���� - >");
	p = SelectNode(DL, "��");
	InsertNode(DL, p, "ȭ"); PrintNode(DL); getchar();

	printf("���� ���� ����Ʈ '��' ���� - >");
	p = SelectNode(DL, "ȭ");
	InsertNode(DL, p, "��"); PrintNode(DL); getchar();

	printf("���� ���� ����Ʈ '��' ���� - >");
	p = SelectNode(DL, "��");
	InsertNode(DL, p, "��"); PrintNode(DL); getchar();

	printf("���� ���� ����Ʈ '��' ���� - >");
	p = SelectNode(DL, "��");
	DeleteNode(DL, p); PrintNode(DL); getchar();

	printf("���� ���� ����Ʈ '��' ���� - >");
	p = SelectNode(DL, "��");
	InsertNode(DL, p, "��"); PrintNode(DL); getchar();

	printf("���� ���� ����Ʈ '��' ���� - >");
	p = SelectNode(DL, "ȭ");
	InsertNode(DL, p, "��"); PrintNode(DL); getchar();

	return 0;
}