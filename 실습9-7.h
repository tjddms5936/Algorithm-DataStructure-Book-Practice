// ���� ���� ���� ����Ʈ
#ifndef ___CircDblLinkedList
#define ___CircDblLinkedList
#include "Member.h"

/* ȸ�� ������ Memeber(�ҽ���) */
#include <stdio.h>
#include <string.h>

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

// ���
typedef struct __node{
    Member data;
    struct __node *prev;
    struct __node *next;
}Dnode;

// ���� ���� ���� ����Ʈ
typedef struct{
    Dnode *head; // �Ӹ��� ���� ��忡 ���� ������
    Dnode *crnt; // ������ ��忡 ���� ������
}Dlist;

// ����Ʈ�� �ʱ�ȭ
void Initialize(Dlist *list);

// ������ ����� �����͸� ���
void PrintCurrent(const Dlist *list);

// ������ ����� �����͸� ���(�� �ٲ� ���� �߰�)
void PrintLnCurrent(const Dlist *list);

// compare �Լ��� x�� ��ġ�ϴ� ��带 �˻�
Dnode *Search(Dlist *list, const Member *x, int compare(const Member *x, const Member *y));

// ��� ����� �����͸� ����Ʈ ������� ���
void Print (const Dlist *list);

// ��� ����� �����͸� ����Ʈ ������ �������� ���
void PrintReverse(const Dlist *list);

// ������ ����� �������� ����
int Next(Dlist *list);

// ������ ����� �������� ����
int Prev(Dlist *list);

// p�� ����Ű�� ��� �ٷ� �ڿ� ��带 ����
void InsertAfter(Dlist *list, Dnode *p, const Member *x);

// �Ӹ��� ��带 ���� 
void InsertFront(Dlist *list, const Member *x);

// ������ ��带 ����
void InsertRear(Dlist *list, const Member *x);

// p�� ����Ű�� ��带 ����
void Remove(Dlist *list, Dnode *p);

// �Ӹ� ��带 ����
void RemoveFront(Dlist *list);

// ���� ��带 ����
void RemoveRear(Dlist *list);

// ������ ��带 ����
void RemoveCurrent(Dlist *list);

// ��� ��带 ����
void Clear(Dlist *list);

// ���� ���� ���� ����Ʈ ����
void Terminate(Dlist *list);
#endif