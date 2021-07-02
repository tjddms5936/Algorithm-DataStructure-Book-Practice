#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* �迭 ����� �ִ��� ���մϴ�(���� ������ ����) */

// ��� ������ n�� �迭 a�� ����� �ִ��� ���մϴ�.
int maxof(const int a[], int n){
	int i;
	int max = a[0];
	for(i=1; i<n; i++){
		if(a[i]>max){
			max = a[i];
		}
	}
	return max;
}

int main(void){
	int i;
	int *height;
	int number;
	printf("��� �� :"); scanf("%d", &number);
	height = calloc(number, sizeof(int));
	srand(time(NULL)); // �ð����� ������ seed(����)�� �ʱ�ȭ 
	for(i=0; i<number; i++){
		height[i] = 100 + rand() % 90; // 100~189�� ������ ����&���� 
		printf("height[%d] = %d\n", i, height[i]);
	}
	printf("�ִ��� %d�Դϴ�.\n", maxof(height, number));
	free(height);
	return 0;
} 
