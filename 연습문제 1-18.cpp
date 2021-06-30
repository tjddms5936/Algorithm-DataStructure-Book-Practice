#include <stdio.h>
/* 오른쪽과 같이 아래를 향한 n단의 숫자 피라미드를 출력하는 함수를 작성하세요.
void nrpira(int n);
*/

void nrpira(int n){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=n; j>=n-i; j--){
			printf(" ");
		}
		for(j=1; j<=(n-i+1)*2+1; j++){
			printf("%d", i % 10);
		}
		printf("\n");
	}
	return;
}

int main(void){
	int n;
	printf("몇 단의 피라미드? :");
	scanf("%d", &n);
	nrpira(n);
	return 0;
} 
