#include <stdio.h>
// ���� �Ʒ��� ������ �̵ �ﰢ���� ����մϴ�. 

int main(void){
	int i, j, n;
	do{
		printf("�� �� �ﰢ���Դϱ�? : ");
		scanf("%d", &n);
	}while(n <= 0);
	for(i=1; i<=n; i++){
		for(j=1; j<=i; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
} 
