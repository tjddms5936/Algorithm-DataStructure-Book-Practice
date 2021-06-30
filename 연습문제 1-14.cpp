#include <stdio.h>
// 오른쪽과 같이 입력한 수를 한 변으로 하는 정사각형을 *기호로 출력하는 프로그램을 작성하세요(책 참조)

int main(void){
	int i, j;
	int a;
	printf("a 입력 :"); scanf("%d", &a);
	for(i=1; i<=a; i++){
		for(j=1; j<=a; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
} 
