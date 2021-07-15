/*
Q&A 6-1 : 버블 정렬의 각 패스에서 비교, 교환은 처음(왼쪽)부터 수행해도 됩니다(오름차순정렬). 
그렇게 수정한 프로그램을 작성하세요.  
*/
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void bubble(int a[], int n){
	int i, j;
	for(i=n-1; i>0; i--){
		for(j=0; j<i; j++){
			if(a[j] > a[j+1]){
				swap(int, a[j], a[j+1]);
			}
		}
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
	
	printf("버블정렬 하였습니다.\n");
	bubble(x, nx);
	for(i=0; i<nx; i++){
		printf("x[%d] : %d\n", i, x[i]);
	}
	free(x);
	return 0;
}
