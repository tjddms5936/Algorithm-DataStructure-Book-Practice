// int�� ť IntQueue(�ҽ�)
#include <stdio.h>
#include <stdlib.h>
#include "C:\Program Files (x86)\Dev-Cpp\MinGW64\lib\gcc\x86_64-w64-mingw32\4.9.2\include\c++\tr1\IntQueue.h"

// ť �ʱ�ȭ
int Initialize(IntQueue *q, int max){
	q->num = q->front = q->rear = 0;
	if((q->que=calloc(max, sizeof(int)))==NULL){
		q->max = 0; // �迭 ������ ���� 
		return -1;
	}
	q->max = max;
	return 0;
}
// ����
int Enque(IntQueue *q, int x){
	if(q->num >= q->max){
		printf("ť�� ��ȭ �����Դϴ�.");
		return -1; 
	}
	else{
		q->num++; 
		q->que[q->rear++] = x; // �����ϰ� rear ++
		if(q->rear == q->max) {
			q->rear == 0;
		}
		return 0;
	}
} 

// ����
int Deque(IntQueue *q, int *x){
	if(q->num <= 0){
		printf("ť�� �� �����Դϴ�.");
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

// ��ȸ
int Peek(const IntQueue *q, int *x){
	if(q->num <= 0){
		printf("ť�� ����ֽ��ϴ�.");
		return -1; 
	}
	*x = q->que[q->front];
	return 0;
}

// ��� ������ ����
void Clear(IntQueue *q){
	q->num = q->front = q->rear = 0;
} 

// ť�� �ִ� �뷮
int Capacity(const IntQueue *q){
	return q->max;
} 

// ť�� ������ ����
int Size(const IntQueue *q){
	return q->num;
} 

// ť�� ��� �ִ��� ����
int IsEmpty(const IntQueue *q){
	return q->num <= 0;
} 

// ť�� ��ȭ �������� ����
int IsFull(const IntQueue *q){
	return q->num >= q->max;
} 

// ť���� �˻�
int Search(const IntQueue *q, int x){
	int i, idx;
	for(i=0; i<q->num; i++){
		if(q->que[idx = (i + q->front) % q->max] == x){
			return idx; // �ε��� ��ȯ  
		}
	}
	return -1; // �˻� ���� 
} 

// ��� ������ ��� 
void Print(const IntQueue *q){
	int i;
	for(i=0; i<q->num; i++){
		printf("%d, ", q->que[(i + q->front)] % q->max);
	}
	printf("\n");
} 

// ť�� ����
void Terminate(IntQueue *q){
	if(q->que != NULL){
		free(q->que); // �޸� ������ �Ҵ��� �迭 ���� 
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
		printf("���� ������ �� : %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)ENQUE (2)DEQUE (3)PEEK (4)PRINT (5)Search (6)Clear (7)IsEmpty|IsFull (8)Search2 (0)TERMINATE :"); scanf("%d", &m);
		
		if(m == 0){
			break;
		}
		switch(m){
		case 1 : // ���� 
			printf("���� ������ �Է� :"); scanf("%d", &x);
			if(Enque(&que, x) == -1){
				printf("\a���� : ��ť�� �����Ͽ����ϴ�.");
			}
			break;
		case 2 : // ���� 
			if(Deque(&que, &x) == -1){
				printf("\a���� : ��ť�� �����Ͽ����ϴ�.");
			}
			else{
				printf("��ť�� �����ʹ� %d�Դϴ�.", x);
			}
			break;
		case 3 : // ��ȸ 
			if(Peek(&que, &x) == -1){
				printf("\a���� : ��ũ�� �����Ͽ����ϴ�.");
			}
			else{
				printf("��ũ�� �����ʹ� %d�Դϴ�.", x);
			}
			break;
		case 4 : // ��� 
			Print(&que);
			break;
		case 5 : // Search
			printf("�˻� �� :"); scanf("%d", &y);
			if(Search(&que, y) == -1){
				printf("\a���� : �˻��� �����߽��ϴ�.");
			}
			else{
				printf("%d�� q[%d]�� �ֽ��ϴ�.", y, Search(&que, y));
			}
			break;
		case 6 : // Clear
			Clear(&que);
			break;
		case 7 : // IsEmpty , IsFull
			printf("%s\n", IsEmpty(&que) ? "ť�� ����ֽ��ϴ�." : "ť�� ������� �ʽ��ϴ�.");
			printf("%s\n", IsFull(&que) ? "ť�� ��ȭ�����Դϴ�." : "ť�� ��ȭ ���°� �ƴմϴ�.");
			break;
		case 8 : // Search2
			printf("�˻� �� :"); scanf("%d", &y2);
			if(Search2(&que, y2) == -1){
				printf("�˻��� �����߽��ϴ�."); 
			}
			else{
				printf("%d�� �� ���� ��ҷκ��� ���� %d��ŭ ������ �ֽ��ϴ�.", y2, Search(&que, y2));
			}
			break;
		}
	}
	
	return 0;
}
