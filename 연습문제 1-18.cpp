#include <stdio.h>
/* �����ʰ� ���� �Ʒ��� ���� n���� ���� �Ƕ�̵带 ����ϴ� �Լ��� �ۼ��ϼ���.
void nrpira(int n);
*/

void nrpira(int n){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=n; j>=n-i; j--){
			printf(" ");
		}
		for(j=1; j<=(n-i+1)*2+1; j++){
			printf("%d", i % 10);
		}
		printf("\n");
	}
	return;
}

int main(void){
	int n;
	printf("�� ���� �Ƕ�̵�? :");
	scanf("%d", &n);
	nrpira(n);
	return 0;
} 
