/* �����͸� ����� ���� ����Ʈ(�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

/*--- ȸ�� ��ȣ �� �Լ� ---*/
int MemberNoCmp(const Member *x, const Member *y)
{
	return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

/*--- ȸ�� �̸� �� �Լ� ---*/
int MemberNameCmp(const Member *x, const Member *y)
{
	return strcmp(x->name, y->name);
}

/*--- ȸ�� ������(��ȣ�� �̸�)�� ǥ��(�� �ٲ� ����) ---*/
void PrintMember(const Member *x)
{
	printf("%d %s", x->no, x->name);
}

/*--- ȸ�� ������(��ȣ�� �̸�)�� ǥ��(�� �ٲ� ����) ---*/
void PrintLnMember(const Member *x)
{
	printf("%d %s\n", x->no, x->name);
}

/*--- ȸ�� ������(��ȣ�� �̸�)�� �о� ���� ---*/
Member ScanMember(const char *message, int sw)
{
	Member temp;
	printf("%s�ϴ� �����͸� �Է��ϼ���.\n", message);
	if (sw & MEMBER_NO) { printf("��ȣ : "); scanf("%d", &temp.no); }
	if (sw & MEMBER_NAME) { printf("�̸� : "); scanf("%s", temp.name); }
	return temp;
}

/*--- ��带 �������� ���� ---*/
static Node *AllocNode(void)
{
	return calloc(1, sizeof(Node));
}

/*--- n�� ����Ű�� ����� �� ����� ���� ���� ----*/
static void SetNode(Node *n, const Member *x, const Node *next)
{
	n->data = *x;		/* ������ */
	n->next = next;		/* ���� ������ */
}
/*--- ���� ����Ʈ�� �ʱ�ȭ ---*/
void Initialize(List *list)
{
	list->head = NULL;	/* �Ӹ� ��� */
	list->crnt = NULL;	/* ������ ��� */
}

/*--- �Լ� compare�� ����� x�� �˻��մϴ�. ---*/
Node *search(List *list, const Member *x, int compare(const Member *x, const Member *y))
{
	Node *ptr = list->head;
	while (ptr != NULL) {
			if (compare(&ptr->data, x) == 0) {	/* Ű���� ���� ��� */
					list->crnt = ptr;
				return ptr;			/* �˻� ���� */
			}
		ptr = ptr->next;			/* ���� ��带 ���� */
	}
	return NULL;					/* �˻� ���� */
}

/*--- �Ӹ��� ��带 �����ϴ� �Լ� ---*/
void InsertFront(List *list, const Member *x)
{
	Node *ptr = list->head;
	list->head = list->crnt = AllocNode();
	SetNode(list->head, x, ptr);
}

/*--- ������ ��带 �����ϴ� �Լ� ---*/
void InsertRear(List *list, const Member *x)
{
	if (list->head == NULL)		/* ����ִ� ��� */
		InsertFront(list, x);	/* �Ӹ��� ���� */
	else {
		Node *ptr = list->head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = list->crnt = AllocNode();
		SetNode(ptr->next, x, NULL);
	}
}

/*--- �Ӹ���带 �����ϴ� �Լ� ---*/
void RemoveFront(List *list)
{
	if (list->head != NULL) {
		Node *ptr = list->head->next;		/* �� ��° ��忡 ���� ������ */
		free(list->head);					/* �Ӹ� ��带 ���� */
		list->head = list->crnt = ptr;		/* ���ο� �Ӹ� ��� */
	}
}

/*--- ���� ��带 �����ϴ� �Լ� ---*/
void RemoveRear(List *list)
{
	if (list->head != NULL) {
		if ((list->head)->next == NULL)	/* ��尡 �ϳ��� �ִ� ��� */
			RemoveFront(list);			/* �Ӹ� ��带 ���� */
		else {
			Node *ptr = list->head;
			Node *pre = NULL;
			while (ptr->next != NULL) {
				pre = ptr;
				ptr = ptr->next;
			}
			
			pre->next = NULL;	/* pre�� ���� ������ �� ��° ��� */
			free(ptr);			/* ptr�� ���� ��� */
			list->crnt = pre;
		}
	}
}

/*--- ������ ��带 �����ϴ� �Լ� ---*/
void RemoveCurrent(List *list)
{
	if (list->head != NULL) {
		if (list->crnt == list->head)	/* �Ӹ� ��带 ������ ���¶�� */
			RemoveFront(list);			/* �Ӹ� ��带 ���� */
		else {
			Node *ptr = list->head;
			while (ptr->next != list->crnt)
				ptr = ptr->next;
			ptr->next = list->crnt->next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

/*--- ��� ��带 ���� ---*/
void Clear(List *list)
{
	while (list->head != NULL)		/* �� �� ������ */
		RemoveFront(list);			/* �Ӹ� ��带 ���� */
	list->crnt = NULL;
}

/*--- ������ ����� �����͸� ��� ---*/
void PrintCurrent(const List *list)
{
	if (list->crnt == NULL)
		printf("������ ��尡 �����ϴ�.");
	else
		PrintMember(&list->crnt->data);
}
/*--- ������ ����� �����͸� ���(�ٹٲ� ���� ����) ---*/
void PrintLnCurrent(const List *list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- ��� ����� �����͸� ������� ����ϴ� �Լ� ---*/
void Print(const List *list)
{
	if (list->head == NULL)
		puts("��尡 �����ϴ�.");
	else {
		Node *ptr = list->head;
		puts("�� ��� ���� ��");
		while (ptr != NULL) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;		/* ���� ��� ���� */
		}
	}
}
/*--- ���� ����Ʈ�� �����ϴ� �Լ� ---*/
void Terminate(List *list)
{
	Clear(list);		/* ��� ��带 ���� */
}

/*--- �޴� ---*/
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
	RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu;

/*--- �޴� ���� ---*/
Menu SelectMenu(void)
{
	int i, ch;
	char *mstring[] = {
		"�Ӹ��� ��带 ����",   "������ ��带 ����",   "�Ӹ� ��带 ����",
		"���� ��带 ����",     "������ ��带 ���",   "������ ��带 ����",
		"��ȣ�� �˻�",          "�̸����� �˻�",        "��� ��带 ���",
		"��� ��带 ����",
	};
	
	do {
		for (i = TERMINATE; i < CLEAR; i++) {
			printf("(%2d) %-18.18s ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("( 0) ���� : ");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > CLEAR);
	
	return (Menu)ch;
}

/*--- ���� ---*/
int main(void)
{
	Menu menu;
	List list;
	
	Initialize(&list);                 /* ���� ����Ʈ�� �ʱ�ȭ */
	do {
		Member x;
		switch (menu = SelectMenu()) {
		/* �Ӹ��� ��带 ���� */
		case INS_FRONT:
			x = ScanMember("�Ӹ��� ����", MEMBER_NO | MEMBER_NAME);
			InsertFront(&list, &x);
			break;
		
		/* ������ ��带 ���� */
		case INS_REAR:
			x = ScanMember("������ ����", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;

		
		/* �Ӹ� ��带 ���� */
		case RMV_FRONT:
			RemoveFront(&list);
			break;

		/* ���� ��带 ���� */
		case RMV_REAR:
			RemoveRear(&list);
			break;

		/* ������ ����� �����͸� ���*/
		case PRINT_CRNT:
			PrintLnCurrent(&list);
			break;

		/* ������ ��带 ���� */
		case RMV_CRNT:
			RemoveCurrent(&list);
			break;

		/* ��ȣ�� �˻� */
		case SRCH_NO:
			x = ScanMember("�˻�", MEMBER_NO);
			if (search(&list, &x, MemberNoCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("�� ��ȣ�� �����Ͱ� �����ϴ�.");
			break;

		/* �̸����� �˻� */
		case SRCH_NAME:
			x = ScanMember("�˻�", MEMBER_NAME);
			if (search(&list, &x, MemberNameCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("�� �̸��� �����Ͱ� �����ϴ�.");
			break;
		
		/* ��� ����� �����͸� ��� */
		case PRINT_ALL:
			Print(&list);
			break;

		/* ��� ��带 ���� */
		case CLEAR:
			Clear(&list);
			break;
		}
	} while (menu != TERMINATE);
	
	Terminate(&list);               /* ���� ����Ʈ�� ��ó�� */
	
	return 0;
}