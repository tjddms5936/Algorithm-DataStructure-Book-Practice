// int형 스택 intStack의 사용
#include <stdio.h>

// 스택을 구현하는 구조체
typedef struct {
    int max; // 스택 용량
    int ptr; // 스택 포인터
    int *stk; // 스택의 첫 요소에 대한 포인터
}IntStack;

// 스택 초기화
int Initialize(IntStack *s, int max){
    s->ptr = 0;
    if((s->stk = calloc(max, sizeof(int))) == NULL){
        s->max = 0; // 배열의 생성에 실패
        return -1;
    }
    s->max = max;
    return 0;
}

// 스택에 데이터를 푸시
int Push(IntStack *s, int x){
    if(s->ptr >= s->max){
        // 스택이 가득 참
        printf("스택이 가득 차있습니다.");
        return -1;
    }
    s->stk[s->ptr++] = x; // ptr포인터에 x넣고 ptr 1 + 
    return 0;
}

// 팝
int Pop(IntStack *s, int *x){
    if(s->ptr <= 0){
        printf("스택이 비어있습니다.");
        return -1;
    }
    *x = s->stk[--s->ptr]; // ptr하나 줄인 상태에서 x = s->ptr의 값으로 지정 
    return 0;
}

// 피크
int Peek(const IntStack *s, int *x){
    if(s->ptr <= 0 ){
        printf("스택이 비어있습니다.");
        return -1;
    }
    *x = s->stk[s->ptr -1]; // ptr을 하나 줄이는게 아님. 조회만 하는거라. 현재 ptr-1을 해서 보기만 함
    return 0;
}

// 비우기
int Clear(IntStack *s){
    s->ptr = 0;
} /* 스택에 대한 푸시와 팝 등 모든 작업은 스택 포인터를 바탕으로 이루어집니다. 따라서 스택의 배열 요솟값을 변경할
필요가 없습니다. 모든 요소의 삭제는 스택 포인터 ptr값을 0으로 하면 끝납니다.
*/

// 스택 용량
int Capacity(const IntStack *s){
    return s->max;
}

// 스택에 쌓여있는 데이터 수
int Size(const IntStack *s){
    return s->ptr;
}

// 스택이 비어있는가?
int IsEmpty(const IntStack *s){
    return s->ptr <= 0;
}
// 가득차있는가?
int IsFull(const IntStack *s){
    return s->ptr >= s->max;
}

// 스택에서 검색
int Search(const IntStack *s, int x){
    int i;
    for(i=s->ptr-1; i >=0; i--){ // top -> bottom으로 선형 검색 
        if(s->stk[i] == x){
            return i; // 검색 성공
        }
    }
    return -1; // 검색 실패
}

// 모든 데이터 출력
void Print(const IntStack *s){
    int i;
    for(i=0; i<s->ptr; i++){ // bottom -> top으로 스캔
        printf("%d ", s->stk[i]);
    }
    printf("\n");
}

// 스택 종료 
void Terminate(IntStack *s){
    if(s->stk != NULL){
        free(s->stk); // 배열에 값이 있다면 배열 해제
    }
    s->max = s->ptr = 0; // 배열의 크기, 인덱스 = 0 으로 초기화 
}


int main(void){
    IntStack s;
    if(Initialize(&s, 64) == -1){
        puts("스택 생성에 실패하였습니다.");
        return 1;
    }    
    while(1){
        int menu, x;
        printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s)); 
        printf("(1)PUSH (2)POP (3)PEEK (4)PRINT (0)TERMINATE :"); scanf("%d", &menu);
    if(menu == 0){
        break;
    }
    switch (menu){
    case 1 : // push
        printf("데이터 :"); scanf("%d", &x);
        if(Push(&s, x) == -1){
            printf("PUSH에 실패했습니다.");
        }
        break;
    case 2 : // pop
        if(Pop(&s, &x) == -1){
            printf("POP에 실패했습니다.");
        }
        else{
            printf("POP데이터는 %d 입니다.", x);
        }
        break;
    case 3 : // peek
        if(Peek(&s, &x) == -1){
            printf("PEEK에 실패했습니다.");
        }
        else{
            printf("PEEK데이터는 %d입니다.", x);
        }
        break;
    case 4 : // print
        Print(&s);
        break;
    }
	}
    Terminate(&s);
    return 0;

}
