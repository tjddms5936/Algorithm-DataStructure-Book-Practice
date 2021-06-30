#include <stdio.h>

/*
1,2, ..., n의 합을 구합니다. (while문) 
*/

int main(void){
	int i, n;
	int sum;
	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값 :"); scanf("%d", &n);
	sum = 0;
	i = 1;
	while(i <= n){ // i가 n보다 크면 반복문 종료 
		sum += i; // sum에 i를 더함 
		i++; // i는 1증가 
	}
	printf("1부터 %d까지의 합은 %d입니다.", n, sum);
	return 0;
} 
