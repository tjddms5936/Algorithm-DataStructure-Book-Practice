#include <stdio.h>

// n���� �Ƕ�̵带 ����ϴ� �Լ��� �ۼ��ϼ��� 

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
	printf("�� ���� �Ƕ�̵�? :");
	scanf("%d", &n);
	spira(n);
	return 0;
} 
