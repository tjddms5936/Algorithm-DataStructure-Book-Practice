#include <stdio.h>

/*
���� a, b�� �����Ͽ� �� ������ ��� ������ ���� ���ϴ� �Ʒ� �Լ��� �ۼ��ϼ���.
int sumof(int a, int b)  << ��� �Լ��� �ۼ��϶�� �� ����;; 
*/ 

int sumof(int a, int b){
	int i;
	int sum = 0;
	if(a>b){
		for(i=b; i<=a; i++){
			sum += i;
		}
		return sum;
	}
	else if(a<b){
		for(i=a; i<=b; i++){
			sum += i;
		}
		return sum;
	}
	else{
		sum = a + b;
		return sum;
	}
}

int main(void){
	int a, b;
	puts("a�� b�� �Է����ּ���\n");
	printf("a : "); scanf("%d", &a);
	printf("b : "); scanf("%d", &b);
	if(a>b){
		printf("%d ���� %d������ ���� %d �Դϴ�.", b, a, sumof(a, b));	
	}
	else{
		printf("%d ���� %d������ ���� %d �Դϴ�.", a, b, sumof(a, b));
	}
	return 0;
} 
