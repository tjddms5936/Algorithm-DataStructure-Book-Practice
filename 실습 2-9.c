#include <stdio.h>

int main(void){
	int i, n;
	unsigned long counter;
	for(n=2; n<=1000; n++){
		for(i=2; i<n; i++){
			counter++;
			if(n % i == 0){
				break;  // n이 자기 자신 이외의 값으로 나누어 떨어졌으므로 반복문 더 할 필요x  
			}
		}
		if(n == i){
			printf("%d\n", n);
		} 
	}
	printf("나눗셈을 실행한 횟 수 : %lu", counter);
	return 0;
}
