// int형 큐 IntQueue(소스)
#include <stdio.h>
#include <stdlib.h>
#include "C:\Program Files (x86)\Dev-Cpp\MinGW64\lib\gcc\x86_64-w64-mingw32\4.9.2\include\c++\tr1\IntQueue.h"

// 큐 초기화
int Initialize(IntQueue *q, int max){
	q->num = q->front = q->rear = 0;
	if((q->que=calloc(max, sizeof(int)))==NULL){
		q->max = 0; // 배열 생성에 실패 
		return -1;
	}
	q->max = max;
	return 0;
}
// 삽입
int Enque(IntQueue *q, int x){
	if(q->num >= q->max){
		printf("큐가 포화 상태입니다.");
		return -1; 
	}
	else{
		q->num++; 
		q->que[q->rear++] = x; // 삽입하고 rear ++
		if(q->rear == q->max) {
			q->rear == 0;
		}
		return 0;
	}
} 

// 삭제
int Deque(IntQueue *q, int *x){
	if(q->num <= 0){
		printf("큐가 빈 상태입니다.");
		return -1;
	}
	else{
		q->num--;
		*x = q->que[q->front++];
		if(q->front == q->max){
			q->front == 0;
		}
		return 0;
	}
}

// 조회
int Peek(const IntQueue *q, int *x){
	if(q->num <= 0){
		printf("큐가 비어있습니다.");
		return -1; 
	}
	*x = q->que[q->front];
	return 0;
}

// 모든 데이터 삭제
void Clear(IntQueue *q){
	q->num = q->front = q->rear = 0;
} 

// 큐의 최대 용량
int Capacity(const IntQueue *q){
	return q->max;
} 

// 큐의 데이터 개수
int Size(const IntQueue *q){
	return q->num;
} 

// 큐가 비어 있는지 여부
int IsEmpty(const IntQueue *q){
	return q->num <= 0;
} 

// 큐가 포화 상태인지 여부
int IsFull(const IntQueue *q){
	return q->num >= q->max;
} 

// 큐에서 검색
int Search(const IntQueue *q, int x){
	int i, idx;
	for(i=0; i<q->num; i++){
		if(q->que[idx = (i + q->front) % q->max] == x){
			return idx; // 인덱스 반환  
		}
	}
	return -1; // 검색 실패 
} 

// 모든 데이터 출력 
void Print(const IntQueue *q){
	int i;
	for(i=0; i<q->num; i++){
		printf("%d, ", q->que[(i + q->front)] % q->max);
	}
	printf("\n");
} 

// 큐의 종료
void Terminate(IntQueue *q){
	if(q->que != NULL){
		free(q->que); // 메모리 공간에 할당한 배열 해제 
	}
	q->max = q->num = q->front = q->rear = 0;
} 

int Search2(const IntQueue *q, int x){
	int i;
	for(i=0; i<q->num; i++){
		if(q->que[(i + q->front) % q->max] == x){
			return i;
		}
	}
	return -1;
}

int main(void){
	IntQueue que; 
	if(Initialize(&que, 64) == -1){
		return 1;
	}
	while(1){
		int m, x, y, y2;
		printf("현재 데이터 수 : %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)ENQUE (2)DEQUE (3)PEEK (4)PRINT (5)Search (6)Clear (7)IsEmpty|IsFull (8)Search2 (0)TERMINATE :"); scanf("%d", &m);
		
		if(m == 0){
			break;
		}
		switch(m){
		case 1 : // 삽입 
			printf("삽입 데이터 입력 :"); scanf("%d", &x);
			if(Enque(&que, x) == -1){
				printf("\a오류 : 인큐에 실패하였습니다.");
			}
			break;
		case 2 : // 삭제 
			if(Deque(&que, &x) == -1){
				printf("\a오류 : 디큐에 실패하였습니다.");
			}
			else{
				printf("디큐한 데이터는 %d입니다.", x);
			}
			break;
		case 3 : // 조회 
			if(Peek(&que, &x) == -1){
				printf("\a오류 : 피크에 실패하였습니다.");
			}
			else{
				printf("피크한 데이터는 %d입니다.", x);
			}
			break;
		case 4 : // 출력 
			Print(&que);
			break;
		case 5 : // Search
			printf("검색 값 :"); scanf("%d", &y);
			if(Search(&que, y) == -1){
				printf("\a오류 : 검색에 실패했습니다.");
			}
			else{
				printf("%d는 q[%d]에 있습니다.", y, Search(&que, y));
			}
			break;
		case 6 : // Clear
			Clear(&que);
			break;
		case 7 : // IsEmpty , IsFull
			printf("%s\n", IsEmpty(&que) ? "큐가 비어있습니다." : "큐가 비어있지 않습니다.");
			printf("%s\n", IsFull(&que) ? "큐가 포화상태입니다." : "큐가 포화 상태가 아닙니다.");
			break;
		case 8 : // Search2
			printf("검색 값 :"); scanf("%d", &y2);
			if(Search2(&que, y2) == -1){
				printf("검색에 실패했습니다."); 
			}
			else{
				printf("%d는 맨 앞의 요소로부터 현재 %d만큼 떨어져 있습니다.", y2, Search(&que, y2));
			}
			break;
		}
	}
	
	return 0;
}
