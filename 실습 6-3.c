// ��������(����3 : ��ĵ ������ �����մϴ�.)
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void bubble(int a[], int n){
	int k = 0; // a[k]���� ������ ��Ҵ� ������ ��ģ �����Դϴ�. 
	while(k < n-1){
		int j;
		int last = n - 1; // ���������� ��ȯ�� ������ ��ġ�� �����մϴ�. 
		for(j = n-1; j>k; j--){
			if(a[j-1] > a[j]){
				swap(int, a[j-1], a[j]);
				last = j; 
			}
		}
		k = last; 
		
	} 
} 
int main(void){
	return 0;
}
