#include <stdio.h>

// n단의 피라미드를 출력하는 함수를 작성하세요 

void spira(int n){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n-i; j++){
			printf(" ");
		}
		for(j=1; j<=(i-1)*2+1; j++){
			printf("*");
		}
		printf("\n");
	}
	return;
}

int main(void){
	int n;
	printf("몇 단의 피라미드? :");
	scanf("%d", &n);
	spira(n);
	return 0;
} 
