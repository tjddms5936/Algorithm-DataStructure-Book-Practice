#include <stdio.h>

/*
1~n������ ���� ���մϴ�. (do������ ���� �������� n ������ �Է��մϴ�.)
*/

int main(void){
	int i, n;
	int sum;
	puts("1���� n������ ���� ���մϴ�.");
	do{
		printf("n �� :"); scanf("%d", &n);
	}while(n<=0); // n�� 0���� Ŭ ������ �ݺ��մϴ�.
	sum = 0;
	for(i=1; i<=n; i++){
		sum += i;
	} 
	printf("1���� %d������ ���� %d�Դϴ�.", n, sum);
	return 0;
} 

