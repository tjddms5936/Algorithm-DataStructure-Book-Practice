// 버블 정렬(버전2 : 교환 횟수에 따라 정렬 작업을 멈춥니다. 
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void bubble(int a[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		int exchg = 0; // 패스에서 시도한 교환 횟수
		for(j=n-1; j>i; j--){
			if(a[j-1]>a[j]){
				swap(int, a[j-1], a[j]);
				exchg ++;
			}
		}
		if(exchg == 0) break; // 교환이 수행되지 않았다면 정렬을 멈춥니다.  
	}
} 
int main(void){
	int i, nx;
	int *x;
	printf("요소 개수 :"); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	
	for(i=0; i<nx; i++){
		printf("x[%d] :", i); scanf("%d", &x[i]);
	}
	printf("\n");
	printf("버블 정렬 하였습니다.\n\n");
	bubble(x, nx);
	free(x);
	return 0;
}
