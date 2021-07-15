#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// bsearch �Լ��� ����� ����ü �迭������ �˻�

typedef struct{
	char name[10]; // �̸�
	int height; // Ű
	int weight; // ������ 
}Person; 

// Person���� �� �Լ�(������������ �̸� ����)
int npcmp(const Person *x, const Person *y){
	return strcmp(x->name, y->name);  // string.h ����� ����Ǿ��ִ� �����Լ� 
} 

int main(void){
	Person x[] = {
	{"�ڼ���", 178, 67},
	{"�ֱԹ�", 168, 62},
	{"������", 165, 60},
	{"õ��â", 175, 62},
	{"������", 158, 60},
	{"�ѹ���", 176, 75}
	};
	int nx = sizeof(x)/sizeof(x[0]); // �迭 x�� ����� ���� 
	int retry;
	puts("�̸����� �˻��մϴ�.");
	do{
		Person temp, *p;
		printf("�̸� :"); scanf("%s", &temp.name);
		p = bsearch(&temp, x, nx, sizeof(Person), (int(*)(const void *, const void *))npcmp);
		if(p==NULL){
			puts("�˻��� �����߽��ϴ�.");
		}
		else{
			puts("�˻� ���� !! �Ʒ� ��Ҹ� ã�ҽ��ϴ�.");
			printf("x[%d] : %s %dcm %dkg\n", (int)(p-x), p->name, p->height, p->weight);
		}
		printf("�ٽ� �˻��ұ��? (1)�� (2)�ƴϿ� :"); scanf("%d", &retry);
	}while(retry == 1); 
	return 0;
}
