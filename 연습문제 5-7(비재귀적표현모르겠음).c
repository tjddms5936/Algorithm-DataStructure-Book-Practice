// Q&A 5-7 : �ǽ� 5-6�� MOVE�Լ��� ����������� �����ϼ���.

// �ϳ����� ž

#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int max;		/* ���� �뷮 */
	int ptr;		/* ���� ������ */
	int *stk;		/* ������ ù ��ҿ� ���� ������ */
} IntStack;

int Initialize(IntStack *s, int max)
{
	s->ptr = 0;
	if ((s->stk = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;							
		return -1;
	}
	s->max = max;
	return 0;
}

int Push(IntStack *s, int x)
{
	if (s->ptr >= s->max)					
		return -1;
	s->stk[s->ptr++] = x;
	return 0;
}

/*--- 스택에서 데이터를 팝 ---*/
int Pop(IntStack *s, int *x)
{
	if (s->ptr <= 0)							/* 스택이 비어 있음 */
		return -1;
	*x = s->stk[--s->ptr];
	return 0;
}

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const IntStack *s, int *x)
{
	if (s->ptr <= 0)							/* 스택이 비어 있음 */
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

/*--- 스택 비우기 ---*/
void Clear(IntStack *s)
{
	s->ptr = 0;
}

/*--- 스택 용량 ---*/
int Capacity(const IntStack *s)
{
	return s->max;
}

/*--- 스택에 쌓여 있는 데이터 수 ---*/
int Size(const IntStack *s)
{
	return s->ptr;
}

/*--- 스택이 비어 있는가? ---*/
int IsEmpty(const IntStack *s)
{
	return s->ptr <= 0;
}

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntStack *s)
{
	return s->ptr >= s->max;
}

/*--- 스택에서 검색 ---*/
int Search(const IntStack *s, int x)
{
	int i;

	for (i = s->ptr - 1; i >= 0; i--)	/* 꼭대기(top) → 바닥(bottom)으로 선형 검색 */
		if (s->stk[i] == x)
			return i;		/* 검색 성공 */
	return -1;				/* 검색 실패 */
}

/*--- 모든 데이터 표시 ---*/
void Print(const IntStack *s)
{
	int i;

	for (i = 0; i < s->ptr; i++)		/* 바닥(bottom) → 꼭대기(top)로 스캔 */
		printf("%d ", s->stk[i]);
	putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(IntStack *s)
{
	if (s->stk != NULL)
		free(s->stk);		/* 배열을 삭제 */
	s->max = s->ptr = 0;
}

/*--- 원반[1] ~ 원반[no]을 x 기둥에서 y 기둥으로 이동 ---*/
void move(int no, int x, int y)
{
	int sw = 0;
	IntStack xstk, ystk, sstk;		/* 스택 */

	Initialize(&xstk, 100);
	Initialize(&ystk, 100);
	Initialize(&sstk, 100);

	while (1) {
		if (sw == 0 && no > 1) {
			Push(&xstk, x);				/* x 값을 푸시 */
			Push(&ystk, y);				/* y 값을 푸시 */
			Push(&sstk, sw);			/* sw 값을 푸시 */
			no = no - 1;
			y = 6 - x - y;
			continue;
		}

		printf("원반[%d]를 %d 기둥에서 %d 기둥으로 이동\n", no, x, y);

		if (sw == 1 && no > 1) {
			Push(&xstk, x);				/* x 값을 푸시 */
			Push(&ystk, y);				/* y 값을 푸시 */
			Push(&sstk, sw);			/* sw 값을 푸시 */
			no = no - 1;
			x = 6 - x - y;
			if (++sw == 2) sw = 0;
			continue;
		}
		do {
			if (IsEmpty(&xstk))			/* 스택이 비어있는 상태라면 */
				return;
			Pop(&xstk, &x);				/* x를 팝 */
			Pop(&ystk, &y);				/* y를 팝 */
			Pop(&sstk, &sw);			/* sw를 팝 */
			sw++;
			no++;
		} while (sw == 2);
	}

	Terminate(&xstk);
	Terminate(&ystk);
	Terminate(&sstk);
}

int main(void){
	int n; // ������ ����
	printf("�ϳ����� ž\n���� ���� :"); scanf("%d", &n);
	move(n, 1, 3); 
	return 0;
}  
