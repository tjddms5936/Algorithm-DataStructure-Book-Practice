#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

/*
선택 정렬의 경우 안정적이지 않다. 
EX) 3(left) 4 2 3(right) 1 를 정렬하면
1 2 3(right) 3(left) 4 가 된다. 
*/

void selection(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(int, a[i], a[min]);
    }
}

int main(void)
{
    int i, nx;
    int *x;
    printf("Insert Number of Elements : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("Do Sort Selection\n");
    selection(x, nx);
    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : %d\n", i, x[i]);
    }
    free(x);

    return 0;
}
