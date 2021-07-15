/*
Q&A 6-3 : ¹öºí Á¤·Ä(¹öÀü2)ÀÇ ¾ÆÀÌµğ¾î´Â ¹è¿­ÀÌ Á¤·ÄÀ» ¸¶ÃÆ´ÂÁö¸¦ °Ë»çÇÏ´Â µ¥ ÀÀ¿ë °¡´É. 
Àü´Ş¹ŞÀº ¹è¿­ a°¡ ¿À¸§Â÷¼øÀ¸·Î Á¤·ÄÀ» ¸¶ÃÆ´ÂÁö °Ë»çÇÏ´Â ÇÔ¼ö¸¦ ÀÛ¼ºÇÏ¼¼¿ä.
ÀÌ¶§ ¿À¸§Â÷¼øÀ¸·Î Á¤·ÄÀ» ¸¶Ä£ »óÅÂ¶ó¸é 1, ±×·¸Áö ¾ÊÀ¸¸é 0À» ¹İÈ¯ÇÏµµ·Ï ÀÛ¼ºÇÏ¼¼¿ä. 
*/
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)
int is_sorted(int a[], int n)
{
	int i;

	for (i = n - 1; i > 0; i--)
		if (a[i - 1] > a[i])
			return 0;
	return 1;
}

int main(void)
{
	int i, nx, sorted;
	int *x;		

	printf("¿ä¼Ò °³¼ö: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	sorted = is_sorted(x, nx);		/* ë°°ì—´ xê°€ ì •ë ¬ë˜ì—ˆëŠ”ì§€ í™•ì¸ */

	if (sorted)
		puts("Á¤·ÄÀ» ¸¶ÃÆ½À´Ï´Ù..");
	else
		puts("Á¤·ÄÀÌ ³¡³ªÁö ¾Ê¾Ò½À´Ï´Ù..");

	free(x);	

	return 0;
}
