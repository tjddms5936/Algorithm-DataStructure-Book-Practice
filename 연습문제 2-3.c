#include <stdio.h>
#include <stdlib.h>


double aveof(const int a[], int n){
	int i;
	double sum = 0;
	for(i=0; i<n; i++){
		sum += a[i];
	}
	return sum/n;
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
	printf("�Է��� Ű���� ����� : %.2f �Դϴ�.", aveof(a, number));
	return 0;
}
