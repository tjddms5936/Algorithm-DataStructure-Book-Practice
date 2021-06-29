/* 세 값의 대소 관계 13종류의 모든 조합에 대해 중앙값을 구하여 출력하는 프로그램을 작성하세요 */
#include <stdio.h>

int med3(int a, int b, int c){
	if(a >= b){
		if(b >= c){ // a >= b >= c 니까 중앙값은 b
			return b; 
		}
		else if(a <= c){ // c >= a >= b 니까 중앙값은 a 
			return a;
		}
		else{ // c가 b보다 크고, a보다 작은 상태. a < c < b 인 상태 . 중앙값은 c 
			return c; 
		}
	}
	else if(a > c){ // b > a > c 니까 중앙값은 a
		return a; 
	}
	else if(b > c){ // b > c > a 니까 중앙값은 c 
		return c; 
	}
	else{ // a < b , a < c , b < c  인 상태. c > b > a 니까 중앙값은 b 
		return b;  
	}
}

int main(void){
	int a, b, c;
	printf("세 정수의 중앙값을 구합니다.\n");
	printf("a의 값 : "); scanf("%d", &a);
	printf("b의 값 : "); scanf("%d", &b);
	printf("c의 값 : "); scanf("%d", &c);
	
	printf("중앙값은 %d입니다.", med3(a,b,c));
	return 0;
} 
