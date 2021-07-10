#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int max;
	int num;
	int rear, front;
	int *que;
}IntQueue;

/*--- Å¥ ÃÊ±âÈ­---*/
int Initialize(IntQueue *q, int max)
{
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;							/* ë°°ì—´ ìƒì„±ì— ì‹¤íŒ¨ */
		return -1;
	}
	q->max = max;
	return 0;
}

/*--- Å¥ »ðÀÔ ---*/
int Enque(IntQueue *q, int x)
{
	if (q->num >= q->max)
		return -1;							/* Å¥°¡ Æ÷È­ »óÅÂÀÌ¸é*/
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)
			q->rear = 0;
		return 0;
	}
}

/*--- Å¥ µðÅ¥ ---*/
int Deque(IntQueue *q, int *x)
{
	if (q->num <= 0)						/* Å¥°¡ ºñ¾îÀÖÀ¸¸é */
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
		return 0;
	}
}

/*--- Å¥ Á¶È¸ ---*/
int Peek(const IntQueue *q, int *x)
{
	if (q->num <= 0)						/* Å¥°¡ ºñ¾îÀÖÀ¸¸é*/
		return -1;
	*x = q->que[q->front];
	return 0;
}

/*--- Å¥ Å¬¸®¾î ---*/
void Clear(IntQueue *q)
{
	q->num = q->front = q->rear = 0;
}

/*--- Å¥ ¿ë·® ---*/
int Capacity(const IntQueue *q)
{
	return q->max;
}

/*--- Å¥ Å©±â ---*/
int Size(const IntQueue *q)
{
	return q->num;
}

/*--- Å¥ ºñ¾î”? ---*/
int IsEmpty(const IntQueue *q)
{
	return q->num <= 0;
}

/*--- Å¥ Æ÷È­”? ---*/
int IsFull(const IntQueue *q)
{
	return q->num >= q->max;
}

/*--- °Ë»ö---*/
int Search(const IntQueue *q, int x)
{
	int i, idx;

	for (i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;		/* ê²€ìƒ‰ ì„±ê³µ */
	}
	return -1;				/* ê²€ìƒ‰ ì‹¤íŒ¨ */
}

/*--- Å¥ Ãâ·Â ---*/
void Print(const IntQueue *q)
{
	int i;

	for (i = 0; i < q->num; i++)
		printf("%d ", q->que[(i + q->front) % q->max]);
	printf("\n");
}

/*--- Å¥ Á¾·á ---*/
void Terminate(IntQueue *q)
{
	if (q->que != NULL)
		free(q->que);		/* ë©”ëª¨ë¦¬ì— í• ë‹¹í•œ ë°°ì—´ í•´ì œ */
	q->max = q->num = q->front = q->rear = 0;
}

int main(void){
	return 0;
}
 
