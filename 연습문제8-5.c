// 문자열에서 문자 F를 검색하는 프로그램
// strchr처럼 가장 앞쪽에 있는 c를 찾는데 이때 c는 null문자여도 됨.
// strchr은 찾은 문자에 대한 포인터를 반환함. 문자가 없으면 NULL포인터를 반환함.
#include <stdio.h>
#include <string.h>

// 문자열 s에서 문자 c를 검색하는 함수
char *str_chr(const char *s, int c)
{
    c = (char)c;
    while (*s != c)
    {
        // c가 없으면 계속 반복
        if (*s == '\0')
            return NULL; // 검색에 실패하면 NULL 반환
        s++;
    }
    return (char *)s; // 문자에 대한 포인터 반환 !
}

int main(void)
{
    char str[64]; // 이 문자열에서 검색
    char tmp[64];
    int ch; // 검색할 문자
    char *idx;

    printf("문자열 : ");
    scanf("%s", str);
    printf("검색할 문자 : ");
    scanf("%s", tmp); // 먼저 문자열로 검색할 문자를 읽어 들입니다.
    ch = tmp[0];      // 첫번째 문자를 검색할 문자로 지정합니다.

    if ((idx = str_chr(str, ch)) == NULL)
    {
        printf("문자 %c가 문자열 안에 없습니다.\n", ch);
    }
    else
    {
        printf("idx = %d, str = %d\nidx - str = %d\n", idx, str, idx - str);
        printf("문자 %c가 %d번째에 있습니다.\n", ch, (idx - str) + 1);
    }

    return 0;
}