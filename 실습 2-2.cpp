#include <stdio.h>

int main(void){
	int i;
	int a[5] = {1, 2, 3, 4, 5};
	int na = sizeof(a)/sizeof(a[0]);  
	// 정수 하나당 4bit 이므로 5개의 정수까 20bit 즉, na = 20 입니다. 
	// 정수 하나값. 즉, 4bit로 나누어 줌 으로써 총 정수의 갯수를 알 수 있습니다. a[0]대신 a[0~4] 아무 값 상관x 
	printf("배열 a의 요소 개수는 = %d 입니다.\n", na);
	
	for(i=0; i<na; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}
