/* 중앙값을 구하는 함수는 다음과 같이 작성할 수도 있습니다. 그러나 연습문제 1-4의 함수의 비해 효율이 떨어지는데 그 이유는? */
#include <stdio.h>

int med3(int a, int b, int c){
	if((b >= a && c <= a) || (b <= a && c >= a)){  // c <= a <= b  || b <= a <= c 일 경우 
		return a; // a가 중앙값 
	}
	else if((a > b && c < b) || (a < b && c > b)){ // c < b < a || a < b < c 일 경우 
		return b; // b가 중앙값  
	}
	return c; // 위의 모든 경우가 아니라면 c가 중앙값.  
}

int main(void){
	int a, b, c;
	printf("세 정수의 중앙값을 구합니다.\n");
	printf("a의 값 : "); scanf("%d", &a); 
	printf("b의 값 : "); scanf("%d", &b);
	printf("c의 값 : "); scanf("%d", &c);
	printf("중앙값은 %d입니다.", med3(a, b, c));
	return 0;
} 


/*
연습문제 1-4와 비교해봤을 때 정수가 3개인 경우는 이 함수가 훨씬 유용해 보이지만 만약 정수의 갯수가 기하급수적으로 늘어난다면 
1-5번처럼 조건문을 작성하기가 너무 까다로워 지기 때문에 정수의 갯수가 많아질수록 이 함수는 효율성이 떨어지는 것 같다.  
*/
