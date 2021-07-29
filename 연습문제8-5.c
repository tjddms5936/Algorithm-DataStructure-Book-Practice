// ���ڿ����� ���� F�� �˻��ϴ� ���α׷�
// strchró�� ���� ���ʿ� �ִ� c�� ã�µ� �̶� c�� null���ڿ��� ��.
// strchr�� ã�� ���ڿ� ���� �����͸� ��ȯ��. ���ڰ� ������ NULL�����͸� ��ȯ��.
#include <stdio.h>
#include <string.h>

// ���ڿ� s���� ���� c�� �˻��ϴ� �Լ�
char *str_chr(const char *s, int c)
{
    c = (char)c;
    while (*s != c)
    {
        // c�� ������ ��� �ݺ�
        if (*s == '\0')
            return NULL; // �˻��� �����ϸ� NULL ��ȯ
        s++;
    }
    return (char *)s; // ���ڿ� ���� ������ ��ȯ !
}

int main(void)
{
    char str[64]; // �� ���ڿ����� �˻�
    char tmp[64];
    int ch; // �˻��� ����
    char *idx;

    printf("���ڿ� : ");
    scanf("%s", str);
    printf("�˻��� ���� : ");
    scanf("%s", tmp); // ���� ���ڿ��� �˻��� ���ڸ� �о� ���Դϴ�.
    ch = tmp[0];      // ù��° ���ڸ� �˻��� ���ڷ� �����մϴ�.

    if ((idx = str_chr(str, ch)) == NULL)
    {
        printf("���� %c�� ���ڿ� �ȿ� �����ϴ�.\n", ch);
    }
    else
    {
        printf("idx = %d, str = %d\nidx - str = %d\n", idx, str, idx - str);
        printf("���� %c�� %d��°�� �ֽ��ϴ�.\n", ch, (idx - str) + 1);
    }

    return 0;
}