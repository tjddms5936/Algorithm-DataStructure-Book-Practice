#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do{type t=x; x=y; y=t;}while(0)

void ary_reverse(int a[], int n){
	int i;
	for(i=0; i<n/2; i++){
		swap(int, a[i], a[n-i-1]);
	}
	return;
}


int main(void){
	int i; 
	int *array;
	int number;
	srand(time(NULL));
	number = 5 + rand() % 5;
	array = calloc(number, sizeof(int));
	for(i=0; i<number; i++){
		array[i] = rand() % 20;
		printf("array[%d] = %d\n", i, array[i]);
	}
	ary_reverse(array, number);
	printf("역순 정렬\n");
	for(i=0; i<number; i++){
		printf("ary_reverse[%d] = %d\n", i, array[i]);
	}
	free(array);
	return 0;
}
