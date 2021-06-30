#include <stdio.h>
// 곱셈이 아니라 덧셈을 출력하는 프로그램을 작성하세요 . 즉, 덧셈표 작성

int main(void){
	int i, j;
	printf("덧셈표|");
	for(i=1; i<=9; i++){
		printf("  %d", i);
	}
	printf("\n");
	printf("------+-----------------------------");
	printf("\n");
	for(i=1; i<=9; i++){
		printf("     %d|", i);
		for(j=1; j<=9; j++){
			printf("%3d", i+j);
		}
		printf("\n");
	}
	return 0;
} 
