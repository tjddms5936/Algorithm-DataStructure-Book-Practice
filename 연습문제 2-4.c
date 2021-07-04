#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxof(const int a[], int n){
	int i;
	int max = 0;
	for(i=0; i<n; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	return max;
}

int main(void){
	int i;
	int *height;
	int number;
	srand(time(NULL));
	number = 5 + rand() % 20;
	height = calloc(number, sizeof(int));
	for(i=0; i<number; i++){
		height[i] = 160 + rand() % 30; // 160~189������ ����  
		printf("height[%d] = %d\n", i, height[i]);
	}
	printf("");
	printf("Ű �� �ִ��� %d�Դϴ�.", maxof(height, number)); 
	return 0;
}
