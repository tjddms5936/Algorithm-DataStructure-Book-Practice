#include <stdio.h>
/* 
직각 이등변 삼각형을 출력하는 부분을 아래와 같은 형식의 함수로 작성하세요.
void triangleLB (int n);  << 왼쪽 아래가 직각인 이등변 삼각형을 출력 
void triangleLU (int n); << 왼쪽 위가 직각인 이등변 삼각형을 출력 
void triangleRU (int n); << 오른쪽 위가 직각인 이등변 삼각형을 출력 
void triangleRB (int n); << 오른쪽 아래가 직각인 이등변 삼각형을 출력 
*/  

void triangleLB (int n){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=i; j++){
			printf("*");
		}
		printf("\n");
	}
	return;
} 

void triangleLU (int n){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=n; j>=i; j--){
			printf("*");
		}
		printf("\n");
	}
	return;
}

void triangleRU (int n){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=i-1; j++){
			printf(" ");
		}
		
		for(j=1; j<=n-i+1; j++){
			printf("*");
		} 
		printf("\n");
	}
	return;
}


void triangleRB (int n){
	int i, j;
	for(i=n; i>=1; i--){
		for(j=1; j<=i-1; j++){
			printf(" ");
		}
		
		for(j=1; j<=n-i+1; j++){
			printf("*");
		} 
		printf("\n");
	}
	return;
}
int main(void){
	int n;
	do{
		printf("몇 단 삼각형입니까? : ");
		scanf("%d", &n);
	}while(n <= 0);
	printf("왼쪽 아래가 직각\n");
	triangleLB(n);
	printf("왼쪽 위가 직각\n");
	triangleLU(n);
	printf("오른쪽 위가 직각\n");
	triangleRU(n);
	printf("오른쪽 아래가 직각\n");
	triangleRB(n);
	return 0;
}
