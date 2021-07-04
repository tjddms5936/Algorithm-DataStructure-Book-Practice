#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do{type t=x; x=y; y=t;}while(0)

void ary_rcopy(int a[], const b[], int n){
	int i;
	for(i=0; i<n; i++){
		a[i] = b[i];
	}
	for(i=0; i<n/2; i++){
		swap(int, a[i], a[n-i-1]);
	}
	return;	
}

int main(void){
	int i;
	int *a;
	int *b;
	int number;
	srand(time(NULL));
	number = 3 + rand() % 5;
	a = calloc(number, sizeof(int));
	b = calloc(number, sizeof(int));
	for(i=0; i<number; i++){
		b[i] = rand() % 20;
		printf("b[%d] = %d\n", i, b[i]);
	}
	printf("\n");
	ary_rcopy(a, b, number);
	for(i=0; i<number; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
	free(a);
	free(b);
	return 0;
}
