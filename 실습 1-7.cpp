#include <stdio.h>
/*
1~n������ ���� for���� ���ؼ� ���մϴ�.  
*/

int main(void){
	int i, n;
	int sum = 0;
	puts("1���� n������ ���� ���մϴ�.");
	printf("n�� �� :"); scanf("%d", &n);
	for(i=0; i<=n; i++){
		sum += i;
	}
	printf("1���� %d������ ���� %d�Դϴ�.", n, sum);
	return 0;
}
