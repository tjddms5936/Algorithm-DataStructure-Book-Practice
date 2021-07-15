#include <stdio.h>
#include <stdlib.h>

// 선형 검색(보초법)
// Q1. search함수를 while문이 아니라 for문으로 수정 
// 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색(보초법)
int search(int a[], int n, int key){
	int i;
	a[n] = key;
	for(i=0; i<=n; i++){
		if(a[i] == key){
			break;
		}
		continue; 
	}
	return i == n ? -1 : i; // i==n이냐? 맞으면 -1반환 아니면 i반환 
} 

int main(void){
	int i, nx, ky, idx;
	int *x;
	puts("선형 검색(보초법)");
	
	printf("요소 개수 :"); scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int)); // 동적 할당. 보초를 추가해줘야 하기 때문에 nx보다 한개 더 생성  
	
	
	for(i=0; i<nx; i++){ // 값이 들어가는것은 nx개만  
		printf("x[%d] :", i); scanf("%d", &x[i]);
	}
	
	
	printf("검색 값 : "); scanf("%d", &ky);
	
	
	idx = search(x, nx, ky); 
	
	
	if(idx == -1){
		printf("검색에 실패했습니다.");
	}
	else{
		printf("%d는 x[%d]에 있습니다.", ky, idx);
	}
	free(x); // 배열 해제  
	return 0;
}  
