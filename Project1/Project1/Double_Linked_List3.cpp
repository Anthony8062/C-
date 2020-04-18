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

	printf("이중 연결 리스트 '월' 삽입 -> ");
	InsertNode(DL, NULL, "월"); PrintNode(DL); getchar();

	printf("이중 연결 리스트 '화' 삽입 - >");
	p = SelectNode(DL, "월");
	InsertNode(DL, p, "화"); PrintNode(DL); getchar();

	printf("이중 연결 리스트 '수' 삽입 - >");
	p = SelectNode(DL, "화");
	InsertNode(DL, p, "수"); PrintNode(DL); getchar();

	printf("이중 연결 리스트 '목' 삽입 - >");
	p = SelectNode(DL, "수");
	InsertNode(DL, p, "목"); PrintNode(DL); getchar();

	printf("이중 연결 리스트 '목' 삭제 - >");
	p = SelectNode(DL, "목");
	DeleteNode(DL, p); PrintNode(DL); getchar();

	printf("이중 연결 리스트 '금' 삽입 - >");
	p = SelectNode(DL, "수");
	InsertNode(DL, p, "금"); PrintNode(DL); getchar();

	printf("이중 연결 리스트 '토' 삽입 - >");
	p = SelectNode(DL, "화");
	InsertNode(DL, p, "토"); PrintNode(DL); getchar();

	return 0;
}