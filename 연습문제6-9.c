#include <stdio.h>
#include <stdlib.h>

// 단순 삽입 정렬 함수
void insertion(int a[], int n){
    int i, j;
    for(i=1; i<n; i++){
        int tmp = a[0] = a[i];
        for(j = i; a[j-1] > tmp; j--){
            a[j] = a[j-1];
        }
        if(j){
            a[j] = tmp;
        }
    }
}

int main(void){
    int i, nx;
    int *x;
    printf("Number of Elements :"); scanf("%d", &nx);
    x = calloc(nx+1, sizeof(int));
    for(i=1; i<nx+1; i++){
        printf("x[%d] : ", i); scanf("%d", &x[i]);
    }
    insertion(x, nx+1);
    printf("Finish the insertion\n");
    for(i=1; i<nx+1; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }
    free(x);
    return 0;
}