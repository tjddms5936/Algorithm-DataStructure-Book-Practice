#include <stdio.h>
/*
���� ������ �Է��ϰ� �ڸ����� ����ϴ� ���α׷��� �ۼ��ϼ���. 
���� ��� 135�� �Է��ϸ� '�� ���� 3�ڸ��Դϴ�.'��� ��� 
*/

int main(void){
	int a;
	int num;
	int jud = 1;
	printf("a�� �Է� :"); scanf("%d", &a);
	num = a;
	do{
		num = num/10;
		jud += 1;
	}while(num>=10);
	printf("%d�� %d�ڸ��� �Դϴ�.", a, jud);
	return 0;
}
