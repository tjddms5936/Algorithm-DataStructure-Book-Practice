#include <stdio.h>

int main(void){
	int i, n;
	unsigned long counter;
	for(n=2; n<=1000; n++){
		for(i=2; i<n; i++){
			counter++;
			if(n % i == 0){
				break;  // n�� �ڱ� �ڽ� �̿��� ������ ������ ���������Ƿ� �ݺ��� �� �� �ʿ�x  
			}
		}
		if(n == i){
			printf("%d\n", n);
		} 
	}
	printf("�������� ������ Ƚ �� : %lu", counter);
	return 0;
}
