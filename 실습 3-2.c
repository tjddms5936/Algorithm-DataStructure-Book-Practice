// ���� �˻� for������  
#include <stdio.h>
#include <stdlib.h>

// ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�
int search(const int a[], int n, int key){
	int i;
	for(i=0; i<n; i++){
		if(a[i] == key){
			return i;
		} // �˻� ���� 
	}
	return -1; // �˻� ���� 
} 

int main(void){
	int i, nx, ky, idx;
	int *x; // �迭�� ù ��° ��ҿ� ���� ������
	puts("���� �˻�");
	printf("��� ���� :"); scanf("%d", &nx);
	x = calloc(nx, sizeof(int)); // ����� ������ nx�� int�� �迭�� ���� ����
	for(i=0; i<nx; i++){
		printf("x[%d] :", i); scanf("%d", &x[i]); // ��� ���� 
	} 
	printf("�˻��� :"); scanf("%d", &ky);
	idx = search(x, nx, ky); // �迭 x�� ���� ky�� ��Ҹ� ���� �˻� 
	if(idx==-1){ // �˻��� �����ߴٸ�
		puts("�˻��� �����߽��ϴ�."); 
 	} 
 	else{ // �˻��� �����ߴٸ�
		printf("%d�� x[%d]�� �ֽ��ϴ�.\n", ky, idx); 	 
	}
	free(x);
	 
	return 0;
} 
