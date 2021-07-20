/* Q11 ���� ���� ����(��� �̵��� memmove �Լ��� ��룩*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*--- ���� ���� ����(��� �̵��� memmove �Լ��� ��룩---*/
void bin_insertion(int a[], int n)
{
	int  i, j;
	// int k;
	for (i = 1; i < n; i++) {
		int key = a[i];
		int pl = 0;		
		int pr = i - 1;	
		int pc;			
		int pd;			

		do {
			pc = (pl + pr) / 2;
			if (a[pc] == key)		
				break;
			else if (a[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);
		pd = (pl <= pr) ? pc + 1 : pr + 1;
//********************************************************************
		memmove(&a[pd + 1], &a[pd], (i - pd) * sizeof(int));
    /* a[pd] �� ��ġ���� i-pd ���� ��ŭ�� ��, a[pd] ~ �ٲٷ��� �ε��� ������ ����
        �� �� a[pd + 1] ���� �ٿ��ֱ���. ���� 5 7 9 4 1 ���� i = 3 �̶��
        key = 4, pr = 2, pc = 1 -> a[pc] = 7 > key -> pr = 0
        pc = 0 a[pc] = 5 > key -> pr = -1 pl <= pr ���� x �ݺ� ���� 
        pd = pr+1 = 0 
        memove �Լ� �ߵ�
        a[pd=0]�������� i-pd = 3 - 0 ���� ��ŭ�� �����ϰ� ��, 3�� �����ϰ� 
        -> 5 7 9 �� �����ϰ� 
        a[pd + 1 = 1] ���� �ٿ��ֱ��ϸ� 5 5 7 9 1 �̵�  memmove �Լ� ��! 
    */
//********************************************************************
		a[pd] = key; // << �� ���� 5�� key=4�� �ٲ��ָ鼭 ���������� 
        // 4 5 7 9 1 �� ��!!! 
	}
}

int main(void)
{
	int i, nx;
	int *x;		

	puts("���� ���� ����");
	printf("��ڼ� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bin_insertion(x, nx);		

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	

	return 0;
}