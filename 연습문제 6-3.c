/*
Q&A 6-3 : 버블 정렬(버전2)의 아이디어는 배열이 정렬을 마쳤는지를 검사하는 데 응용 가능. 
전달받은 배열 a가 오름차순으로 정렬을 마쳤는지 검사하는 함수를 작성하세요.
이때 오름차순으로 정렬을 마친 상태라면 1, 그렇지 않으면 0을 반환하도록 작성하세요. 
*/
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)
int is_sorted(int a[], int n)
{
	int i;

	for (i = n - 1; i > 0; i--)
		if (a[i - 1] > a[i])
			return 0;
	return 1;
}

int main(void)
{
	int i, nx, sorted;
	int *x;		

	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	sorted = is_sorted(x, nx);		/* 諛곗뿴 x媛� �젙�젹�릺�뿀�뒗吏� �솗�씤 */

	if (sorted)
		puts("정렬을 마쳤습니다..");
	else
		puts("정렬이 끝나지 않았습니다..");

	free(x);	

	return 0;
}
