/* Q1 �ǽ� 7-2 ���α׷�(IntSet.c)�� 8�� �Լ� �߰� */
#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

/*--- �� ǥ�ð� �ִ� �Լ��� ���� �߰��� 8���� �Լ� �Դϴ�. ---*/

int Initialize(IntSet *s, int max)
{
	s->num = 0;
	if ((s->set = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;								
		return -1;
	}
	s->max = max;
	return 0;
}

int IsMember(const IntSet *s, int n)
{
	int i;

	for (i = 0; i < s->num; i++)
		if (s->set[i] == n)
			return i;			
	return -1;					
}

/*--- �� ������ ���� á�ٸ� 1, �ƴϸ� 0�� ��ȯ ---*/
int IsFull(const IntSet *s)
{
	return s->num >= s->max;
}

void Add(IntSet *s, int n)
{
	if (s->num < s->max && IsMember(s, n) == -1)	
		s->set[s->num++] = n;						
}

void Remove(IntSet *s, int n)
{
	int idx;

	if ((idx = IsMember(s, n)) != -1) {
		s->set[idx] = s->set[--s->num];	
	}
}

int Capacity(const IntSet *s)
{
	return s->max;
}

int Size(const IntSet *s)
{
	return s->num;
}

void Assign(IntSet *s1, const IntSet *s2)
{
	int i;
	int n = (s1->max < s2->num) ? s1->max : s2->num;	

	for (i = 0; i < n; i++)
		s1->set[i] = s2->set[i];
	s1->num = n;
}

int Equal(const IntSet *s1, const IntSet *s2)
{
	int i, j;

	if (Size(s1) != Size(s2))
		return 0;

	for (i = 0; i < s1->num; i++) {
		for (j = 0; j < s2->num; j++)
			if (s1->set[i] == s2->set[j])
				break;
		if (j == s2->num)
			return 0;
	}
	return 1;
}

IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i;

	Assign(s1, s2);
	for (i = 0; i < s3->num; i++)
		Add(s1, s3->set[i]);

	return s1;
}

IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i, j;

	s1->num = 0;			/* s1�������˪��� */
	for (i = 0; i < s2->num; i++)
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				Add(s1, s2->set[i]);
	return s1;
}

IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i, j;

	s1->num = 0;			/* s1�������˪��� */
	for (i = 0; i < s2->num; i++) {
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				break;
		if (j == s3->num)
			Add(s1, s2->set[i]);
	}
	return s1;
}

/*--- �� ���� s2, s3�� ��Ī ���� s1�� �����ϴ� �Լ� ---*/
IntSet *SymmetricDifference(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i;

	s1->num = 0;			/* s1�� ���������� */

	for (i = 0; i < s2->num; i++)
		if (IsMember(s3, s2->set[i]) == -1)
			Add(s1, s2->set[i]);

	for (i = 0; i < s3->num; i++)
		if (IsMember(s2, s3->set[i]) == -1)
			Add(s1, s3->set[i]);

	return s1;
}

/*--- �� ���� s1�� s2�� ��� ���Ҹ� �߰��ϴ� �Լ�(s1 ������ ��ȯ) ---*/
IntSet *ToUnion(IntSet *s1, const IntSet *s2)
{
	int i;

	for (i = 0; i < s2->num; i++)
		Add(s1, s2->set[i]);

	return s1;
}

/*--- �� ���� s1���� s2�� ��� ���� ���� ��� ���Ҹ� �����ϴ� �Լ�(s1 ������ ��ȯ) ---*/
IntSet *ToIntersection(IntSet *s1, const IntSet *s2)
{
	int i = 0;

	while (i < s1->num) {
		if (IsMember(s2, s1->set[i]) == -1)
			Remove(s1, s1->set[i]);
		else
			i++;
	}
	return s1;
}

/*--- �� ���� s1���� s2�� ��� �ִ� ��� ���Ҹ� �����ϴ� �Լ�(s1 ������ ��ȯ) ---*/
IntSet *ToDifference(IntSet *s1, const IntSet *s2)
{
	int i;

	for (i = 0; i < s2->num; i++)
		Remove(s1, s2->set[i]);

	return s1;
}

