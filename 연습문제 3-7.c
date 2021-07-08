#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 Q7 : bsearch 함수와 같은 형식으로 호출할 수 있는 다음 함수를 작성하세요. 
 단, 선형 검색 알고리즘을 사용하고, 배열은 정렬되어 있지 않아도 좋습니다.  
*/
// 실패한 코딩. 실행이 이상하게 됨
void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *)){
	size_t i;
	char   *x = (char *)base;

	for (i = 0; i < nmemb; i++)
		if (!compar((const void *)&x[i * size], key))
			return (&x[i * size]);
	return NULL;
}

int compare(int *x, int *y){
	if(*x > *y){
		return 1;
	}
	else if(*x < *y){
		return -1;
	}
	else{
		return 0;
	}
	
}

int main(void){
	int i, nx, ky;
	int *x;
	int *p;
	printf("요소 개수 : "); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for(i=0; i<nx; i++){
		printf("x[%d] : ", i); 
		scanf("%d", &x[i]);
	}
	printf("검색 값 : "); scanf("%d", &ky);
	p = seqsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *))compare);
	if(p==NULL){
		printf("검색에 실패했습니다..");
	}
	else{
		printf("검색에 성공했습니다..\n");
		printf("%d는 x[%d]에 있습니다..", ky, (int)(p-x));
	}
	free(x);
	return 0;
}

