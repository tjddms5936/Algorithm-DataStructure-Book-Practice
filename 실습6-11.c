// 표준 라이브러리에서 제공하는 qsort 함수 사용하기 stdlib.h에 있음
/*
void qsort(void *base, size_t nmemb, size_t size, int(*compar)(const void*, const void *));

base는 정렬할 배열 
nmemeb는 요소의 개수
size는 배열 요소의 크기 

compar는 비교 함수. 즉, compar에 지정한 비교 함수를 사용하여 정렬하게 된다. 

compar에 전달할 비교 함수는 다음과 같은 기능을 할 수 있도록 직접 작성해야 한다. 
첫 번째 인수가 두 번째 인수보다 작은 경우 : 0보다 작은 값 반환
첫 번째 인수가 두 번째 인수랑 같은 경우 : 0 반환 
첫 번째 인수가 두 번째 인수보다 큰 경우 : 0보다 큰 값 반환
*/

// qsort 함수를 사용하여 정수 배열을 오름차순으로 정렬
#include <stdio.h>
#include <stdlib.h>

// int형 비교 함수(오름차순 정렬에 사용)
int int_cmp(const int *a, const int *b){
    if(*a < *b){
        return -1;
    }
    if(*a > *b){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void){
    int i, nx;
    int *x;
    printf("qsort에 의한 정렬\n");
    printf("요소 개수 : "); scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for(i=0; i<nx; i++){
        printf("x[%d] :", i); scanf("%d", &x[i]);
    }
    qsort(x, nx, sizeof(int), (int(*)(const void *, const void *))int_cmp);
    puts("오름차순으로 정렬했습니다.");
    for(i=0; i<nx; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }
    free(x);
    return 0;
}
