#include <stdio.h>
// �����ʰ� ���� �Է��� ���̿� �ʺ� �´� ���簢���� *��ȣ�� ����ϴ� ���α׷��� �ۼ��ϼ��� (å ����)

int main(void){
	int i, j;
	int a, b;
	printf("a �Է� :"); scanf("%d", &a);
	printf("b �Է� :"); scanf("%d", &b);
	for(i=1; i<=a; i++){
		for(j=1; j<=b; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
} 
