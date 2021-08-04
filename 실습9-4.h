// 커서로 만든 연결 리스트(헤더)
#ifndef ___ArrayLinkedList
#define ___ArrayLinkedList
#include <stdio.h>
#include <string.h>
#include "Member.h"

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

typedef int Index; // 커서의 자료형

// 노드
typedef struct 
{
    Member data; // 데이터
    Index next; // 다음 노드
    Index Dnext; // 프리 리스트의 다음 노드 
}Node;

// 연결 리스트
typedef struct 
{
    Node *n; // 리스트 본체(배열)
    Index head; // 머리 노드
    Index max; // 사용중인 꼬리 레코드
    Index deleted; // 프리 리스트의 머리 노드
    Index crnt; // 선택한 노드 
}List;

// 연결 리스트를 초기화(가장 큰 요소 개수는 size)
void Initialize(List *list, int size);

// 함수 compare로 x와 같은 노드를 검색
Index search(List *list, const Member *x, int compare(const Member *x, const Member *y));

// 머리에 노드를 삽입 
void InsertFront(List *list, const Member *x);

// 꼬리에 노드를 삽입
void InsertRear(List *list, const Member *x);

// 머리 노드를 삭제
void RemoveFront(List *list);

// 꼬리 노드를 삭제
void RemoveRear(List *list);

// 선택한 노드를 삭제
void RemoveCurrent(List *list);

// 모든 노드를 삭제
void Clear(List *list);

// 선택한 노드의 데이터를 출력
void PrintCurrent(const List *list);

// 모든 노드의 데이터를 출력 
void Print(const List *list);

// 연결 리스트 종료
void Terminate(List *list);
#endif
