/* Q11 이진 삽입 정렬(요소 이동에 memmove 함수를 사용）*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*--- 이진 삽입 정렬(요소 이동에 memmove 함수를 사용）---*/
void bin_insertion(int a[], int n)
{
	int  i, j;
	// int k;
	for (i = 1; i < n; i++) {
		int key = a[i];
		int pl = 0;		
		int pr = i - 1;	
		int pc;			
		int pd;			

		do {
			pc = (pl + pr) / 2;
			if (a[pc] == key)		
				break;
			else if (a[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);
		pd = (pl <= pr) ? pc + 1 : pr + 1;
//********************************************************************
		memmove(&a[pd + 1], &a[pd], (i - pd) * sizeof(int));
    /* a[pd] 의 위치부터 i-pd 갯수 만큼을 즉, a[pd] ~ 바꾸려는 인덱스 까지를 복사
        한 뒤 a[pd + 1] 부터 붙여넣기함. 만약 5 7 9 4 1 에서 i = 3 이라면
        key = 4, pr = 2, pc = 1 -> a[pc] = 7 > key -> pr = 0
        pc = 0 a[pc] = 5 > key -> pr = -1 pl <= pr 성립 x 반복 종료 
        pd = pr+1 = 0 
        memove 함수 발동
        a[pd=0]에서부터 i-pd = 3 - 0 갯수 만큼을 복사하고 즉, 3개 복사하고 
        -> 5 7 9 를 복사하고 
        a[pd + 1 = 1] 부터 붙여넣기하면 5 5 7 9 1 이됨  memmove 함수 끝! 
    */
//********************************************************************
		a[pd] = key; // << 맨 앞의 5를 key=4로 바꿔주면서 최종적으로 
        // 4 5 7 9 1 이 됨!!! 
	}
}

int main(void)
{
	int i, nx;
	int *x;		

	puts("이진 삽입 정렬");
	printf("요솟수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bin_insertion(x, nx);		

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	

	return 0;
}