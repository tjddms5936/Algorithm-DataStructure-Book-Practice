// ���� ���� ���� ����Ʈ(�ҽ�)
#include <stdio.h>
#include <stdlib.h>
#include "07_CircDblLinkedList.h"
#include "Member.h"

// 1���� ��带 �������� ����
static Dnode *AllocDNode(void){
    return calloc(1, sizeof(Dnode));
}

// ����� �� ��� ���� ����
static void SetNode(Dnode *n,  Member *x,  Dnode *prev, Dnode *next){
    n->data = *x; // ������
    n->prev = prev; // ���� ��忡 ���� ������
    n->next = next; // ���� ��忡 ���� ������
}

// ����Ʈ�� ����ִ��� �˻�
static int IsEmpty(const Dlist *list){
    return list->head->next == list->head;
}

// ����Ʈ�� �ʱ�ȭ
void Initialize(Dlist *list){
    Dnode *dummyNode = AllocDNode();
    list->head = list->crnt = dummyNode;
    dummyNode->prev = dummyNode->next = dummyNode; 
}

// ������ ����� �����͸� ���
void PrintCurrent(const Dlist *list){
    if(IsEmpty(list)){
        printf("������ ��尡 �����ϴ�.");
    }
    else{
        PrintMember(&list->crnt->data);
    }
}

// ������ ����� �����͸� ���(�� �ٲ� ���� �߰�)
void PrintLnCurrent(const Dlist *list){
    PrintCurrent(list);
    printf("\n");
}

// compare�Լ��� x�� ��ġ�ϴ� ��带 �˻�
Dnode *Search(Dlist *list, const Member *x, int compare(const Member *x, const Member *y)){
    /*
    ���� ��带 ����Ű�� ������ : list -> head
    �Ӹ� ��带 ����Ű�� ������ : list -> head -> next
    ���� ��带 ����Ű�� ������ : list -> head -> prev
    */
    Dnode *ptr = list->head->next; // �˻��� ������ list->head�� ����Ű�� ���̳�尡 �ƴ� �� ������� ���� �˻�
    while (ptr != list->head) // ��尡 1�����̰ų�, ��������϶����� 
    {
        if(compare(&ptr->data, x) == 0){
            // compare �Լ��� ���� ����� 0�̸� �˻� ���� 
            list->crnt = ptr;
            return ptr; // ���� ��� �˻� �Ϸ�
        }
        ptr = ptr->next; // ���� ���� �˻�
    }
    return NULL; // �˻� ���� 
}

// ��� ����� �����͸� ����Ʈ ������� ���
void Print(const Dlist *list){
    if(IsEmpty(list)){
        printf("��尡 �����ϴ�.");
    }
    else{
        Dnode *ptr = list->head->next; // ptr�� �Ӹ� �����! 
        printf("---��� ����---");
        while (ptr != list->head) // ptr�� ��������� �� ����!
        {
            PrintLnMember(&ptr->data);
            ptr = ptr->next; // ���� ��� ���� 
        }
        
    }
}

// ��� ����� �����͸� ����Ʈ ������ �������� ��� 
void PrintReverse(const Dlist *list){
    if(IsEmpty(list)){
        printf("��尡 �����ϴ�.");
    }
    else{
        Dnode *ptr = list->head->prev; // ���� ������ !! 
        while (ptr != list->head)
        {
            PrintLnMember(&ptr->data);
            ptr = ptr->prev; // ���� ��� �˻�! 
        }
        
    }
}

// ������ ��带 �������� ����
int Next(Dlist *list){
    if(IsEmpty(list) || list->crnt->next == list->head){
        // ����Ʈ�� ����ְų� || ������ ����� ���� ��尡 ���̳���� ��� ������ �� ����
        return 0;
    }
    list->crnt = list->crnt->next; // ������ ��带 �������� �ʱ�ȭ 
    return 1;
}

// ������ ��带 �������� ����
int Prev(Dlist *list){
    if(IsEmpty(list) || list->crnt->prev == list->head){
        // ����Ʈ�� ����ְų� || ������ ����� ���� ��尡 ���̳���� ��� �ǵ��� �� �� ����
        return 0;
    }
    list->crnt = list->crnt->prev; // ������ ��带 ���ʳ��� �ʱ�ȭ 
    return 1;
}

// p�� ����Ű�� ��� �ٷ� ���� ��带 ����
void InsertAfter(Dlist *list, Dnode *p, const Member *x){
    Dnode *ptr = AllocDNode();
    Dnode *nxt = p->next;
    p->next = p->next->prev = ptr; // ��
    SetNode(ptr, x, p, nxt);
    list->crnt = ptr; // ������ ��带 ����  
}

// �Ӹ��� ��带 ���� 
void InsertFront(Dlist *list, const Member *x){
    InsertAfter(list, list->head, x);
}

