#include <stdio.h>
#include <stdlib.h>
#define MIN 1000000
int sumof(const int a[], int n){
	int i;
	int sum = 0;
	for(i=0; i<n; i++){
		sum += a[i];
	}
	return sum;
}

int main(void){
	int number;
	int i;
	int *a;
	printf("�� ����� �л��� �Է��Ͻðڽ��ϱ�?  : "); scanf("%d", &number);
	a = calloc(number, sizeof(int));
	for(i=0; i<number; i++){
		printf("Ű�� �Է��� �ּ��� :"); scanf("%d", &a[i]);
	}
	printf("�Է��� Ű���� �� ���� : %d �Դϴ�.", sumof(a, number));
	return 0;
}
