#include <stdio.h>
// ����, ����ǥ

// x1�� x2�� �� ���ϴ� �Լ�
int sum(int x1, int x2){
	return x1 + x2;
} 

// x1�� x2�� ���� ���ϴ� �Լ�
int mul(int x1, int x2){
	return x1 * x2;
}

// ǥ ���
int kuku(int(*calc)(int, int)){
	int i, j;
	for(i=1; i<=9; i++){
		for(j=1; j<=9; j++){
			printf("%3d", (*calc)(i, j)); // (*calc)(i,j) -> ȣ�� �Լ��� ���α׷��� ���� �� �� �����˴ϴ�. 
		}
		printf("\n");
	}
}

int main(void){
	puts("����ǥ");
	kuku(sum);
	puts("����ǥ");
	kuku(mul);
	return 0;
}
