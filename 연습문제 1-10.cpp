#include <stdio.h>

int main(void){
	int a, b;
	puts("b-a를 출력하는 함수입니다.\n");
	do{
		printf("a 입력 :"); scanf("%d", &a); 
		printf("b 입력 :"); scanf("%d", &b);
	}while(a>=b);
	printf("%d - %d는 %d입니다.", b, a, b-a);
	return 0;
}
