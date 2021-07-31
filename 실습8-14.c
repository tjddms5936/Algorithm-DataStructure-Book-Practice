// Boyer-Moore법으로 문자열을 검색하는 프로그램 
#include <stdio.h>
#include <string.h>
#include <limits.h> // UCHAR_MAX가 정의되어 있는 라이브러리 

// Boyer-Moore법으로 문자열을 검색하는 함수
int bm_match(const char txt[], const char pat[]){
    int pt; // txt 커서
    int pp; // pat 커서
    int txt_len = strlen(txt); // txt문자 개수
    int pat_len = strlen(pat); // pat문자 개수 
    int skip[UCHAR_MAX + 1]; // 건너 뛰기 표 
    
    for(pt = 0; pt <= UCHAR_MAX; pt++){
        // 건너뛰기 표 만들기
        skip[pt] = pat_len; // 
    }
    for(pt = 0; pt < pat_len-1; pt++){
        skip[pat[pt]] = pat_len - pt - 1;
    }

    // pt == pat_len -1

    while(pt < txt_len){
        pp = pat_len -1; // pat의 마지막 문자부터 검사 
        while(txt[pt] == pat[pp]){
            if(pp == 0){
                return pt;
            }
            pp--;
            pt--;
        }
        pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp; 
    }
    return -1; 
}

int main(void){
    int idx;
    char s1[256]; // 텍스트
    char s2[256]; // 패턴
    printf("Boyer-Moore법");
    printf("텍스트 :"); scanf("%s", s1);
    printf("패턴 :"); scanf("%s", s2);

    idx = bm_match(s1, s2); // 문자열 s1에서 문자열 s2를 Boyer-Moore법을 사용해 검색 
    if(idx == -1){
        printf("텍스트에 패턴이 없습니다.");
    }
    else{
        printf("%d번째 문자부터 match합니다.\n", idx + 1);
    }

    return 0;
}