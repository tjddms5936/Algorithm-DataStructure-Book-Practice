#ifndef ___IntStack
#define ___IntStack // int형 스택 intstack(헤더)

// 스택을 구현하는 구조체
typedef struct {
    int max; // 스택 용량
    int ptr; // 스택 포인터
    int *stk; // 스택의 첫 요소에 대한 포인터
}IntStack;

// 스택 초기화
int Initialize(IntStack *s, int max);

// push
int Push(IntStack *s, int x);
// pop
int Pop(IntStack *s, int *x);
// peek
int Peek(const IntStack *s, int *x);
// 스택 비우기
int Clear(IntStack *s);
// 스택의 최대 용량
int Caoacity(const IntStack *s);
// 스택의 데이터 개수
int Size(const IntStack *s);
// 스택이 비어 있나요?
int IsEmpty(const IntStack *s);
// 스택이 가득 찼나요?
int IsFull(const IntStack *s);
// 스택에서 검색
int Search(const IntStack *s);
// 모든 데이터 출력
void Print(const IntStack *s);
// 스택 종료
void Terminate(IntStack *s);



