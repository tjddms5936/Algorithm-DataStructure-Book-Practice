#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[]){
	int i;
	int index = 0;
	for(i=0; i<n; i++){
		if(a[i]==key){
			idx[index] = i;
			index ++;
		}
	}
	for(i=0; i<index; i++){
		printf("idx[%d] = %d\n", i, idx[i]);
	}
	return index;
}

int main(void){
	int i, nx, ky;
	int *x, *idx;
	printf("��� ���� :"); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for(i=0; i<nx; i++){
		printf("x[%d] :", i); scanf("%d", &x[i]);
	}
	printf("�˻� �� :"); scanf("%d", &ky);
	int nx2 = 0;
	for(i=0; i<nx; i++){
		if(x[i] == ky){
			nx2 ++;
		}
	}
	idx = calloc(nx2, sizeof(int));
	printf("��� �� �� %d�� ������ %d�� �Դϴ�.", ky, search_idx(x, nx, ky, idx));
	
	return 0;
}
