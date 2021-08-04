// Ŀ���� ���� ���� ����Ʈ(���)
#ifndef ___ArrayLinkedList
#define ___ArrayLinkedList
#include <stdio.h>
#include <string.h>
#include "Member.h"

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

typedef int Index; // Ŀ���� �ڷ���

// ���
typedef struct 
{
    Member data; // ������
    Index next; // ���� ���
    Index Dnext; // ���� ����Ʈ�� ���� ��� 
}Node;

// ���� ����Ʈ
typedef struct 
{
    Node *n; // ����Ʈ ��ü(�迭)
    Index head; // �Ӹ� ���
    Index max; // ������� ���� ���ڵ�
    Index deleted; // ���� ����Ʈ�� �Ӹ� ���
    Index crnt; // ������ ��� 
}List;

// ���� ����Ʈ�� �ʱ�ȭ(���� ū ��� ������ size)
void Initialize(List *list, int size);

// �Լ� compare�� x�� ���� ��带 �˻�
Index search(List *list, const Member *x, int compare(const Member *x, const Member *y));

// �Ӹ��� ��带 ���� 
void InsertFront(List *list, const Member *x);

// ������ ��带 ����
void InsertRear(List *list, const Member *x);

// �Ӹ� ��带 ����
void RemoveFront(List *list);

// ���� ��带 ����
void RemoveRear(List *list);

// ������ ��带 ����
void RemoveCurrent(List *list);

// ��� ��带 ����
void Clear(List *list);

// ������ ����� �����͸� ���
void PrintCurrent(const List *list);

// ��� ����� �����͸� ��� 
void Print(const List *list);

// ���� ����Ʈ ����
void Terminate(List *list);
#endif
