#include <stdio.h>

// 곱셈표 출력 + 디자인 

int main(void){
	int i, j;
	printf("   |");
	for(i=1; i<=9; i++){
		printf("  %d", i);
	}
	printf("\n");
	printf("---+----------------------------");
	printf("\n");
	for(i=1; i<=9; i++){
		printf("  %d|", i);
		for(j=1; j<=9; j++){
			printf("%3d", i*j);
		}
		printf("\n");
	}
}
