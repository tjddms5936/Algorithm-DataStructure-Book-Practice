// strcmp함수와 동일하게 작동하는 문자열 비교함수
#include <stdio.h>

// 두 문자열 s1과 s2를 비교하는 함수
int str_cmp(const char *s1, const char *s2){
    while(*s1 == *s2){
        if(*s1 == '\0'){
            return 0; // 같음
        }
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
    // 같지 안핟면 차이값 반환(컴퓨터 환경에 따라 다름)
}

int main(void){
    char st[128];
    puts("\"ABCD\"와 비교합니다.");
    puts("\"XXXX\"면 종료합니다.");
    while(1){
        printf("문자열 st :");
        scanf("%s", st);
        if(str_cmp("XXXX", st) == 0){
            break;
        }
        printf("str_cmp(\"ABCD\",st) = %d\n", str_cmp("ABCD", st));
    }
    return 0;
}