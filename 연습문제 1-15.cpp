#include <stdio.h>
// 오른쪽과 같이 입력한 높이와 너비에 맞는 직사각형을 *기호로 출력하는 프로그램을 작성하세요 (책 참조)

int main(void){
	int i, j;
	int a, b;
	printf("a 입력 :"); scanf("%d", &a);
	printf("b 입력 :"); scanf("%d", &b);
	for(i=1; i<=a; i++){
		for(j=1; j<=b; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
} 
