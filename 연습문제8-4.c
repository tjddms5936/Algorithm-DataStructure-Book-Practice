#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[256];
    printf("문자열 :");
    scanf("%s", str);
    printf("이 문자열의 길이는 %d입니다.\n", strlen(str));

    return 0;
}