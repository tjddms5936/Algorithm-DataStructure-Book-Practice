#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 Q6 : ����� ���� ������������ ���ĵ� long�� �迭������ �˻��� 
 bsearch �Լ��� ����Ͽ� ���α׷��� �ۼ��ϼ���.  
*/

int int_cmp(const int *a, const int *b){
	if(*a > *b){
		return 1;
	}
	else if(*a < *b){
		return -1;
	}
	else{
		return 0;
	}
};

int main(void){
	int i, nx, ky;
	int *x;
	int *p;
	printf("��� ���� :"); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("x[0] : "); scanf("%d", &x[0]);
	for(i=1; i<nx; i++){
		do{
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		}while(x[i] > x[i-1]); // ���������̴ϱ� 
	}
	printf("�˻� �� : "); scanf("%d", &ky);
	p = bsearch(&ky, x, nx, sizeof(long), (int(*)(const void *, const void *))int_cmp);
	if(p == NULL){
		printf("�˻��� �����߽��ϴ�.");
	}
	else{
		printf("�˻��� �����߽��ϴ�.\n");
		printf("%d�� x[%d]�� �ֽ��ϴ�.", ky, (int)(p-x));
	}
	free(x);
}


















