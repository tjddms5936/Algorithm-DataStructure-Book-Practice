#include <stdio.h>

int main(void){
	int i;
	int a[5] = {1, 2, 3, 4, 5};
	int na = sizeof(a)/sizeof(a[0]);  
	// ���� �ϳ��� 4bit �̹Ƿ� 5���� ������ 20bit ��, na = 20 �Դϴ�. 
	// ���� �ϳ���. ��, 4bit�� ������ �� ���ν� �� ������ ������ �� �� �ֽ��ϴ�. a[0]��� a[0~4] �ƹ� �� ���x 
	printf("�迭 a�� ��� ������ = %d �Դϴ�.\n", na);
	
	for(i=0; i<na; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}
