#include <stdio.h>
#include <stdlib.h>
#define MIN 1000000
int minof(const int a[], int n){
	int i;
	int min = MIN;
	for(i=0; i<n; i++){
		if(a[i]<min){
			min = a[i];
		}
	}
	return min;
}

int main(void){
	int index;
	int i;
	int *a;
	printf("�� ��� ������ �Է��Ͻðڽ��ϱ�? : "); scanf("%d", &index);
	a = calloc(index, sizeof(int));
	for(i=0; i<index; i++){
		printf("������ �Է��� �ּ��� :"); scanf("%d", &a[i]);
	}
	printf("�Է��� ���� �� �ּҰ��� : %d �Դϴ�.", minof(a, index));
	return 0;
}
