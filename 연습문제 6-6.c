/*
Q&A 6-6 : ������ ��.  
*/
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0) 

int sw[100];
int compare = 0;
int trade = 0;

void print(const int b[], int n2){
	int i;
	for(i=0; i<n2; i++){
		if(sw[i]==1){
			printf("%d+", b[i]);
		}
		else if(sw[i]==2){
			printf("%d-", b[i]);
		}
		else{
			printf("%d ", b[i]);
		}
	}
	printf("\n");	
}


void bubble(int a[], int n){
	int k = 0; // a[k]���� ������ ��Ҵ� ������ ��ģ �����Դϴ�. 
	int pass = 1;
	 
	while(k < n-1){
		if(pass%2 == 0){ // Ȧ����° �н����!  
			int j;
			int last = n - 1; // ���������� ��ȯ�� ������ ��ġ�� �����մϴ�. 
			for(j = n-1; j>k; j--){
				if(a[j-1] > a[j]){
					sw[j-1] = 1;
					print(a, n);
					swap(int, a[j-1], a[j]);
					last = j; 
					trade ++;
				}
				else{
					sw[j-1] = 2;
					print(a, n);
				}
				sw[j-1] = 0;
				compare ++;
			}
			print(a, n);
			k = last; 
			printf("\n");
		} 
		else{ // ¦�� 
			int j;
			int last = n - 1; // ���������� ��ȯ�� ������ ��ġ�� �����մϴ�. 
			for(j = k; j<n-1; j++){
				if(a[k] > a[k+1]){
					sw[k] = 1;
					print(a, n);
					swap(int, a[k], a[k+1]);
					last = k; 
					trade ++;
				}
				else{
					sw[k] = 2;
					print(a, n);
				}
				sw[k] = 0;
				compare ++;
			}
			print(a, n);
			k = last; 
			printf("\n");
		}
	} 
	printf("%dȸ ���Ͽ����ϴ�.\n", compare);
	printf("%dȸ ��ȯ�Ͽ����ϴ�.", trade);
} 
int main(void){
	int i, nx;
	int *x;
	printf("��� ���� :"); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	
	for(i=0; i<nx; i++){
		printf("x[%d] :", i); scanf("%d", &x[i]);
	}
	printf("\n");
	printf("���� ���� �Ͽ����ϴ�.\n\n");
	bubble(x, nx);
	free(x);
	return 0;
}
