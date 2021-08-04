/* 커서에 의한 선형 리스트의 사용 예 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "ArrayLinkedList.h"


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


// 삽입할 레코드의 인덱스를 구한 다음 반환 
static Index GetIndex(List *list){
    if(list->deleted == NULL){
        // 삭제할 레코드가 없는 경우
        return ++(list->max);
    }
    else{
        Index rec = list->deleted;
        list->deleted = list->n[rec].Dnext;
        return rec;
    }
}

// 지정된 레코드를 삭제 리스트에 등록
static void DeleteIndex(List *list, Index idx){
    if(list->deleted == NULL){
        // 삭제할 레코드가 없는 경우
        list->deleted = idx;
        list->n[idx].Dnext = NULL;
    }
    else{
        Index ptr = list->deleted;
        list->deleted = idx;
        list->n[idx].Dnext = ptr;
    }
}

// n이 가리키는 노드의 각 멤버에 값을 설정
static void SetNode(Node *n, const Member *x, Index next){
    n->data = *x; // 데이터
    n->next = next; // 다음 노드에 대한 포인터
}

// 연결 리스트를 초기화
void Initialize(List *list, int size){
    list->n = calloc(size, sizeof(Node));
    list->head = NULL; // 머리 노드
    list->crnt = NULL; // 선택한 노드
    list->max = NULL; 
    list->deleted = NULL; 
}

// compare 함수로 x와 일치하는 노드 검색
Index search(List *list, const Member *x, int compare(const Member *x, const Member *y)){
    Index ptr = list->head;
    while(ptr != NULL){
        if(compare(&list->n[ptr].data, x) == 0){
            list->crnt = ptr;
            return ptr; // 검색 성공
        }
        ptr = list->n[ptr].next;
    }
    return NULL; // 검색 실패 
}

// 머리에 노드를 삽입
void InsertFront(List *list, const Member *x){
    Index ptr = list->head;
    list->head = list->crnt = GetIndex(list);
    SetNode(&list->n[list->head], x, ptr);
}

// 꼬리에 노드를 삽입
void InsertRear(List *list, const Member *x){
    if(list->head == NULL){
        // 비어 있는 경우
        InsertFront(list, x); // 머리에 삽입
    }
    else{
        Index ptr = list->head;
        while(list->n[ptr].next != NULL){
            ptr = list->n[ptr].next;
            list->n[ptr].next = list->crnt = GetIndex(list);
            SetNode(&list->n[list->n[ptr].next], x, NULL);
        }
    }
}

// 머리 노드를 삭제
void RemoveFront(List *list){
    if(list->head != NULL){
        // 비어 있지 않은 경우
        Index ptr = list->n[list->head].next;
        DeleteIndex(list, list->head);
        list->head = list->crnt = ptr;
    }
}

// 꼬리 노드를 삭제
void RemoveRear(List *list){
    if(list->head != NULL){
        // 비어 있지 않은 경우
        if(list->n[list->head].next == NULL){
            // 노드가 1개만 있다면
            RemoveFront(list); // 머리 노드를 삭제하면 됨. 
        }
        else{
            Index ptr = list->head;
            Index pre;
            while(list->n[ptr].next != NULL){
                // 다음 노드가 있다면 계속 반복하면서 
                pre = ptr; 
                ptr = list->n[ptr].next; 
                // while문이 끝날 때 pre는 꼬리 노드가 됨 ptr = NULL이 됨
            }
            list->n[pre].next = NULL; // 꼬리 노드의 next 포인터는 NULL로 초기화
            DeleteIndex(list, ptr); // 삭제 리스트에 NULL 삽입?;;
            list->crnt = pre; 
        }
    }
}

// 선택한 노드를 삭제
void RemoveCurrent(List *list){
    if(list->crnt == list->head){
        // 머리 노드가 선택되어 있으면
        RemoveFront(list); // 머리 노드를 삭제
    }
    else{
        Index ptr = list->head;
        while(list->n[ptr].next != list->crnt){
            // 머리 노드부터 crnt 노드 직전까지 보면서
            ptr = list->n[ptr].next; // 머리노드부터 하나씩 다음 노드로 초기화
        }
        // while문이 끝날 때 ptr은 선택한 노드의 전 노드 
        list->n[ptr].next = list->n[list->crnt].next; 
        /* 원래는 ptr노드 -> 선택한 노드 -> 다음 노드 순이었는데 선택한 노드 삭제할 거니까
            ptr노드 -> 다음 노드 로 만들기 위한 작업 */
        DeleteIndex(list, list->crnt);
        list->crnt = ptr; 
    }
}

