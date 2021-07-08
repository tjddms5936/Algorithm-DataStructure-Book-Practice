#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 Q6 : 요소의 값이 내림차순으로 정렬된 long형 배열에서의 검색을 
 bsearch 함수를 사용하여 프로그램을 작성하세요.  
*/

int int_cmp(const int *a, const int *b){
	if(*a > *b){
		return 1;
	}
	else if(*a < *b){
		return -1;
	}
	else{
		return 0;
	}
};

int main(void){
	int i, nx, ky;
	int *x;
	int *p;
	printf("요소 개수 :"); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("x[0] : "); scanf("%d", &x[0]);
	for(i=1; i<nx; i++){
		do{
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		}while(x[i] > x[i-1]); // 내림차순이니까 
	}
	printf("검색 값 : "); scanf("%d", &ky);
	p = bsearch(&ky, x, nx, sizeof(long), (int(*)(const void *, const void *))int_cmp);
	if(p == NULL){
		printf("검색에 실패했습니다.");
	}
	else{
		printf("검색에 성공했습니다.\n");
		printf("%d는 x[%d]에 있습니다.", ky, (int)(p-x));
	}
	free(x);
}


















