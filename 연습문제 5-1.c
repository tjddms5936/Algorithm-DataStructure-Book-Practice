// Q&A 1 : ��� �Լ� ȣ���� ������� �ʰ� factorial �Լ��� �ۼ��ϼ��� 
#include <stdio.h>

int factorial(int n){
	int a=n;
	int b;
	if(n<=0){
		return 1;
	}
	else{
		do{
			b = a;
			a = a * (n-1);
			printf("%d = %d * %d\n", a, b, n-1); 
			n -= 1;
		}while(n>1);
		return a;
	}
}

int main(void){
	int x;
	printf("������ �Է��ϼ��� :"); scanf("%d", &x);
	printf("[%d!]�� ���� [%d]�Դϴ�.", x, factorial(x));
	return 0;
} 
