// 원형 이중 연결 리스트
#ifndef ___CircDblLinkedList
#define ___CircDblLinkedList
#include "Member.h"

/* 회원 데이터 Memeber(소스부) */
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
typedef struct __node{
    Member data;
    struct __node *prev;
    struct __node *next;
}Dnode;

// 원형 이중 연결 리스트
typedef struct{
    Dnode *head; // 머리의 더미 노드에 대한 포인터
    Dnode *crnt; // 선택한 노드에 대한 포인터
}Dlist;

// 리스트를 초기화
void Initialize(Dlist *list);

// 선택한 노드의 데이터를 출력
void PrintCurrent(const Dlist *list);

// 선택한 노드의 데이터를 출력(줄 바꿈 문제 추가)
void PrintLnCurrent(const Dlist *list);

// compare 함수로 x와 일치하는 노드를 검색
Dnode *Search(Dlist *list, const Member *x, int compare(const Member *x, const Member *y));

// 모든 노드의 데이터를 리스트 순서대로 출력
void Print (const Dlist *list);

// 모든 노드의 데이터를 리스트 순서와 역순으로 출력
void PrintReverse(const Dlist *list);

// 선택한 노드의 다음으로 진행
int Next(Dlist *list);

// 선택한 노드의 앞쪽으로 진행
int Prev(Dlist *list);

// p가 가리키는 노드 바로 뒤에 노드를 삽입
void InsertAfter(Dlist *list, Dnode *p, const Member *x);

// 머리에 노드를 삽입 
void InsertFront(Dlist *list, const Member *x);

// 꼬리에 노드를 삽입
void InsertRear(Dlist *list, const Member *x);

// p가 가리키는 노드를 삭제
void Remove(Dlist *list, Dnode *p);

// 머리 노드를 삭제
void RemoveFront(Dlist *list);

// 꼬리 노드를 삭제
void RemoveRear(Dlist *list);

// 선택한 노드를 삭제
void RemoveCurrent(Dlist *list);

// 모든 노드를 삭제
void Clear(Dlist *list);

// 원형 이중 연결 리스트 종료
void Terminate(Dlist *list);
#endif