#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ary_copy(int a[], const b[], int n){
	int i;
	for(i=0; i<n; i++){
		a[i] = b[i];
	}
	return;	
}

int main(void){
	int i;
	int *a;
	int *b;
	int number;
	srand(time(NULL));
	number = rand() % 5;
	a = calloc(number, sizeof(int));
	b = calloc(number, sizeof(int));
	for(i=0; i<number; i++){
		b[i] = rand() % 20;
		printf("b[%d] = %d\n", i, b[i]);
	}
	ary_copy(a, b, number);
	for(i=0; i<number; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
	free(a);
	free(b);
	return 0;
}


