#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// bsearch 함수를 사용한 구조체 배열에서의 검색

typedef struct{
	char name[10]; // 이름
	int height; // 키
	int weight; // 몸무게 
}Person; 

// Person형의 비교 함수(오름차순으로 이름 정렬)
int npcmp(const Person *x, const Person *y){
	return strcmp(x->name, y->name);  // string.h 헤더에 내장되어있는 정렬함수 
} 

int main(void){
	Person x[] = {
	{"박성은", 178, 67},
	{"최규범", 168, 62},
	{"안혜영", 165, 60},
	{"천현창", 175, 62},
	{"이유나", 158, 60},
	{"한범우", 176, 75}
	};
	int nx = sizeof(x)/sizeof(x[0]); // 배열 x의 요소의 개수 
	int retry;
	puts("이름으로 검색합니다.");
	do{
		Person temp, *p;
		printf("이름 :"); scanf("%s", &temp.name);
		p = bsearch(&temp, x, nx, sizeof(Person), (int(*)(const void *, const void *))npcmp);
		if(p==NULL){
			puts("검색에 실패했습니다.");
		}
		else{
			puts("검색 성공 !! 아래 요소를 찾았습니다.");
			printf("x[%d] : %s %dcm %dkg\n", (int)(p-x), p->name, p->height, p->weight);
		}
		printf("다시 검색할까요? (1)예 (2)아니오 :"); scanf("%d", &retry);
	}while(retry == 1); 
	return 0;
}
