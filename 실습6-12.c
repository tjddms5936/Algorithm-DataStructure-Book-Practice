// qsort �Լ��� ����Ͽ� ����ü �迭�� ���� 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[10]; 
    int height;
    int weight;
}Person;

// Person�� �� �Լ�(�̸� �������� ����)
int npcmp(const Person *x, const Person *y){
    return strcmp(x->name, y->name); // strcmp�� ǥ�� ���̺귯������ �����ϴ� �Լ� 
}

// Person�� �� �Լ�(Ű �������� ����)
int hpcmp(const Person *x, const Person *y){
    return x->height < y->height ? -1 : 
        x->height > y->height ? 1 : 0; 
}

// Person�� �� �Լ�(������ �������� ����)
int wpcmp(const Person *x, const Person *y){
    return x->weight < y->weight ? 1 :
        x->weight > y->weight ? -1 : 0;
}

// ��� no���� �����͸� ��� 
void print_person(const Person x[], int no){
    int i;
    for(i=0; i<no; i++){
        printf("%-10s %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
    }
}

int main(void){
    Person x[] = {
        {"SungEun", 178, 70},
        {"GyuBeom", 168, 63},
        {"SeungHyun", 184, 78},
        {"JiHwan", 179, 67}
    };
    int nx = sizeof(x) / sizeof(x[0]); // �迭 x�� ����� ���� 
    puts("���� ��"); 
    print_person(x, nx);

    // �̸� �������� ���� 
    qsort(x, nx, sizeof(Person), (int(*)(const void *, const void *))npcmp);
    puts("\n�̸� �������� ���� ��");
    print_person(x, nx);
    // Ű �������� ���� 
    qsort(x, nx, sizeof(Person), (int(*)(const void *, const void *))hpcmp);
    puts("\nŰ �������� ���� ��");
    print_person(x, nx);
    // ������ �������� ���� 
    qsort(x, nx, sizeof(Person), (int(*)(const void *, const void *))wpcmp);
    puts("\n������ �������� ���� ��");
    print_person(x, nx);

    return 0;
}