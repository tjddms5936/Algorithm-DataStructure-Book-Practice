// Q&A 5-5 : recur3 �Լ��� �ٽ� ����������� �����ϼ��� 
/*
void recur3(int n){
	if(n>0){
		recur3(n-1);
		recur3(n-2);
		printf("%d\n", n);
	}
}
*/ 

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

void recur3(int n)
{
	int sw = 0;
	IntStack nstk, sstk;			/* ���� */

	Initialize(&nstk, 100);
	Initialize(&sstk, 100);

	while (1) {
		if (n > 0) {
			Push(&nstk, n);
			Push(&sstk, sw);

			if (sw == 0)
				n = n - 1;
			else if (sw == 1) {
				n = n - 2;
				sw = 0;
			}
			continue;
		}
		do {
			Pop(&nstk, &n);
			Pop(&sstk, &sw);
			sw++;

			if (sw == 2) {
				printf("%d\n", n);
				if (IsEmpty(&nstk))
					return;
			}
		} while (sw == 2);
	}

	Terminate(&nstk);
	Terminate(&sstk);
}

int main(void)
{
	int x;

	printf("������ �Է��ϼ���. : ");
	scanf("%d", &x);

	recur3(x);

	return 0;
}
