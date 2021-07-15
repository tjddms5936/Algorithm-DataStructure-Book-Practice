#include <stdio.h>
#include <stdlib.h>

int scan(const int a[], int n, int key){
	int i, j;
	printf("  |");
	for(i=0; i<n; i++){
		printf(" %d", i);
	}
	printf("\n");
	printf("--*-----------------\n");
	for(i=0; i<n; i++){
		printf("  |");
		for(j=0; j<n; j++){
			printf(" ");
			if(j==i){
				printf("*\n");
				break;
			}
			printf("  ");
		}
		printf(" %d|", i);
		for(j=0; j<n; j++){
			printf(" %d ", a[j]);
			if(j==i && a[j] == key){
				printf("\n");
				return j;
			}	
		}
		printf("\n");
		printf("  |\n");
		
	}
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
	idx = scan(x, nx, ky);
	if(idx == -1){
		printf("�˻��� �����߽��ϴ�.");
	}
	else{
		printf("%d�� x[%d]�� �ֽ��ϴ�.", ky, idx);
	}
	free(x);
	return 0;
}
