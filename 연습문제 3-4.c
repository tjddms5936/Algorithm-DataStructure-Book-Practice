#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key){
	int i, j;
	int pl = 0;
	int pr = n-1;
	int pc;
	printf("  |");
	for(i=0; i<n; i++){
		printf(" %d", i);
	}
	printf("\n");
	printf("--*-----------------\n");
	do{
		pc = (pl + pr) / 2;
		printf("  |<-");
		for(i=0; i<n; i++){
			printf(" ");
			if(i==pc){
				printf(" + ->");
				break;
			}
			printf(" ");
			if(i==n-1){
				printf("  ->");
			}
		}
		printf("\n");
		printf(" %d| ", pc);
		for(i=0; i<n; i++){
			printf("%d  ", a[i]);
		}
		printf("\n");
		printf("  |\n");
		
		if(a[pc] == key){
			// �˻� ����
			return pc; 
		}
		else if(a[pc] < key){
			pl = pc + 1;
		}
		else{
			pr = pc - 1;
		}
		
	}while(pl <= pr);
	return -1;
}

int main(void){
	int i, nx, ky, idx;
	int *x;
	puts("���� �˻�");
	printf("��� ���� :"); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for(i=0; i<nx; i++){
		printf("x[%d] :", i);
		scanf("%d", &x[i]);
	}
	printf("�˻� �� :"); scanf("%d", &ky);
	idx = bin_search(x, nx, ky);
	if(idx == -1){
		printf("�˻��� �����߽��ϴ�.");
	} 
	else{
		printf("%d�� x[%d]�� �ֽ��ϴ�.", ky, idx);
	}
	free(x);
	return 0;
}
