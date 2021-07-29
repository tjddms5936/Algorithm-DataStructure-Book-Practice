#include <stdio.h>
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

int main(void)
{
    char *s1 = "ABCD";
    char *s2 = "EFGH";

    printf("포인터 s1은 \"%s\"를 가리킵니다.\n", s1);
    printf("포인터 s2은 \"%s\"를 가리킵니다.\n", s2);
    printf("s1의 총 배열의 길이는 %d입니다.", sizeof(s1) / sizeof(s1[0]));

    swap(char *, s1, s2);

    printf("서로 교환하였습니다.\n");
    printf("포인터 s1은 \"%s\"를 가리킵니다.\n", s1);
    printf("포인터 s2은 \"%s\"를 가리킵니다.\n", s2);

    return 0;
}