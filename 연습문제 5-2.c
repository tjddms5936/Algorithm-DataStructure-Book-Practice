// Q&A 5-2 : ��� �Լ� ȣ���� ������� �ʰ� gcd �Լ��� �ۼ��ϼ���.
// ��Ŭ����  ȣ������ ���� �ִ������� ���մϴ�.
#include <stdio.h>
// ���� x, y�� �ִ������� ��ȯ
int gcd(int x, int y){
	int t;
	if(y==0){
		return x;
	}
	else if(x==0){
		return y;
	}
	else{
		do{
			if(x==y){
				return x;
			}
			else{
				t = x;
				x = y%x;
				y = t;
			}
		}while(x>1);
		if(x==0){
			return y;
		}
		else{
			return x;
		}
	}
} 

int main(void){
	int x, y;
	int retry;
	do{
		printf("������ �Է��ϼ��� : "); scanf("%d", &x);
		printf("������ �Է��ϼ��� : "); scanf("%d", &y);
		printf("�ִ������� %d�Դϴ�.\n", gcd(x, y));
		printf("�ٽ� �Ͻðڽ��ϱ�? (1) : ��� (2) ��ž"); scanf("%d", &retry);
	}while(retry==1);	
	return 0;
} 