// 모든 노드를 삭제
void Clear(List *list){
    while(list->head != NULL){
        // 텅 빌 때까지
        RemoveFront(list); // 머리 노드를 삭제 
    }
    list->crnt = NULL; 
}

// 선택한 노드의 데이터를 출력 
void PrintCurrent(const List *list){
    if(list->crnt == NULL){
        // 선택한 노드가 없다면
        printf("선택한 노드가 없습니다.");
    }
    else{
        PrintMember(&list->n[list->crnt].data); 
    }
}

// 선택한 노드의 데이터를 출력(줄 바꿈 문자 추가)
void PrintLnCurrent(const List *list){
    PrintCurrent(list);
    printf("\n");
}

// 모든 노드의 데이터를 출력
void Print(const List *list){
    if(list->head == NULL){
        printf("노드가 없습니다.");
    }
    else{
        Index ptr = list->head;
        printf("---모두 보기---");
        while(ptr != NULL){
            // ptr이 꼬리 노드가 될 때 까지
            PrintLnMember(&list->n[ptr].data); // ptr노드 출력하고
            ptr = list->n[ptr].next; // ptr을 다음 노드로 초기화
        }
    }
}

// 연결 리스트 종료
void Terminate(List *list){
    Clear(list); // 일단 모든 노드를 삭제하고
    free(list->n); // 해제시킴
}




/*--- 메뉴 ---*/
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
	RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu;

/*--- 메뉴 선택 ---*/
Menu SelectMenu(void)
{
	int i, ch;
	char *mstring[] = {
		"머리에 노드를 삽입",    "말미에 노드를 삽입",    "머리노드를 삭제",
		"꼬리노드를 삭제",       "주목노드를 출력",     "주목노드를 삭제",
		"번호로 검색",           "이름으로 검색",         "모든 노드를 출력",
		"모든 노드를 삭제",
	};

	do {
		for (i = TERMINATE; i < CLEAR; i++) {
			printf("(%2d) %-18.18s  ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("( 0) 종료 : ");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > CLEAR);

	return (Menu)ch;
}

/*--- 메인 ---*/
int main(void)
{
	Menu menu;
	List list;
	
	Initialize(&list, 30);              /* 선형 리스트 초기화 */

	do {
		Member x;
		switch (menu = SelectMenu()) {
		
		/* 머리에 노드를 삽입 */
		case INS_FRONT:
			x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertFront(&list, &x);
			break;
		
		/* 말미에 노드를 삽입 */
		case INS_REAR:
			x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;
		
		/* 머리노드를 삭제 */
		case RMV_FRONT:
			RemoveFront(&list);
			break;
		
		/* 꼬리노드를 삭제 */
		case RMV_REAR:
			RemoveRear(&list);
			break;
		
		/* 주목노드의 데이터를 출력 */
		case PRINT_CRNT:
			PrintLnCurrent(&list);
			break;
		
		/* 주목노드를 삭제 */
		case RMV_CRNT:
			RemoveCurrent(&list);
			break;
		
		/* 번호로 검색 */
		case SRCH_NO:
			x = ScanMember("검색", MEMBER_NO);
			if (search(&list, &x, MemberNoCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("그 번호의 데이터가 없습니다.");
			break;
		
		/* 이름으로 검색 */
		case SRCH_NAME:
			x = ScanMember("검색", MEMBER_NAME);
			if (search(&list, &x, MemberNameCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("그 이름의 데이터가 없습니다.");
			break;
		
		/* 모든 노드의 데이터를 출력 */
		case PRINT_ALL:
			Print(&list);
			break;
		
		/* 모든 노드를 삭제 */
		case CLEAR:
			Clear(&list);
			break;
		}
	} while (menu != TERMINATE);
	
	Terminate(&list);                /* 선형 리스트의 뒤처리 */
	
	return 0;
}