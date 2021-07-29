#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)


/*--- 2�� n ������ ���մϴ�. ---*/
static int pow2(int n)
{
	int k = 1;

	while (n--)
		k *= 2;
	return (k);
}

/*--- �� ��� ---*/
static void disp_heap(int a[], int n)
{
	int i, w, level;
	int height = 1;		/* Ʈ���� ���� */

	i = n;
	while (i /= 2)
		height++;

	i = 0;
	w = 1;
	for (level = 0; level < height; level++) {
		int k;
		printf("%*s", pow2(height - level) - 2, ""); 
        /*  %*s : ��°� �ڿ� ������ �������ֱ� ���� �Լ�
         level = 0 �ΰ�� 14ĭ�� ��� �ְڴ� �ǹ�. 
         �� ù �ٿ��� 14ĭ ���  */
		for (k = 0; k < w; k++) {
			printf("%02d", a[i++]);  // a[0] ����ϰ� i 1����
			if (i >= n) goto Exit; // i�� ��Ұ��� �̻��̵Ǹ� Exit
			printf("%*s", pow2(height - level + 1) - 2, "");
            /* level = 0�̴ϱ� 14ĭ ��
            ���� 14ĭ ���� a[0] 14ĭ ���� �ΰ�. 
            ���� i = 1�� ���� 
            */

		}
		putchar('\n'); // ù �� �ϼ��ϰ� �� �� ���

		printf("%*s", pow2(height - level) - 3, ""); // 13ĭ �����ϰ�
		for (k = 0; k < w; k++) { // ���� w = 1 -> /�̵硬�̵� �ѹ����� �����
			if (2 * k + i     < n) printf("��"); 
            /* 
            2*k+1<n �̶�� ���� ? 
            1���� ��� k�� �� �� ���Ƽ� / 1�� ���
            2���� ��� k�� 0, 1 �� �� ���Ƽ� / 2�� ���
            3���� ��� k�� 0, 1, 2, 3 �׹� ���Ƽ� / 4�� ���
            1~10 ���� �ִٰ� ġ�� ������ �� ��, 3���� ��� n = 10
            2*2 + i=6 !< 10 �̴ϱ� k�� �ι��� ���Ƽ� / 2�� ���!

            �� i=6? : 3�� �� ����ϰ� ���� ���� for���� ���ؼ� a[6]���� ����ѰŴϱ�!
            (���� 4�� ��� ����.)

            */
			if (2 * k + i + 1 < n) printf("��");
			printf("%*s", pow2(height - level + 1) - 4, "");
		}
		putchar('\n');
		w *= 2; // ���� �ϳ��� �þ ������ ���� �ִ� 1 -> 2-> 4 ó�� �þ
	}
Exit:
	putchar('\n');
	putchar('\n');
}

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
    puts("�迭�� ������ ����ϴ�.\n");
    for(i = (n-1)/2; i >= 0; i--){
        disp_heap(a, n);
        downhip(a, i, n-1);
    }
    puts("���� �������� �����մϴ�.\n");
    for(i = n-1; i >0; i--){
        swap(int, a[0], a[i]); // ��Ʈ�� ���� �������̶� �ٲ���
        disp_heap(a, n);
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