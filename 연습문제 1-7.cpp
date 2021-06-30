#include <stdio.h>
/*
for문을 이용(실습1-7인용)하여 n이 7이면 '1+2+3+4+5+6+7 = 28'로 출력하는 프로그램을 작성하세요 
*/ 

int main(void){
	int i, n;
	int sum = 0;
	puts("1부터 n까지의 합을 구하는 함수");
	printf("n의 값 입력 :"); scanf("%d", &n);
	for(i=1; i<=n; i++){
		if(i != n){
			printf("%d+", i);
		}
		else{
			printf("%d =", i);
		}
		sum += i;
	}
	printf("%d", sum);
	return 0; 
}
