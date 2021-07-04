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
	printf("총 몇명의 학생을 입력하시겠습니까?  : "); scanf("%d", &number);
	a = calloc(number, sizeof(int));
	for(i=0; i<number; i++){
		printf("키를 입력해 주세요 :"); scanf("%d", &a[i]);
	}
	printf("입력한 키들의 총 합은 : %d 입니다.", sumof(a, number));
	return 0;
}
