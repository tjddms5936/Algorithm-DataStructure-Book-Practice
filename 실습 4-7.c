// ���ϴ� ������ŭ �����͸� �Է��ϰ�, ����� ������ n�� �迭���� �ֱٿ� �Է��� n���� ����
#include <stdio.h>
#define N 10

int main(){
	int i;
	int a[N]; // �Է��� �����͸� ������ �迭 
	int cnt = 0; // �Է��� �������� ���� 
	int retry; // �ٽ� �� ��?
	puts("������ �Է��ϼ���.");
	do{
		printf("%d��° ���� :", cnt + 1); scanf("%d", &a[cnt++ % N]);
		printf("����ұ��? (1)��� (0)����"); scanf("%d", &retry);
	}while(retry == 1);
	
	i = cnt - N;
	if(i<0){
		i = 0;
	}
	for(; i<cnt; i++){
		printf("%2d��° ���� = %d\n", i+1, a[i%N]);
	}
	if(i>0){
		for(i=N; i<cnt; i++){
			printf("a[%d] = %d\n", i%N, a[i%N]);
		}
		for(i=cnt-N; i<N; i++){
			printf("a[%d] = %d\n", i, a[i%N]);
		}
	}
	else{
		for(i=0; i<cnt; i++){
			printf("a[%d] = %d\n", i, a[i%N]);
		}
	}
	return 0;
} 
