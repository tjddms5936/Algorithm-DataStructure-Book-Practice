// Ŀ���� ���� ���� ����Ʈ(�ҽ�)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "ArrayLinkedList.h"

/*--- ȸ�� ��ȣ �� �Լ� ---*/
int MemberNoCmp(const Member *x, const Member *y)
{
	return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

/*--- ȸ�� �̸� �� �Լ� ---*/
int MemberNameCmp(const Member *x, const Member *y)
{
	return strcmp(x->name, y->name);
}

/*--- ȸ�� ������(��ȣ�� �̸�)�� ǥ��(�� �ٲ� ����) ---*/
void PrintMember(const Member *x)
{
	printf("%d %s", x->no, x->name);
}

/*--- ȸ�� ������(��ȣ�� �̸�)�� ǥ��(�� �ٲ� ����) ---*/
void PrintLnMember(const Member *x)
{
	printf("%d %s\n", x->no, x->name);
}

/*--- ȸ�� ������(��ȣ�� �̸�)�� �о� ���� ---*/
Member ScanMember(const char *message, int sw)
{
	Member temp;
	printf("%s�ϴ� �����͸� �Է��ϼ���.\n", message);
	if (sw & MEMBER_NO) { printf("��ȣ : "); scanf("%d", &temp.no); }
	if (sw & MEMBER_NAME) { printf("�̸� : "); scanf("%s", temp.name); }
	return temp;
}

// ������ ���ڵ��� �ε����� ���� ���� ��ȯ 
static Index GetIndex(List *list){
    if(list->deleted == NULL){
        // ������ ���ڵ尡 ���� ���
        return ++(list->max);
    }
    else{
        Index rec = list->deleted;
        list->deleted = list->n[rec].Dnext;
        return rec;
    }
}

// ������ ���ڵ带 ���� ����Ʈ�� ���
static void DeleteIndex(List *list, Index idx){
    if(list->deleted == NULL){
        // ������ ���ڵ尡 ���� ���
        list->deleted = idx;
        list->n[idx].Dnext = NULL;
    }
    else{
        Index ptr = list->deleted;
        list->deleted = idx;
        list->n[idx].Dnext = ptr;
    }
}

// n�� ����Ű�� ����� �� ����� ���� ����
static void SetNode(Node *n, const Member *x, Index next){
    n->data = *x; // ������
    n->next = next; // ���� ��忡 ���� ������
}

// ���� ����Ʈ�� �ʱ�ȭ
void Initialize(List *list, int size){
    list->n = calloc(size, sizeof(Node));
    list->head = NULL; // �Ӹ� ���
    list->crnt = NULL; // ������ ���
    list->max = NULL; 
    list->deleted = NULL; 
}

// compare �Լ��� x�� ��ġ�ϴ� ��� �˻�
Index search(List *list, const Member *x, int compare(const Member *x, const Member *y)){
    Index ptr = list->head;
    while(ptr != NULL){
        if(compare(&list->n[ptr].data, x) == 0){
            list->crnt = ptr;
            return ptr; // �˻� ����
        }
        ptr = list->n[ptr].next;
    }
    return NULL; // �˻� ���� 
}

// �Ӹ��� ��带 ����
void InsertFront(List *list, const Member *x){
    Index ptr = list->head;
    list->head = list->crnt = GetIndex(list);
    SetNode(&list->n[list->head], x, ptr);
}

// ������ ��带 ����
void InsertRear(List *list, const Member *x){
    if(list->head == NULL){
        // ��� �ִ� ���
        InsertFront(list, x); // �Ӹ��� ����
    }
    else{
        Index ptr = list->head;
        while(list->n[ptr].next != NULL){
            ptr = list->n[ptr].next;
            list->n[ptr].next = list->crnt = GetIndex(list);
            SetNode(&list->n[list->n[ptr].next], x, NULL);
        }
    }
}

// �Ӹ� ��带 ����
void RemoveFront(List *list){
    if(list->head != NULL){
        // ��� ���� ���� ���
        Index ptr = list->n[list->head].next;
        DeleteIndex(list, list->head);
        list->head = list->crnt = ptr;
    }
}

// ���� ��带 ����
void RemoveRear(List *list){
    if(list->head != NULL){
        // ��� ���� ���� ���
        if(list->n[list->head].next == NULL){
            // ��尡 1���� �ִٸ�
            RemoveFront(list); // �Ӹ� ��带 �����ϸ� ��. 
        }
        else{
            Index ptr = list->head;
            Index pre;
            while(list->n[ptr].next != NULL){
                // ���� ��尡 �ִٸ� ��� �ݺ��ϸ鼭 
                pre = ptr; 
                ptr = list->n[ptr].next; 
                // while���� ���� �� pre�� ���� ��尡 �� ptr = NULL�� ��
            }
            list->n[pre].next = NULL; // ���� ����� next �����ʹ� NULL�� �ʱ�ȭ
            DeleteIndex(list, ptr); // ���� ����Ʈ�� NULL ����?;;
            list->crnt = pre; 
        }
    }
}

// ������ ��带 ����
void RemoveCurrent(List *list){
    if(list->crnt == list->head){
        // �Ӹ� ��尡 ���õǾ� ������
        RemoveFront(list); // �Ӹ� ��带 ����
    }
    else{
        Index ptr = list->head;
        while(list->n[ptr].next != list->crnt){
            // �Ӹ� ������ crnt ��� �������� ���鼭
            ptr = list->n[ptr].next; // �Ӹ������� �ϳ��� ���� ���� �ʱ�ȭ
        }
        // while���� ���� �� ptr�� ������ ����� �� ��� 
        list->n[ptr].next = list->n[list->crnt].next; 
        /* ������ ptr��� -> ������ ��� -> ���� ��� ���̾��µ� ������ ��� ������ �Ŵϱ�
            ptr��� -> ���� ��� �� ����� ���� �۾� */
        DeleteIndex(list, list->crnt);
        list->crnt = ptr; 
    }
}

// ��� ��带 ����
void Clear(List *list){
    while(list->head != NULL){
        // �� �� ������
        RemoveFront(list); // �Ӹ� ��带 ���� 
    }
    list->crnt = NULL; 
}

// ������ ����� �����͸� ��� 
void PrintCurrent(const List *list){
    if(list->crnt == NULL){
        // ������ ��尡 ���ٸ�
        printf("������ ��尡 �����ϴ�.");
    }
    else{
        PrintMember(&list->n[list->crnt].data); 
    }
}

// ������ ����� �����͸� ���(�� �ٲ� ���� �߰�)
void PrintLnCurrent(const List *list){
    PrintCurrent(list);
    printf("\n");
}

// ��� ����� �����͸� ���
void Print(const List *list){
    if(list->head == NULL){
        printf("��尡 �����ϴ�.");
    }
    else{
        Index ptr = list->head;
        printf("---��� ����---");
        while(ptr != NULL){
            // ptr�� ���� ��尡 �� �� ����
            PrintLnMember(&list->n[ptr].data); // ptr��� ����ϰ�
            ptr = list->n[ptr].next; // ptr�� ���� ���� �ʱ�ȭ
        }
    }
}

// ���� ����Ʈ ����
void Terminate(List *list){
    Clear(list); // �ϴ� ��� ��带 �����ϰ�
    free(list->n); // ������Ŵ
}