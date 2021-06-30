#include <stdio.h>
/*
실습 1-6에서 while문이 종료될 때 변수 i의 값이 n+1이 됨을 확인하세요  
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
	printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);
	printf("현재 i의 값은 %d 입니다.", i); 
	return 0;
}  