/*--- �� ���� s1�� s2�� �κ������̸� 1, �ƴϸ� 0�� ��ȯ ---*/
int IsSubset(const IntSet *s1, const IntSet *s2)
{
	int i, j;

	for (i = 0; i < s1->num; i++) {
		for (j = 0; j < s2->num; j++)
			if (s1->set[i] == s2->set[j])
				break;
		if (j == s2->num)					
			return 0;
	}
	return 1;
}

/*--- �� ���� s1�� s2�� ���κ������̸� 1, �ƴϸ� 0�� ��ȯ ---*/
int IsProperSubset(const IntSet *s1, const IntSet *s2)
{
	int i;

	if (s1->num >= s2->num)					
		return 0;							

	return IsSubset(s1, s2);
}

void Print(const IntSet *s)
{
	int i;

	printf("{ ");
	for (i = 0; i < s->num; i++)
		printf("%d ", s->set[i]);
	printf("}");
}

void PrintLn(const IntSet *s)
{
	Print(s);
	putchar('\n');
}

/*--- �� ������ ��� ���Ҹ� �����ϴ� �Լ� ---*/
void Clear(IntSet *s)
{
	s->num = 0;
}

void Terminate(IntSet *s)
{
	if (s->set != NULL) {
		free(s->set);							
		s->max = s->num = 0;
	}
}

enum { ADD, RMV, SCH};

// ������ �Է�
int scan_data(int sw){
    int data;
    switch (sw)
    {
    case ADD : printf("�߰��� ������ : ");
        break;
    case RMV : printf("������ ������ :"); 
        break;
    case SCH : printf("�˻��� ������ :"); 
        break;
    }
    scanf("%d", &data);

    return data;
}

int main(void){
    IntSet s1, s2, temp;
    Initialize(&s1, 512);
    Initialize(&s2, 512);
    Initialize(&temp, 512);

    while(1){
        int m, x, idx;

        printf("s1 ="); PrintLn(&s1);
        printf("s2 ="); PrintLn(&s2);
        printf("(1)s1�� �߰� (2)s1���� ���� (3)s1���� �˻� (4)s1-s2 (5)���� ����\n"
            "(6)s2�� �߰� (7)s2���� ���� (8)s2���� �˻� (9)s2-21 (0)���� : ");

        scanf("%d", &m);
        if(m == 0) break;
        switch (m)
        {
        case 1: 
            x = scan_data(ADD); Add(&s1, x); // �߰� 
            break;
        case 2:
            x = scan_data(RMV); Remove(&s1, x); // ����
            break;
        case 3:
            x = scan_data(SCH); idx = IsMember(&s1, x); // �˻�
            printf("s1�� ��� ��%s\n", idx >= 0 ? "���ϴ�." : "�� �ʽ��ϴ�."); 
            break;
        case 4:
            Assign(&s1, &s2);
            break;
        case 5:
            printf("s1 == s2 = %s\n", Equal(&s1, &s2) ? "True" : "False");
            printf("s1 & s2 = "); Intersection(&temp, &s1, &s2);
            PrintLn(&temp);
            printf("s1 : s2 = "); Union(&temp, &s1, &s2);
            PrintLn(&temp);
            printf("s1 & s2 = "); Difference(&temp, &s1, &s2);
            PrintLn(&temp);
            break;
        case 6:
            x = scan_data(ADD); Add(&s2, x);
            break;
        case 7:
             x = scan_data(RMV); Remove(&s2, x); // ����
            break;
        case 8:
            x = scan_data(SCH); idx = IsMember(&s2, x); // �˻�
            printf("s1�� ��� ��%s\n", idx >= 0 ? "���ϴ�." : "�� �ʽ��ϴ�."); 
            break;
        case 9 :
            Assign(&s2, &s1);
            break;
        }
    }

    Terminate(&s1);
    Terminate(&s2);
    Terminate(&temp);
    return 0;
}