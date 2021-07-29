// 퀵 정렬 프로그램
#include <stdio.h>
#include <stdlib.h>
#define swap(type,x, y) do{type t = x; x = y; y = t;}while(0)

// 배열을 나누는 함수
void partition(int a[], int n){
    int i;
    int pl = 0;
    int pr = n-1;
    int x = a[n/2]; // 피벗은 가운데 요소를 선택할 것임. 
//******************************************************
    do{
        while(a[pl] < x){
            pl++;
        }
        while(a[pr] > x){
            pr--;
        }
        if(pl <= pr){
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    }while(pl <= pr);
//****************************************************** 
// 배열 a를 피벗x를 기준으로 나눔
    printf("피벗의 값은 %d입니다.\n", x);
    printf("피벗 이하의 그룹\n");
    for(i=0; i<=pl-1; i++){
        // a[0] ~ a[pl-1] 까지가 x이하! (x도 포함일수도 아닐수도)
        printf("%d ", a[i]);      
    }
    printf("\n");

    if(pl > pr+1){
        printf("피벗과 일치하는 그룹\n"); // 피벗과 같은 그룹
        for(i= pr+1; i<=pl-1; i++){
            // a[pr+1] ~ a[pl-1] 
            printf("%d", a[i]);
        }
        printf("\n");
    }

    printf("피벗 이상의 그룹\n");
    for(i=pr+1; i<n; i++){
        // a[0] ~ a[pl-1] 까지가 x이하! (x도 포함일수도 아닐수도)
        printf("%d ", a[i]);      
    }
    printf("\n");
}


int main(void){
    int i, nx;
    int *x;
    puts("배열을 나눕니다.");
    printf("요소의 개수 : "); scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for(i=0; i<nx; i++){
        printf("x[%d] :", i); scanf("%d", &x[i]);
    }   

    partition(x, nx);
    free(x);

    return 0;
}