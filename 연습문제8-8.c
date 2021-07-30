#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ��ҹ��ڸ� �������� �ʰ� �� ���ڿ��� ���ϴ� �Լ� 
int str_cmpic(const char *s1, const char *s2){
    while(toupper(*s1) == toupper(*s2)){
        if(*s1 == '\0') return 0;
    s1++;
    s2++;
    }
    return (unsigned char)toupper(*s1) - (unsigned char)toupper(*s2);
}

int str_ncmpic(const char *s1, const char *s2, size_t n){
    while(n && *s1 && *s2){
        if(toupper(*s1) != toupper(*s2)){
            return (unsigned char)toupper(*s1) - (unsigned char)toupper(*s2); 
        }
        s1++;
        s2++;
        n--;
    }
    if(!n) return 0;
    if(*s1) return toupper(*s1);
    return toupper(*s2);
}

int main(void){
    char st[128];
    puts("\"XXXX\"�� �Է��ϸ� �����մϴ�.");
    while(1){
        printf("���ڿ� st :"); scanf("%s", st);
        if(str_cmpic("XXXX", st) == 0){
            break;
        }
        else if(str_ncmpic("XXXX", st, 3) == 0){
            break;
        }
        puts("\"STRING\"�� ���ڸ� ���մϴ�.\n");
        printf("str_cmpic(\"STRING\", st) = %d\n", str_cmpic("STRING", st));
        puts("\n\"STRING\"�� ó�� 3���� ���ڸ� ���մϴ�.\n");
        printf("str_ncmpic(\"STRING\", st, 3) = %d\n", str_ncmpic("STRING", st, 3));
    }
    return 0;
}