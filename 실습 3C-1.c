#include <stdio.h>
// 덧셈, 곱셈표

// x1과 x2의 합 구하는 함수
int sum(int x1, int x2){
	return x1 + x2;
} 

// x1과 x2의 곱을 구하는 함수
int mul(int x1, int x2){
	return x1 * x2;
}

// 표 출력
int kuku(int(*calc)(int, int)){
	int i, j;
	for(i=1; i<=9; i++){
		for(j=1; j<=9; j++){
			printf("%3d", (*calc)(i, j)); // (*calc)(i,j) -> 호출 함수는 프로그램이 실행 될 때 결정됩니다. 
		}
		printf("\n");
	}
}

int main(void){
	puts("덧셈표");
	kuku(sum);
	puts("곱셈표");
	kuku(mul);
	return 0;
}
