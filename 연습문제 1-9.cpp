#include <stdio.h>

/*
정수 a, b를 포함하여 그 사이의 모든 정수의 합을 구하는 아래 함수를 작성하세요.
int sumof(int a, int b)  << 라는 함수를 작성하라는 거 ㅋㅋ;; 
*/ 

int sumof(int a, int b){
	int i;
	int sum = 0;
	if(a>b){
		for(i=b; i<=a; i++){
			sum += i;
		}
		return sum;
	}
	else if(a<b){
		for(i=a; i<=b; i++){
			sum += i;
		}
		return sum;
	}
	else{
		sum = a + b;
		return sum;
	}
}

int main(void){
	int a, b;
	puts("a와 b를 입력해주세요\n");
	printf("a : "); scanf("%d", &a);
	printf("b : "); scanf("%d", &b);
	if(a>b){
		printf("%d 부터 %d까지의 합은 %d 입니다.", b, a, sumof(a, b));	
	}
	else{
		printf("%d 부터 %d까지의 합은 %d 입니다.", a, b, sumof(a, b));
	}
	return 0;
} 
