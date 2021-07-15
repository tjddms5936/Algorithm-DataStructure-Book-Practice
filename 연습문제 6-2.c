/*
Q&A 6-2 : ������(å ����) ó�� ��, ��ȯ ������ �ڼ��� ����ϸ鼭 ���������ϴ� ���α׷��� �ۼ��ϼ���
���ϴ� �� ��� ���̿� ��ȯ�� �����ϸ� '+', �������� ������ '-'�� ����ϰ� 
������ ��ġ�� �� Ƚ���� ��ȯ Ƚ���� ����ϼ���. 
*/
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

int sw[100];
int compare = 0;
int trade = 0;
void print(const int b[], int n2){
	int i;
	for(i=0; i<n2; i++){
			if(sw[i]==1){
				printf("%d+", b[i]);
				sw[i]=0;
			}
			else if(sw[i]==2){
				printf("%d-", b[i]);
			}
			else{
				printf("%d ", b[i]);
			}	
	}
	printf("\n");
}

void bubble(int a[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		printf("�н� %d\n", i+1);
		for(j=n-1; j>i; j--){ // ������ ���� ���ϴ� �������� ���� ����
			if(a[j-1] > a[j]){
				sw[j-1] = 1;
				print(a, n);
				swap(int, a[j-1], a[j]);
				trade++;
			}
			else{
				sw[j-1] = 2;
				print(a, n);
			}
			sw[j-1] = 0;
			compare++;
		}
		print(a, n);
		printf("\n");
	}
	printf("\n");
	printf("�񱳸� %dȸ �߽��ϴ�.\n", compare);
	printf("��ȯ�� %dȸ �߽��ϴ�.", trade);
}

int main(void){
	int i, nx;
	int *x;
	printf("��� ���� :"); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	
	for(i=0; i<nx; i++){
		printf("x[%d] :", i); scanf("%d", &x[i]);
	}
	printf("\n");
	printf("���� ���� �Ͽ����ϴ�.\n\n");
	bubble(x, nx);
	free(x);
	return 0;
}
