#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)



static void downhip(int a[], int left, int right){
    int temp = a[left];
    int child, parent;
    for(parent = left; parent < (right +1)/2; parent = child){
        int cl = parent * 2 + 1; // 왼쪽자식 인덱스
        int cr = cl + 1; // 오른쪽 자식 인덱스
        child = (cr <= right && a[cr] > a[cl] ? cr : cl); // 큰 값을 선택
        if(temp >= a[child]){
            break;
        }
        a[parent] = a[child];
    }
    a[parent] = temp; 
}

// 힙 정렬 함수 
void heapsort(int a[], int n){
    int i;
    for(i = (n-1)/2; i >= 0; i--){
        downhip(a, i, n-1);
    }
    for(i = n-1; i >0; i--){
        swap(int, a[0], a[i]); // 루트랑 제일 마지막이랑 바꿔줌
        downhip(a, 0, i-1); 
    }
}

int main(void){
    int i, nx;
    int *x;
    printf("힙 정렬\n요소 개수 :"); scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for(i = 0; i<nx; i++){
        printf("x[%d] : ", i); scanf("%d", &x[i]);
    }

    heapsort(x, nx); // 배열 x를 힙 정렬 
    puts("오름차순으로 정렬 하였습니다.\n");
    for(i=0; i<nx; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x); 

    return 0;
}