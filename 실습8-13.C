// KMP법으로 문자열을 검색
#include <stdio.h>
#include <string.h>

int kmp_match(const char txt[], const char pat[]){
    int pt = 1; // txt 커서
    int pp = 0; // pat 커서
    int skip[1024]; // 건너뛰기 표

    // 표 만들기
    skip[pt] = 0;
    while((pat[pt]) != '\0'){
        if(pat[pt] == pat[pp]){
            skip[++pt] = ++pp;
        }
        else if(pp = 0){
            skip[++pt] = pp;
        }
        else{
            pp = skip[pp];
        }
    }
    // ------------- 표 생성 완료 --------------
    // 검색
    pt = pp = 0;
    while(txt[pt] != '\0' && pat[pp] != '\0'){
        if(txt[pt] == pat[pp]){
            pt++; pp++;
        }
        else if(pp == 0){
            pt++;
        }
        else{
            pp = skip[pp];
        }
    }
    if(pat[pp] == '\0'){
        return pt - pp;
    }
    return -1; // 검색 실패 
}

int main(void){
    int idx;
    char txt[256];
    char pat[256];
    puts("KMP법"); 
    printf("텍스트 : ");
    scanf("%s", txt);
    printf("패턴 : ");
    scanf("%s", pat);
    idx = kmp_match(txt, pat); // 텍스트(s1)에서 패턴(s2)을 브루트-포스법으로 검색합니다.

    if(idx == -1){
        printf("텍스트에 패턴이 없습니다.");
    }
    else{
        printf("%d번째 문자부터 match합니다.", idx + 1);
    }
    return 0;
}