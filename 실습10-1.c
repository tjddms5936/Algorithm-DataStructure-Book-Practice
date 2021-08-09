// 이진 검색트리 프로그램(헤더)
#ifndef ___BinTree
#define ___BinTree

#include "Member.h"
#include <stdio.h>
#include <string.h>
/*--- 회원 번호 비교 함수 ---*/
int MemberNoCmp(const Member *x, const Member *y)
{
	return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

/*--- 회원 이름 비교 함수 ---*/
int MemberNameCmp(const Member *x, const Member *y)
{
	return strcmp(x->name, y->name);
}

/*--- 회원 데이터(번호와 이름)를 표시(줄 바꿈 없음) ---*/
void PrintMember(const Member *x)
{
	printf("%d %s", x->no, x->name);
}

/*--- 회원 데이터(번호와 이름)를 표시(줄 바꿈 있음) ---*/
void PrintLnMember(const Member *x)
{
	printf("%d %s\n", x->no, x->name);
}

/*--- 회원 데이터(번호와 이름)를 읽어 들임 ---*/
Member ScanMember(const char *message, int sw)
{
	Member temp;
	printf("%s하는 데이터를 입력하세요.\n", message);
	if (sw & MEMBER_NO) { printf("번호 : "); scanf("%d", &temp.no); }
	if (sw & MEMBER_NAME) { printf("이름 : "); scanf("%s", temp.name); }
	return temp;
}

// 노드 
typedef struct __bnode
{
    Member data; // 데이터
    struct __bnode *left; // 왼쪽 자식 노드에 대한 포인터
    struct __bnode *right; // 오른쪽 자식 노드에 대한 포인터
}BinNode;

// 검색
BinNode *Search(BinNode *p, const Member *x);

// 노드 삽입
BinNode *Add(BinNode *p, const Member *x);

// 노드 삭제
int Remove(BinNode **root, const Member *x);

// 모든 노드를 출력 
void PrintTree(const BinNode *p);

// 모든 노드를 삭제
void FreeTree(BinNode *p);
#endif
