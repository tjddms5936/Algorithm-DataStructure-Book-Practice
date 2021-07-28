// ��Ʈ ���ͷ� ���� ���� ǥ��
#include <stdio.h>
#include "BitSet.h"


// ���� s�� n�� ��� �ִ��� Ȯ��
int IsMember (BitSet s, int n){
    return s & SetOf(n);
}

// ���� s�� n�� �߰� 
void Add (BitSet *s, int n){
    *s |= SetOf(n);
}

// ���� s�� n���� ���� 
void Remove(BitSet *s, int n){
    *s &= ~SetOf(n);
}

// ���� s�� ���� ������ ��ȯ 
int Size(BitSet s){
    int n = 0;
    for(; s != BitSetNull; n++){
        s &= s - 1;
    }
    return n;
}

// ���� s�� ��� ���Ҹ� ���
void Print(BitSet s){
    int i;
    printf("{");
    for(i=0; i < BitSetBits; i++){
        if(IsMember(s, i)){
            printf("%d ", i);
        }
    }
    printf("}");
}

// ���� s�� ��� ���Ҹ� ���(�� �ٲ� ���ڵ� ����)
void PrintLn(BitSet s){
    Print(s);
    printf("\n");
}

enum {ADD, RMV, SCH};

// ������ �Է� 
int scan_data(int sw){
    int data;
    switch (sw)
    {
    case ADD :
        printf("�߰��� ������ : ");
        break;
    case RMV :
        printf("������ ������ : ");
        break;
    case SCH :
        printf("�˻��� ������ : ");
        break;
    }
    scanf("%d", &data);
    return data;
}

int main(void){
    BitSet s1 = BitSetNull;
    BitSet s2 = BitSetNull;
    while(1){
        int m, x, idx;

        printf("s1 = "); PrintLn(s1);
        printf("s2 = "); PrintLn(s2);
        printf("(1)s1�� �߰� (2)s1���� ���� (3)s1���� �˻� (4)s1 <- s2 (5)���� ����\n"
            "(6)s2�� �߰� (7)s2���� ���� (8)s2���� �˻� (9)s2 <- s1 (0)���� : ");
        scanf("%d", &m);

        if(m == 0) break;
        switch (m)
        {
        case 1 :
            x = scan_data(ADD); Add(&s1, x);
            break;
        case 2 :
            x = scan_data(RMV); Remove(&s1, x);
            break;
        case 3 :
            x = scan_data(SCH); idx = IsMember(s1, x);
            printf("s1�� ��� ��%s", idx != 0 ? "���ϴ�." : "�� �ʽ��ϴ�.");
            break;
        case 4 :
            s1 = s2; // s2�� s1�� ����
            break;
        case 5 :
            printf("s1 == s2 = %s\n", s1 == s2 ? "true" : "false");
            printf("s1 & s2 = "); PrintLn(s1 & s2);
            printf("s1 | s2 = "); PrintLn(s1 | s2);
            printf("s1 - s2 = "); PrintLn(s1 & ~s2);
            printf("s1�� s2�� ��Ī ������ = "); PrintLn((s1 & ~s2) | (~s1 & s2));
            break;
        case 6 :
            x = scan_data(ADD); Add(&s2, x);
            break;
        case 7 :
            x = scan_data(RMV); Remove(&s2, x);
            break;
        case 8 :
            x = scan_data(SCH); idx = IsMember(s1, x);
            printf("s2�� ��� ��%s", idx != 0 ? "���ϴ�." : "�� �ʽ��ϴ�.");
            break;
        case 9 :
            s2 = s1; // s1�� s2�� ����
            break;
        }
        
    }

    return 0;
}