// 원형 이중 연결 리스트(소스)
#include <stdio.h>
#include <stdlib.h>
#include "07_CircDblLinkedList.h"
#include "Member.h"

// 1개의 노드를 동적으로 생성
static Dnode *AllocDNode(void){
    return calloc(1, sizeof(Dnode));
}

// 노드의 각 멤버 값을 설정
static void SetNode(Dnode *n, const Member *x, const Dnode *prev, const Dnode *next){
    n->data = *x; // 데이터
    n->prev = prev; // 앞쪽 노드에 대한 포인터
    n->next = next; // 다음 노드에 대한 포인터
}

// 리스트가 비어있는지 검사
static int IsEmpty(const Dlist *list){
    return list->head->next == list->head;
}

// 리스트를 초기화
void Initialize(Dlist *list){
    Dnode *dummyNode = AllocDNode();
    list->head = list->crnt = dummyNode;
    dummyNode->prev = dummyNode->next = dummyNode; 
}

// 선택한 노드의 데이터를 출력
void PrintCurrent(const Dlist *list){
    if(IsEmpty(list)){
        printf("선택한 노드가 없습니다.");
    }
    else{
        PrintMember(&list->crnt->data);
    }
}

// 선택한 노드의 데이터를 출력(줄 바꿈 문자 추가)
void PrintLnCurrent(const Dlist *list){
    PrintCurrent(list);
    printf("\n");
}

// compare함수로 x와 일치하는 노드를 검색
Dnode *Search(Dlist *list, const Member *x, int compare(const Member *x, const Member *y)){
    /*
    더미 노드를 가리키는 포인터 : list -> head
    머리 노드를 가리키는 포인터 : list -> head -> next
    꼬리 노드를 가리키는 포인터 : list -> head -> prev
    */
    Dnode *ptr = list->head->next; // 검색의 시작은 list->head가 가리키는 더미노드가 아닌 그 다음노드 부터 검색
    while (ptr != list->head) // 노드가 1개뿐이거나, 꼬리노드일때까지 
    {
        if(compare(&ptr->data, x) == 0){
            // compare 함수로 비교한 결과가 0이면 검색 성공 
            list->crnt = ptr;
            return ptr; // 현재 노드 검색 완료
        }
        ptr = ptr->next; // 다음 노드로 검색
    }
    return NULL; // 검색 실패 
}

// 모든 노드의 데이터를 리스트 순서대로 출력
void Print(const Dlist *list){
    if(IsEmpty(list)){
        printf("노드가 없습니다.");
    }
    else{
        Dnode *ptr = list->head->next; // ptr은 머리 노드임! 
        printf("---모두 보기---");
        while (ptr != list->head) // ptr이 꼬리노드일 때 까지!
        {
            PrintLnMember(&ptr->data);
            ptr = ptr->next; // 다음 노드 선택 
        }
        
    }
}

// 모든 노드의 데이터를 리스트 순서의 역순으로 출력 
void PrintReverse(const Dlist *list){
    if(IsEmpty(list)){
        printf("노드가 없습니다.");
    }
    else{
        Dnode *ptr = list->head->prev; // 꼬리 노드부터 !! 
        while (ptr != list->head)
        {
            PrintLnMember(&ptr->data);
            ptr = ptr->prev; // 앞쪽 노드 검색! 
        }
        
    }
}

// 선택한 노드를 다음으로 진행
int Next(Dlist *list){
    if(IsEmpty(list) || list->crnt->next == list->head){
        // 리스트가 비어있거나 || 선택한 노드의 다음 노드가 더미노드일 경우 진행할 수 없음
        return 0;
    }
    list->crnt = list->crnt->next; // 선택한 노드를 다음노드로 초기화 
    return 1;
}

// 선택한 노드를 앞쪽으로 진행
int Prev(Dlist *list){
    if(IsEmpty(list) || list->crnt->prev == list->head){
        // 리스트가 비어있거나 || 선택한 노드의 앞쪽 노드가 더미노드일 경우 되돌아 갈 수 없음
        return 0;
    }
    list->crnt = list->crnt->prev; // 선택한 노드를 앞쪽노드로 초기화 
    return 1;
}

// p가 가리키는 노드 바로 다음 노드를 삽입
void InsertAfter(Dlist *list, Dnode *p, const Member *x){
    Dnode *ptr = AllocDNode();
    Dnode *nxt = p->next;
    p->next = p->next->prev = ptr; // 엥
    SetNode(ptr, x, p, nxt);
    list->crnt = ptr; // 삽입한 노드를 선택  
}

// 머리에 노드를 삽입 
void InsertFront(Dlist *list, const Member *x){
    InsertAfter(list, list->head, x);
}

// 꼬리에 노드를 삽입 
void InsertRear(Dlist *list, const Member *x){
    InsertAfter(list, list->head->prev, x);
}

// p가 가리키는 노드를 삭제
void Remove(Dlist *list, Dnode *p){
    p->prev->next = p->next;
    p->next->prev = p->prev;
    list->crnt = p->prev; // 삭제한 노드의 앞쪽 노드를 선택
    free(p);
    if(list->crnt == list->head){
        // 업데이트된 선택된 노드가 더미노드를 가리키고 있다면 
        list->crnt = list->head->next; // 선택된 노드를 머리 노드로 업데이트 ! 
        /* 즉 이 경우가 발동되는 경우는 
        더미노드 - (머리노드)p노드 - 다음노드 일 경우
        p가 삭제되면서
        더미노드(선택된 노드) - 다음노드 가 되고  선택된 노드를 업데이트 해줌으로써
        더미노드 - (선택된 노드)다음노드 로 만들어 준거 임 
        */
    }
}

// 머리 노드를 삭제
void RemoveFront(Dlist *list){
    if(!IsEmpty(list)){
        // 비어있는게 아니면 ! 
        Remove(list, list->head->next); // 머리노드 삭제
    }
}

// 꼬리 노드를 삭제
void RemoveRear(Dlist *list){
    if(!IsEmpty(list)){
        Remove(list, list->head->prev);
    }
}

// 선택한 노드를 삭제
void RemoveCurrent(Dlist *list){
    if(list->crnt != list->head){
        // 선택한 노드가 더미노드가 아니면
        Remove(list, list->crnt);
    }
}

// 모든 노드를 삭제
void Clear(Dlist *list){
    while (!IsEmpty(list))
    {
        RemoveFront(list); // 텅 빌 때까지 머리노드 삭제 
    }
    
}

// 원형 이중 연결 리스트 종료
void Terminate(Dlist *list){
    Clear(list); // 모든 노드를 삭제  하고나면 더미 노드만 남음
    free(list->head); // 더미 노드를 삭제 
}
