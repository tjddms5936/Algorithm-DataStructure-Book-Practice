// ���� ����(����2)�� �������� Q2(204��)ó�� �񱳤� ��ȯ ������ �ڼ��� ����ϴ� ���α׷����� �����ϤĿ�.

// ���� ����(����2 : ��ȯ Ƚ���� ���� ���� �۾��� ����ϴ�. 
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
		int exchg = 0; // �н����� �õ��� ��ȯ Ƚ��
		for(j=n-1; j>i; j--){
			if(a[j-1]>a[j]){
				print(a, n);
				sw[j-1] = 1;
				swap(int, a[j-1], a[j]);
				exchg ++;
				trade ++;
			}
			else{
				sw[j-1] = 2;
				print(a, n);
			}
			compare ++;
			sw[j-1] = 0;
		}
		print(a, n);
		printf("\n");
		if(exchg == 0) break; // ��ȯ�� ������� �ʾҴٸ� ������ ����ϴ�.  
	}
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
