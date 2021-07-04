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
	printf("총 몇개의 정수를 입력하시겠습니까? : "); scanf("%d", &index);
	a = calloc(index, sizeof(int));
	for(i=0; i<index; i++){
		printf("정수를 입력해 주세요 :"); scanf("%d", &a[i]);
	}
	printf("입력한 정수 중 최소값은 : %d 입니다.", minof(a, index));
	return 0;
}
