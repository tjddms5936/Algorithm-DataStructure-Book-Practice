#include <stdio.h>

int main(void){
	int a, b;
	puts("b-a�� ����ϴ� �Լ��Դϴ�.\n");
	do{
		printf("a �Է� :"); scanf("%d", &a); 
		printf("b �Է� :"); scanf("%d", &b);
	}while(a>=b);
	printf("%d - %d�� %d�Դϴ�.", b, a, b-a);
	return 0;
}
