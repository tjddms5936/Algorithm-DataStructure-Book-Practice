#include <stdio.h>
#include <stdlib.h>
/*
void bin_insertion(int a[], int n){
    int i, j;
    for(i=1; i<n; i++){
        int key = a[i];
        int pl = 0; // ������ ù �ε���
        int pr = i - 1; // ������ ������ �ε���
        int pc; // ������ ��� �ε���
        int pd; // �����ϴ� ��ġ�� �ε���  
        do{
            pc = (pl + pr) / 2;
            if(a[pc] == key){
                break;
            }
            else if(a[pc] < key){
                pl = pc+1;
            }
            else{
                pr = pc-1;
            }
        }while(pl <= pr);
        pd = (pl <= pr) ? pc+1 : pr+1;

        for(j=i; j>pd; j--){
            a[j] = a[j-1];
        }
        a[pd] = key;
    }
}

int main(void){
    int i, nx;
    int *x;
    printf("Number of Elements :"); scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for(i=0; i<nx; i++){
        printf("x[%d] : ", i); scanf("%d", &x[i]);
    }
    bin_insertion(x, nx);
    printf("Finish the insertion\n");
    for(i=0; i<nx; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }
    free(x);
    return 0;
}
*/
void bin_insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		int key = a[i];
		int pl = 0;		/* �˻� ������ ù �ε��� */
		int pr = i - 1;	/* �˻� ������ �� �ε��� */
		int pc;			/* �˻� ������ ��� �ε��� */
		int pd;			/* �����ϴ� ��ġ�� �ε��� */

		do {
			pc = (pl + pr) / 2;
			if (a[pc] == key)		/* �˻� ���� */
				break;
			else if (a[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);
		pd = (pl <= pr) ? pc + 1 : pr + 1;

		for (j = i; j > pd; j--)
			a[j] = a[j - 1];
		a[pd] = key;
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