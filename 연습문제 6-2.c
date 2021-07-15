/*
Q&A 6-2 : 오른쪽(책 참조) 처럼 비교, 교환 과정을 자세히 출력하면서 버블정렬하는 프로그램을 작성하세요
비교하는 두 요소 사이에 교환을 수행하면 '+', 수행하지 않으면 '-'를 출력하고 
정렬을 마치면 비교 횟수와 교환 횟수를 출력하세요. 
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
		printf("패스 %d\n", i+1);
		for(j=n-1; j>i; j--){ // 끝에서 부터 비교하는 오름차순 정렬 구현
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
	printf("비교를 %d회 했습니다.\n", compare);
	printf("교환을 %d회 했습니다.", trade);
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
