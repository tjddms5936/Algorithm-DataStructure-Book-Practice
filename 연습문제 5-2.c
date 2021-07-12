// Q&A 5-2 : 재귀 함수 호출을 사용하지 않고 gcd 함수를 작성하세요.
// 유클리드  호제법에 의해 최대공약수를 구합니다.
#include <stdio.h>
// 정수 x, y의 최대공약수를 반환
int gcd(int x, int y){
	int t;
	if(y==0){
		return x;
	}
	else if(x==0){
		return y;
	}
	else{
		do{
			if(x==y){
				return x;
			}
			else{
				t = x;
				x = y%x;
				y = t;
			}
		}while(x>1);
		if(x==0){
			return y;
		}
		else{
			return x;
		}
	}
} 

int main(void){
	int x, y;
	int retry;
	do{
		printf("정수를 입력하세요 : "); scanf("%d", &x);
		printf("정수를 입력하세요 : "); scanf("%d", &y);
		printf("최대공약수는 %d입니다.\n", gcd(x, y));
		printf("다시 하시겠습니까? (1) : 계속 (2) 스탑"); scanf("%d", &retry);
	}while(retry==1);	
	return 0;
} 
