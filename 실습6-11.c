// ǥ�� ���̺귯������ �����ϴ� qsort �Լ� ����ϱ� stdlib.h�� ����
/*
void qsort(void *base, size_t nmemb, size_t size, int(*compar)(const void*, const void *));

base�� ������ �迭 
nmemeb�� ����� ����
size�� �迭 ����� ũ�� 

compar�� �� �Լ�. ��, compar�� ������ �� �Լ��� ����Ͽ� �����ϰ� �ȴ�. 

compar�� ������ �� �Լ��� ������ ���� ����� �� �� �ֵ��� ���� �ۼ��ؾ� �Ѵ�. 
ù ��° �μ��� �� ��° �μ����� ���� ��� : 0���� ���� �� ��ȯ
ù ��° �μ��� �� ��° �μ��� ���� ��� : 0 ��ȯ 
ù ��° �μ��� �� ��° �μ����� ū ��� : 0���� ū �� ��ȯ
*/

// qsort �Լ��� ����Ͽ� ���� �迭�� ������������ ����
#include <stdio.h>
#include <stdlib.h>

// int�� �� �Լ�(�������� ���Ŀ� ���)
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
    printf("qsort�� ���� ����\n");
    printf("��� ���� : "); scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for(i=0; i<nx; i++){
        printf("x[%d] :", i); scanf("%d", &x[i]);
    }
    qsort(x, nx, sizeof(int), (int(*)(const void *, const void *))int_cmp);
    puts("������������ �����߽��ϴ�.");
    for(i=0; i<nx; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }
    free(x);
    return 0;
}
