#include <stdio.h>
/* 
���� �̵ �ﰢ���� ����ϴ� �κ��� �Ʒ��� ���� ������ �Լ��� �ۼ��ϼ���.
void triangleLB (int n);  << ���� �Ʒ��� ������ �̵ �ﰢ���� ��� 
void triangleLU (int n); << ���� ���� ������ �̵ �ﰢ���� ��� 
void triangleRU (int n); << ������ ���� ������ �̵ �ﰢ���� ��� 
void triangleRB (int n); << ������ �Ʒ��� ������ �̵ �ﰢ���� ��� 
*/  

void triangleLB (int n){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=i; j++){
			printf("*");
		}
		printf("\n");
	}
	return;
} 

void triangleLU (int n){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=n; j>=i; j--){
			printf("*");
		}
		printf("\n");
	}
	return;
}

void triangleRU (int n){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=i-1; j++){
			printf(" ");
		}
		
		for(j=1; j<=n-i+1; j++){
			printf("*");
		} 
		printf("\n");
	}
	return;
}


void triangleRB (int n){
	int i, j;
	for(i=n; i>=1; i--){
		for(j=1; j<=i-1; j++){
			printf(" ");
		}
		
		for(j=1; j<=n-i+1; j++){
			printf("*");
		} 
		printf("\n");
	}
	return;
}
int main(void){
	int n;
	do{
		printf("�� �� �ﰢ���Դϱ�? : ");
		scanf("%d", &n);
	}while(n <= 0);
	printf("���� �Ʒ��� ����\n");
	triangleLB(n);
	printf("���� ���� ����\n");
	triangleLU(n);
	printf("������ ���� ����\n");
	triangleRU(n);
	printf("������ �Ʒ��� ����\n");
	triangleRB(n);
	return 0;
}
