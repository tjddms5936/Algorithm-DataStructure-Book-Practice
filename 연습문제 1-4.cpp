/* �� ���� ��� ���� 13������ ��� ���տ� ���� �߾Ӱ��� ���Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ��� */
#include <stdio.h>

int med3(int a, int b, int c){
	if(a >= b){
		if(b >= c){ // a >= b >= c �ϱ� �߾Ӱ��� b
			return b; 
		}
		else if(a <= c){ // c >= a >= b �ϱ� �߾Ӱ��� a 
			return a;
		}
		else{ // c�� b���� ũ��, a���� ���� ����. a < c < b �� ���� . �߾Ӱ��� c 
			return c; 
		}
	}
	else if(a > c){ // b > a > c �ϱ� �߾Ӱ��� a
		return a; 
	}
	else if(b > c){ // b > c > a �ϱ� �߾Ӱ��� c 
		return c; 
	}
	else{ // a < b , a < c , b < c  �� ����. c > b > a �ϱ� �߾Ӱ��� b 
		return b;  
	}
}

int main(void){
	int a, b, c;
	printf("�� ������ �߾Ӱ��� ���մϴ�.\n");
	printf("a�� �� : "); scanf("%d", &a);
	printf("b�� �� : "); scanf("%d", &b);
	printf("c�� �� : "); scanf("%d", &c);
	
	printf("�߾Ӱ��� %d�Դϴ�.", med3(a,b,c));
	return 0;
} 
