// Q&A 1 : 재귀 함수 호출을 사용하지 않고 factorial 함수를 작성하세요 
#include <stdio.h>

int factorial(int n){
	int a=n;
	int b;
	if(n<=0){
		return 1;
	}
	else{
		do{
			b = a;
			a = a * (n-1);
			printf("%d = %d * %d\n", a, b, n-1); 
			n -= 1;
		}while(n>1);
		return a;
	}
}

int main(void){
	int x;
	printf("정수를 입력하세요 :"); scanf("%d", &x);
	printf("[%d!]의 값은 [%d]입니다.", x, factorial(x));
	return 0;
} 
