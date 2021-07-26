#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)


/*--- 2의 n 제곱을 구합니다. ---*/
static int pow2(int n)
{
	int k = 1;

	while (n--)
		k *= 2;
	return (k);
}

/*--- 힙 출력 ---*/
static void disp_heap(int a[], int n)
{
	int i, w, level;
	int height = 1;		/* 트리의 높이 */

	i = n;
	while (i /= 2)
		height++;

	i = 0;
	w = 1;
	for (level = 0; level < height; level++) {
		int k;
		printf("%*s", pow2(height - level) - 2, ""); 
        /*  %*s : 출력값 뒤에 공백을 설정해주기 위한 함수
         level = 0 인경우 14칸을 띄워 주겠다 의미. 
         즉 첫 줄에서 14칸 띄고  */
		for (k = 0; k < w; k++) {
			printf("%02d", a[i++]);  // a[0] 출력하고 i 1증가
			if (i >= n) goto Exit; // i가 요소개수 이상이되면 Exit
			printf("%*s", pow2(height - level + 1) - 2, "");
            /* level = 0이니까 14칸 띔
            현재 14칸 공백 a[0] 14칸 공백 인것. 
            현재 i = 1인 상태 
            */

		}
		putchar('\n'); // 첫 줄 완성하고 한 줄 띄고

		printf("%*s", pow2(height - level) - 3, ""); // 13칸 공백하고
		for (k = 0; k < w; k++) { // 현재 w = 1 -> /이든＼이든 한번씩만 출력함
			if (2 * k + i     < n) printf("／"); 
            /* 
            2*k+1<n 이라는 것은 ? 
            1층인 경우 k는 한 번 돌아서 / 1번 출력
            2층인 경우 k는 0, 1 두 번 돌아서 / 2번 출력
            3층인 경우 k는 0, 1, 2, 3 네번 돌아서 / 4번 출력
            1~10 까지 있다고 치면 마지막 층 즉, 3층인 경우 n = 10
            2*2 + i=6 !< 10 이니까 k는 두번만 돌아서 / 2번 출력!

            왜 i=6? : 3층 다 출력하고 나면 위의 for문에 의해서 a[6]까지 출력한거니까!
            (아직 4층 출력 전임.)

            */
			if (2 * k + i + 1 < n) printf("＼");
			printf("%*s", pow2(height - level + 1) - 4, "");
		}
		putchar('\n');
		w *= 2; // 층이 하나씩 늘어날 때마다 줄은 최대 1 -> 2-> 4 처럼 늘어남
	}
Exit:
	putchar('\n');
	putchar('\n');
}

static void downhip(int a[], int left, int right){
    int temp = a[left];
    int child, parent;
    for(parent = left; parent < (right +1)/2; parent = child){
        int cl = parent * 2 + 1; // 왼쪽자식 인덱스
        int cr = cl + 1; // 오른쪽 자식 인덱스
        child = (cr <= right && a[cr] > a[cl] ? cr : cl); // 큰 값을 선택
        if(temp >= a[child]){
            break;
        }
        a[parent] = a[child];
    }
    a[parent] = temp; 
}

// 힙 정렬 함수 
void heapsort(int a[], int n){
    int i;
    puts("배열을 힙으로 만듭니다.\n");
    for(i = (n-1)/2; i >= 0; i--){
        disp_heap(a, n);
        downhip(a, i, n-1);
    }
    puts("힙을 기준으로 정렬합니다.\n");
    for(i = n-1; i >0; i--){
        swap(int, a[0], a[i]); // 루트랑 제일 마지막이랑 바꿔줌
        disp_heap(a, n);
        downhip(a, 0, i-1); 
    }
}

int main(void){
    int i, nx;
    int *x;
    printf("힙 정렬\n요소 개수 :"); scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for(i = 0; i<nx; i++){
        printf("x[%d] : ", i); scanf("%d", &x[i]);
    }

    heapsort(x, nx); // 배열 x를 힙 정렬 
    puts("오름차순으로 정렬 하였습니다.\n");
    for(i=0; i<nx; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x); 

    return 0;
}