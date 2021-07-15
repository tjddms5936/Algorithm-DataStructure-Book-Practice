// Q&A 5-5 : recur3 ÇÔ¼ö¸¦ ´Ù½Ã ºñÀç±ÍÀûÀ¸·Î ±¸ÇöÇÏ¼¼¿ä 
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
	int max;		/* ½ºÅÃ ¿ë·® */
	int ptr;		/* ½ºÅÃ Æ÷ÀÎÅÍ */
	int *stk;		/* ½ºÅÃÀÇ Ã¹ ¿ä¼Ò¿¡ ´ëÇÑ Æ÷ÀÎÅÍ */
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

/*--- ìŠ¤íƒì—ì„œ ë°ì´í„°ë¥¼ íŒ ---*/
int Pop(IntStack *s, int *x)
{
	if (s->ptr <= 0)							/* ìŠ¤íƒì´ ë¹„ì–´ ìˆìŒ */
		return -1;
	*x = s->stk[--s->ptr];
	return 0;
}

/*--- ìŠ¤íƒì—ì„œ ë°ì´í„°ë¥¼ í”¼í¬ ---*/
int Peek(const IntStack *s, int *x)
{
	if (s->ptr <= 0)							/* ìŠ¤íƒì´ ë¹„ì–´ ìˆìŒ */
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

/*--- ìŠ¤íƒ ë¹„ìš°ê¸° ---*/
void Clear(IntStack *s)
{
	s->ptr = 0;
}

/*--- ìŠ¤íƒ ìš©ëŸ‰ ---*/
int Capacity(const IntStack *s)
{
	return s->max;
}

/*--- ìŠ¤íƒì— ìŒ“ì—¬ ìˆëŠ” ë°ì´í„° ìˆ˜ ---*/
int Size(const IntStack *s)
{
	return s->ptr;
}

/*--- ìŠ¤íƒì´ ë¹„ì–´ ìˆëŠ”ê°€? ---*/
int IsEmpty(const IntStack *s)
{
	return s->ptr <= 0;
}

/*--- ìŠ¤íƒì€ ê°€ë“ ì°¼ëŠ”ê°€? ---*/
int IsFull(const IntStack *s)
{
	return s->ptr >= s->max;
}

/*--- ìŠ¤íƒì—ì„œ ê²€ìƒ‰ ---*/
int Search(const IntStack *s, int x)
{
	int i;

	for (i = s->ptr - 1; i >= 0; i--)	/* ê¼­ëŒ€ê¸°(top) â†’ ë°”ë‹¥(bottom)ìœ¼ë¡œ ì„ í˜• ê²€ìƒ‰ */
		if (s->stk[i] == x)
			return i;		/* ê²€ìƒ‰ ì„±ê³µ */
	return -1;				/* ê²€ìƒ‰ ì‹¤íŒ¨ */
}

/*--- ëª¨ë“  ë°ì´í„° í‘œì‹œ ---*/
void Print(const IntStack *s)
{
	int i;

	for (i = 0; i < s->ptr; i++)		/* ë°”ë‹¥(bottom) â†’ ê¼­ëŒ€ê¸°(top)ë¡œ ìŠ¤ìº” */
		printf("%d ", s->stk[i]);
	putchar('\n');
}

/*--- ìŠ¤íƒ ì¢…ë£Œ ---*/
void Terminate(IntStack *s)
{
	if (s->stk != NULL)
		free(s->stk);		/* ë°°ì—´ì„ ì‚­ì œ */
	s->max = s->ptr = 0;
}

void recur3(int n)
{
	int sw = 0;
	IntStack nstk, sstk;			/* ½ºÅÃ */

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

	printf("Á¤¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä. : ");
	scanf("%d", &x);

	recur3(x);

	return 0;
}
