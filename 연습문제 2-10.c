#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do{type t=x; x=y; y=t;}while(0)

void shuffle(int a[], int n){
	int i;
	int shuf;
	for(i=0; i<n; i++){
		shuf = 1 + rand() % n;
		swap(int, a[i], a[shuf]);
	}
	return;	
}

int main(void){
	int i;
	int *b;
	int number;
	srand(time(NULL));
	number = 3 + rand() % 5;
	b = calloc(number, sizeof(int));
	for(i=0; i<number; i++){
		b[i] = rand() % 20;
		printf("b[%d] = %d\n", i, b[i]);
	}
	printf("\n");
	shuffle(b, number);
	for(i=0; i<number; i++){
		printf("shuffle[%d] = %d\n", i, b[i]);
	}

	free(b);
	return 0;
}
