// 버블 정렬(버전2)을 연습문제 Q2(204쪽)처럼 비교ㅡ 교환 과정을 자세히 출력하는 프로그램으로 수정하ㅔ요.

// 버블 정렬(버전2 : 교환 횟수에 따라 정렬 작업을 멈춥니다. 
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
		int exchg = 0; // 패스에서 시도한 교환 횟수
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
