// ���� �˻�(���ʹ�) 
#include <stdio.h> 
#include <stdlib.h>

// ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�(���ʹ�)
int search(int a[], int n, int key){
	int i = 0;
	a[n] = key;
	while(1){
		if(a[i] == key){
			break; // ���ϴ� Ű ���� ã�� ��� // ���� ������ Ž�� �Ϸ� & �ݺ��� ����
		}
		i++; // ���ʹ��� �ƴϸ� i�� ���Ѵ�� �����ϸ鼭 �ݺ����� ������ ������ 
		// ���ʹ��� ��������ν� ���������δ� �߰��ϰ� �Ǳ� ������ �ᱹ �ݺ����� ����.  
	}
	return i == n ? -1 : i; // i==n�̳�? ������ -1��ȯ �ƴϸ� i��ȯ 
} 

int main(void){
	int i, nx, ky, idx;
	int *x;
	puts("���� �˻�(���ʹ�)");
	
	printf("��� ���� :"); scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int)); // ���� �Ҵ�. ���ʸ� �߰������ �ϱ� ������ nx���� �Ѱ� �� ����  
	
	
	for(i=0; i<nx; i++){ // ���� ���°��� nx����  
		printf("x[%d] :", i); scanf("%d", &x[i]);
	}
	
	
	printf("�˻� �� : "); scanf("%d", &ky);
	
	
	idx = search(x, nx, ky); 
	
	
	if(idx == -1){
		printf("�˻��� �����߽��ϴ�.");
	}
	else{
		printf("%d�� x[%d]�� �ֽ��ϴ�.", ky, idx);
	}
	free(x); // �迭 ����  
	return 0;
} 
