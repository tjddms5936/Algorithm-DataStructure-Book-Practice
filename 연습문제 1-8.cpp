#include <stdio.h>
/*
1~10까지의 합은 (1+10)*5와 같은 방법으로 구할 수 있습니다.
가우스의 덧셈이라는 이 방법을 이용하여 1부터 n까지의 정수 합을 구하는 프로그램을 작성하세요  
*/

// 가우스의 법칙 1~n까지의 합 = (1+n) * n/2

int main(void){
	int i, n;
	int sum;
	puts("가우스의 법칙 함수");
	printf("n의 값 입력 :"); scanf("%d", &n);
	sum = (1+n) * (n/2);
	printf("1~%d까지의 합은 %d입니다.", n, sum);
	return 0;
} 
