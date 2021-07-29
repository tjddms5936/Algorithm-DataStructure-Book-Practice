// 저장한 문자열을 출력합니다. 
// \0은 문자열의 끝을 나타내는 널 문자이다. 실제로 널 문자 이후에 문자를 대입했을때 어떻게 나오는지 확인해보자 
#include <stdio.h>

int main(void){
    char st[10];
    st[0] = 'A';
    st[1] = 'B';
    st[2] = 'C';
    st[3] = 'D';
    st[4] = '\0';
    st[5] = 'P';
    printf("문자열 st에는 \"%s\"가 들어 있습니다..\n", st);

    return 0;
}