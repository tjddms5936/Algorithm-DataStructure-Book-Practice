#include <stdio.h>

int min3(int a, int b, int c){
	int min = a;
	if(b < min){
		min = b;
	}
	if(c < min){
		min = c;
	}
	return min;
}

int main(void){
	printf("min3(%d, %d, %d) = %d\n", 10, 20, 30, min3(10,20,30)); // min = 10
	printf("min3(%d, %d, %d) = %d", 13, 2, 111, min3(13,2,111)); // min = 2
	return 0;
} 
