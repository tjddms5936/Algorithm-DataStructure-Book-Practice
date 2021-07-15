// 버블정렬(버전3 : 스캔 범위를 제한합니다.)
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void bubble(int a[], int n){
	int k = 0; // a[k]보다 앞쪽의 요소는 정렬을 마친 상태입니다. 
	while(k < n-1){
		int j;
		int last = n - 1; // 마지막으로 교환을 수행한 위치를 저장합니다. 
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
