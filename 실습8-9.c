// 문자열에서 문자 F를 검색하는 프로그램
#include <stdio.h>

// 문자열 s에서 문자 c를 검색하는 함수
int str_chr(const char *s, int c)
{
    int i = 0;
    c = (char)c;
    while (s[i] != c)
    { // c가 s[i]랑 일치하지 않으면 계속 반복!
        if (s[i] == '\0')
            return -1; // 검색 실패
        i++;
    }
    return i;
}

int main(void)
{
    char str[64]; // 이 문자열에서 검색
    char tmp[64];
    int ch; // 검색할 문자
    int idx;

    printf("문자열 : ");
    scanf("%s", str);
    printf("검색할 문자 : ");
    scanf("%s", tmp); // 먼저 문자열로 검색할 문자를 읽어 들입니다.
    ch = tmp[0];      // 첫번째 문자를 검색할 문자로 지정합니다.

    if ((idx = str_chr(str, ch)) == -1)
    {
        // 처음 나오는 문자를 검색합니다.
        printf("문자 '%c'는 문자열에 없습니다.\n", ch);
    }
    else
    {
        printf("문자 '%c'는 %d번째에 있습니다.\n", ch, idx + 1);
    }

    return 0;
}