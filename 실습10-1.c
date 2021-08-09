// ���� �˻�Ʈ�� ���α׷�(���)
#ifndef ___BinTree
#define ___BinTree

#include "Member.h"
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
typedef struct __bnode
{
    Member data; // ������
    struct __bnode *left; // ���� �ڽ� ��忡 ���� ������
    struct __bnode *right; // ������ �ڽ� ��忡 ���� ������
}BinNode;

// �˻�
BinNode *Search(BinNode *p, const Member *x);

// ��� ����
BinNode *Add(BinNode *p, const Member *x);

// ��� ����
int Remove(BinNode **root, const Member *x);

// ��� ��带 ��� 
void PrintTree(const BinNode *p);

// ��� ��带 ����
void FreeTree(BinNode *p);
#endif