// ������ ��带 ���� 
void InsertRear(Dlist *list, const Member *x){
    InsertAfter(list, list->head->prev, x);
}

// p�� ����Ű�� ��带 ����
void Remove(Dlist *list, Dnode *p){
    p->prev->next = p->next;
    p->next->prev = p->prev;
    list->crnt = p->prev; // ������ ����� ���� ��带 ����
    free(p);
    if(list->crnt == list->head){
        // ������Ʈ�� ���õ� ��尡 ���̳�带 ����Ű�� �ִٸ� 
        list->crnt = list->head->next; // ���õ� ��带 �Ӹ� ���� ������Ʈ ! 
        /* �� �� ��찡 �ߵ��Ǵ� ���� 
        ���̳�� - (�Ӹ����)p��� - ������� �� ���
        p�� �����Ǹ鼭
        ���̳��(���õ� ���) - ������� �� �ǰ�  ���õ� ��带 ������Ʈ �������ν�
        ���̳�� - (���õ� ���)������� �� ����� �ذ� �� 
        */
    }
}

// �Ӹ� ��带 ����
void RemoveFront(Dlist *list){
    if(!IsEmpty(list)){
        // ����ִ°� �ƴϸ� ! 
        Remove(list, list->head->next); // �Ӹ���� ����
    }
}

// ���� ��带 ����
void RemoveRear(Dlist *list){
    if(!IsEmpty(list)){
        Remove(list, list->head->prev);
    }
}

// ������ ��带 ����
void RemoveCurrent(Dlist *list){
    if(list->crnt != list->head){
        // ������ ��尡 ���̳�尡 �ƴϸ�
        Remove(list, list->crnt);
    }
}

// ��� ��带 ����
void Clear(Dlist *list){
    while (!IsEmpty(list))
    {
        RemoveFront(list); // �� �� ������ �Ӹ���� ���� 
    }
    
}

// ���� ���� ���� ����Ʈ ����
void Terminate(Dlist *list){
    Clear(list); // ��� ��带 ����  �ϰ��� ���� ��常 ����
    free(list->head); // ���� ��带 ���� 
}


// �޴� 
typedef enum{
    TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT, RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, NEXT, PREV, CLEAR
}Menu;

// �޴� ����
Menu SelectMenu(void){
    int i, ch;
    char *mstring[] = {
        "�Ӹ��� ��带 ����", "������ ��带 ����", "�Ӹ� ��带 ����", "���� ��带 ����",
        "������ ��带 ���", "������ ��带 ����", "��ȣ�� �˻�", "�̸����� �˻�", "��� ��带 ���",
        "������ ��带 ��������", "������ ��带 ��������", "������ ��带 ��������", "��� ��带 ����"
    };
    do{
        for(i = TERMINATE; i < CLEAR; i++){
            printf("(%2d) %-22.22s ", i + 1, mstring[i]);
            if((i % 3) == 2){
                printf("\n");
            }
        }
        printf("(0) ���� : ");
        scanf("%d", &ch);
    }while(ch < TERMINATE || ch > CLEAR);
    return(Menu)ch;
}

int main(void){
    Menu menu;
    Dlist list;
    Initialize(&list); // ���� ���� ���� ����Ʈ�� �ʱ�ȭ
    do{
        Member x;
        switch (menu = SelectMenu())
        {
        case INS_FRONT:
            x = ScanMember("�Ӹ��� ����", MEMBER_NO | MEMBER_NAME);
            InsertFront(&list, &x);
            break;
        case INS_REAR:
            x = ScanMember("������ ����", MEMBER_NO | MEMBER_NAME);
            InsertRear(&list, &x);
            break;
        case RMV_FRONT:
            RemoveFront(&list);
            break;
        case RMV_REAR:
            RemoveRear(&list);
            break;
        case PRINT_CRNT:
            PrintLnCurrent(&list);
            break;
        case RMV_CRNT:
            RemoveCurrent(&list);
            break;
        case SRCH_NO:
            x = ScanMember("�˻�", MEMBER_NO);
            if(search(&list, &x, MemberNoCmp) != NULL){
                PrintLnCurrent(&list);
            }
            else{
                printf("�� ��ȣ�� �����Ͱ� �����ϴ�.");
            }
            break;
        case SRCH_NAME:
            x = ScanMember("�˻�", MEMBER_NAME);
            if(search(&list, &x, MemberNoCmp) != NULL){
                PrintLnCurrent(&list);
            }
            else{
                printf("�� �̸��� �����Ͱ� �����ϴ�.");
            }
            break;
        case PRINT_ALL:
            Print(&list);
            break;
        case NEXT:
            Next(&list);
            break;
        case PREV:
            Prev(&list);
            break;
        case CLEAR:
            Clear(&list);
            break;
        }
    }while(menu != TERMINATE);
    Terminate(&list);
    return 0;
}