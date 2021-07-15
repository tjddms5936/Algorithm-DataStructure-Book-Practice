#include <stdio.h>
#include <stdlib.h>

// ���� �˻�
// ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�
/*
int bin_search2(const int b[], int n2, int key2){
	int pl2 = 0;
	int pr2 = n2-1;
	int pc2;
	do{
		pc2 = (pl2 + pr2) / 2;
		if(b[pc2] == key2){
			return 1;
		}
		else if(b[pc2] < key2){
			pl2 = pc2 + 1;
		}
		else{
			pr2 = pc2 - 1;
		}
	}while(pl2 <= pr2);
	return -1;
}
*/

int bin_search2(const int b[], int n2, int key2){
	int i;
	for(i=0; i<n2; i++){
		if(b[i] == key2){
			return i;
		}
	}
	return -1;
}

int bin_search(const int a[], int n, int key){
	int pl = 0;
	int pr = n-1;
	int pc;
	do{
		pc = (pl + pr) / 2;
		if(a[pc] == key){
			// �˻� ����
			if(bin_search2(a, pc, key)==-1){
				return pc;
			}
			else{
				return bin_search2(a, pc, key);
			} 
		}
		else if(a[pc] < key){
			pl = pc + 1;
		}
		else{
			pr = pc - 1;
		}
	}while(pl <= pr);
	return -1; // �˻� ���� 
} 

int main(void){
	int i, nx, ky, idx;
	int *x;
	puts("���� �˻�");
	printf("��� ���� :"); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("������������ �Է��ϼ���.\n");
	printf("x[0] :"); scanf("%d", &x[0]);
	for(i=1; i<nx; i++){
		do{
			printf("x[%d] :", i); 
			scanf("%d", &x[i]);
		}while(x[i] < x[i-1]); // �ٷ� ���� �� ���� ������ �ٽ� �Է�  
	}
	printf("�˻��� :"); scanf("%d", &ky);
	idx = bin_search(x, nx, ky);
	if(idx == -1){
		printf("�˻��� �����߽��ϴ�.");
	} 
	else{
		printf("%d�� x[%d]�� �ֽ��ϴ�.", ky, idx);
	}
	free(x);
	return 0;
}
