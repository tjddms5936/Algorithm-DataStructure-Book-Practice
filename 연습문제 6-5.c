// 연습문제 Q2(204쪽)와 마찬가지로 비교, 교환 과정을 자세히 출력하는 프로그램(실습 6-3)으로 수정하세요

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
	int k = 0; // a[k]보다 앞쪽의 요소는 정렬을 마친 상태입니다. 
	while(k < n-1){
		int j;
		int last = n - 1; // 마지막으로 교환을 수행한 위치를 저장합니다. 
		for(j = n-1; j>k; j--){
			if(a[j-1] > a[j]){
				sw[j-1] = 1;
				print(a, n);
				swap(int, a[j-1], a[j]);
				last = j; 
				trade ++;
			}
			else{
				sw[j-1] = 2;
				print(a, n);
			}
			sw[j-1] = 0;
			compare ++;
		}
		print(a, n);
		k = last; 
		printf("\n"); 
		
	} 
	printf("%d회 비교하였습니다.\n", compare);
	printf("%d회 교환하였습니다.", trade);
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
