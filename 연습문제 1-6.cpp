#include <stdio.h>
/*
�ǽ� 1-6���� while���� ����� �� ���� i�� ���� n+1�� ���� Ȯ���ϼ���  
*/
int main(void){
	int i, n;
	int sum;
	puts("1���� n������ ���� ���մϴ�.");
	printf("n�� �� :"); scanf("%d", &n);
	sum = 0;
	i = 1;
	while(i <= n){ // i�� n���� ũ�� �ݺ��� ���� 
		sum += i; // sum�� i�� ���� 
		i++; // i�� 1���� 
	}
	printf("1���� %d������ ���� %d�Դϴ�.\n", n, sum);
	printf("���� i�� ���� %d �Դϴ�.", i); 
	return 0;
}  
