#include <stdio.h>
// �����ʰ� ���� �Է��� ���� �� ������ �ϴ� ���簢���� *��ȣ�� ����ϴ� ���α׷��� �ۼ��ϼ���(å ����)

int main(void){
	int i, j;
	int a;
	printf("a �Է� :"); scanf("%d", &a);
	for(i=1; i<=a; i++){
		for(j=1; j<=a; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
} 
