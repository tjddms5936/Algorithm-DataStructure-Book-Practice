#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[256];
    printf("���ڿ� :");
    scanf("%s", str);
    printf("�� ���ڿ��� ���̴� %d�Դϴ�.\n", strlen(str));

    return 0;
}