// ���� ����(����2 : ��ȯ Ƚ���� ���� ���� �۾��� ����ϴ�. 
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void bubble(int a[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		int exchg = 0; // �н����� �õ��� ��ȯ Ƚ��
		for(j=n-1; j>i; j--){
			if(a[j-1]>a[j]){
				swap(int, a[j-1], a[j]);
				exchg ++;
			}
		}
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
