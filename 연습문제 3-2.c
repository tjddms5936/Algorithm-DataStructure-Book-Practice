#include <stdio.h>
#include <stdlib.h>

int scan(const int a[], int n, int key){
	int i, j;
	printf("  |");
	for(i=0; i<n; i++){
		printf(" %d", i);
	}
	printf("\n");
	printf("--*-----------------\n");
	for(i=0; i<n; i++){
		printf("  |");
		for(j=0; j<n; j++){
			printf(" ");
			if(j==i){
				printf("*\n");
				break;
			}
			printf("  ");
		}
		printf(" %d|", i);
		for(j=0; j<n; j++){
			printf(" %d ", a[j]);
			if(j==i && a[j] == key){
				printf("\n");
				return j;
			}	
		}
		printf("\n");
		printf("  |\n");
		
	}
	return -1;
}

int main(void){
	int i, nx, ky, idx;
	int *x;
	puts("선형 검색");
	printf("요소 개수 :"); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for(i=0; i<nx; i++){
		printf("x[%d] :", i);
		scanf("%d", &x[i]);
	}
	printf("검색 값 :"); scanf("%d", &ky);
	idx = scan(x, nx, ky);
	if(idx == -1){
		printf("검색에 실패했습니다.");
	}
	else{
		printf("%d는 x[%d]에 있습니다.", ky, idx);
	}
	free(x);
	return 0;
}
