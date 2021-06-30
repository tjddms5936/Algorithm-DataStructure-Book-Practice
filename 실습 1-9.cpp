#include <stdio.h>

// °ö¼ÀÇ¥¸¦ Ãâ·ÂÇÕ´Ï´Ù.

int main(void){
	int i, j;
	printf("-----°ö¼ÀÇ¥-----\n");
	for(i=1; i<=9; i++){
		for(j=1; j<=9; j++){
			printf("%3d", i*j);
		}
		printf("\n");
	}
	return 0;
} 
