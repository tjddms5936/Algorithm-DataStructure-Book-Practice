#include <stdio.h>
/*
1~n까지의 합을 for문을 통해서 구합니다.  
*/

int main(void){
	int i, n;
	int sum = 0;
	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값 :"); scanf("%d", &n);
	for(i=0; i<=n; i++){
		sum += i;
	}
	printf("1부터 %d까지의 합은 %d입니다.", n, sum);
	return 0;
}
