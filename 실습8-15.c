// strstr �Լ��� ����� ���α׷�  // string.h�� ����Ǿ��ִ� ���ڿ� Ž�� �Լ� 
#include <stdio.h>
#include <string.h>

int main(void){
    char s1[256], s2[256];
    char *p;
    printf("strstr �Լ�\n");
    printf("�ؽ�Ʈ : "); scanf("%s", s1);
    printf("���� : "); scanf("%s", s2);
    p = strstr(s1, s2); 
    /* ���ڿ� s1���� ���ڿ� s2�� �˻�
    �̶� strstr�� ù ��° ���ڿ��� ���� �����͸� ��ȯ�Ѵ�. ã�� ���ϸ� NULL ��ȯ 
    */ 
    if(p == NULL){
        printf("�ؽ�Ʈ�� ������ �����ϴ�.\n");
    }
    else{
        int ofs = p - s1;
        printf("\n%s\n", s1);
        printf("%*s|\n", ofs, "");
        printf("%*s%s\n", ofs, "", s2);
    }

    return 0;
}