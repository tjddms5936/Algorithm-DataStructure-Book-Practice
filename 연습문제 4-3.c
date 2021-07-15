#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int max;
	int num;
	int rear, front;
	int *que;
}IntQueue;

/*--- ť �ʱ�ȭ---*/
int Initialize(IntQueue *q, int max)
{
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;							/* 배열 생성에 실패 */
		return -1;
	}
	q->max = max;
	return 0;
}

/*--- ť ���� ---*/
int Enque(IntQueue *q, int x)
{
	if (q->num >= q->max)
		return -1;							/* ť�� ��ȭ �����̸�*/
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)
			q->rear = 0;
		return 0;
	}
}

/*--- ť ��ť ---*/
int Deque(IntQueue *q, int *x)
{
	if (q->num <= 0)						/* ť�� ��������� */
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
		return 0;
	}
}

/*--- ť ��ȸ ---*/
int Peek(const IntQueue *q, int *x)
{
	if (q->num <= 0)						/* ť�� ���������*/
		return -1;
	*x = q->que[q->front];
	return 0;
}

/*--- ť Ŭ���� ---*/
void Clear(IntQueue *q)
{
	q->num = q->front = q->rear = 0;
}

/*--- ť �뷮 ---*/
int Capacity(const IntQueue *q)
{
	return q->max;
}

/*--- ť ũ�� ---*/
int Size(const IntQueue *q)
{
	return q->num;
}

/*--- ť ���? ---*/
int IsEmpty(const IntQueue *q)
{
	return q->num <= 0;
}

/*--- ť ��ȭ�? ---*/
int IsFull(const IntQueue *q)
{
	return q->num >= q->max;
}

/*--- �˻�---*/
int Search(const IntQueue *q, int x)
{
	int i, idx;

	for (i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;		/* 검색 성공 */
	}
	return -1;				/* 검색 실패 */
}

/*--- ť ��� ---*/
void Print(const IntQueue *q)
{
	int i;

	for (i = 0; i < q->num; i++)
		printf("%d ", q->que[(i + q->front) % q->max]);
	printf("\n");
}

/*--- ť ���� ---*/
void Terminate(IntQueue *q)
{
	if (q->que != NULL)
		free(q->que);		/* 메모리에 할당한 배열 해제 */
	q->max = q->num = q->front = q->rear = 0;
}

int main(void){
	return 0;
}
 
