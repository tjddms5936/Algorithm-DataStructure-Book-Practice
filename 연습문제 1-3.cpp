#include <stdio.h>

int min4(int a, int b, int c, int d){
	int min = a;
	if(b < min){
		min = b;
	}
	if(c < min){
		min = c;
	}
	if(d < min){
		min = d;
	}
	return min;
}

int main(void){
	printf("min4(%d, %d, %d, %d) = %d\n", 1, 2, 3, 4, min4(1,2,3,4)); // min = 1
	printf("min4(%d, %d, %d, %d) = %d", 5, 6, 3, 2, min4(5,6,3,2)); // min = 2
	return 0;
}
