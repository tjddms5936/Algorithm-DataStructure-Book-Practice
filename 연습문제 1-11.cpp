#include <stdio.h>
/*
양의 정수를 입력하고 자릿수를 출력하는 프로그램을 작성하세요. 
예를 들어 135를 입력하면 '그 수는 3자리입니다.'라고 출력 
*/

int main(void){
	int a;
	int num;
	int jud = 1;
	printf("a를 입력 :"); scanf("%d", &a);
	num = a;
	do{
		num = num/10;
		jud += 1;
	}while(num>=10);
	printf("%d는 %d자릿수 입니다.", a, jud);
	return 0;
}
