#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)



static void downhip(int a[], int left, int right){
    int temp = a[left];
    int child, parent;
    for(parent = left; parent < (right +1)/2; parent = child){
        int cl = parent * 2 + 1; // �����ڽ� �ε���
        int cr = cl + 1; // ������ �ڽ� �ε���
        child = (cr <= right && a[cr] > a[cl] ? cr : cl); // ū ���� ����
        if(temp >= a[child]){
            break;
        }
        a[parent] = a[child];
    }
    a[parent] = temp; 
}

// �� ���� �Լ� 
void heapsort(int a[], int n){
    int i;
    for(i = (n-1)/2; i >= 0; i--){
        downhip(a, i, n-1);
    }
    for(i = n-1; i >0; i--){
        swap(int, a[0], a[i]); // ��Ʈ�� ���� �������̶� �ٲ���
        downhip(a, 0, i-1); 
    }
}

int main(void){
    int i, nx;
    int *x;
    printf("�� ����\n��� ���� :"); scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for(i = 0; i<nx; i++){
        printf("x[%d] : ", i); scanf("%d", &x[i]);
    }

    heapsort(x, nx); // �迭 x�� �� ���� 
    puts("������������ ���� �Ͽ����ϴ�.\n");
    for(i=0; i<nx; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x); 

    return 0;
}