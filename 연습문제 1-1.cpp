#include <stdio.h>

int max4(int a, int b, int c, int d){
	int max = a;
	if(b > max){
		max = b;
	}
	if(c > max){
		max = c;
	}
	if(d > max){
		max = d;
	}
	return max;
}

int main(void){
	printf("max4(%d, %d, %d, %d) = %d\n", 1, 5, 67, 142, max4(1,5,67,142)); // max = 142 
	printf("max4(%d, %d, %d, %d) = %d\n", 11, 45, 7, 31, max4(11,45,7,31)); // max = 45 
	return 0;
}
