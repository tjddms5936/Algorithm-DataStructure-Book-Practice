#include <stdio.h>
/*
for���� �̿�(�ǽ�1-7�ο�)�Ͽ� n�� 7�̸� '1+2+3+4+5+6+7 = 28'�� ����ϴ� ���α׷��� �ۼ��ϼ��� 
*/ 

int main(void){
	int i, n;
	int sum = 0;
	puts("1���� n������ ���� ���ϴ� �Լ�");
	printf("n�� �� �Է� :"); scanf("%d", &n);
	for(i=1; i<=n; i++){
		if(i != n){
			printf("%d+", i);
		}
		else{
			printf("%d =", i);
		}
		sum += i;
	}
	printf("%d", sum);
	return 0; 
}
