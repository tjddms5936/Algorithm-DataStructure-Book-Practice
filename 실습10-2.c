// �����˻�Ʈ�� ���α׷�(�ҽ�)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "01_BinTree.h"

// ��带 �������� �Ҵ�
static BinNode *AllocBinNode(void){
    return calloc(1, sizeof(BinNode));
}

// ��� ����� �� ����
static void SetBinNode(BinNode *n, const Member *x, BinNode *left, BinNode *right){
    n->data = *x; // ������
    n->left = left; // ���� �ڽ� ��忡 ���� ������
    n->right = right; // ������ �ڽ� ��忡 ���� ������ 
}

// �˻�
BinNode *Search(BinNode *p, const Member *x){
    int cond;
    if(p == NULL){
        return NULL;
    }
    else if((cond = MemberNoCmp(x, &p->data)) == 0){
        return p; // �˻� ����
    }
    else if(cond < 0){
        Search(p->left, x); // ���� ���� Ʈ������ �˻�
    }
    else{
        Search(p->right, x); // ������ ���� Ʈ������ �˻� 
    }
}

// ��� ����
BinNode *Add(BinNode *p, const Member *x){
    int cond;
    if(p==NULL){
        p = AllocBinNode();
        SetBinNode(p, x, NULL, NULL);
    }
    else if((cond = MemberNoCmp(x, &p->data)) == 0){
        printf("���� : %d�� �̹� ��ϵǾ� �ֽ��ϴ�.\n", x->no);
    }
    else if(cond < 0){
        p->left = Add(p->left, x);
    }
    else{
        p->right = Add(p->right, x);
    }
    return p; 
}

// ��� ����
int Remove(BinNode **root, const Member *x){
    BinNode *next , *temp;
    BinNode **left;
    BinNode **p = root;

    while(1){
        int cond;
        if(*p == NULL){
            printf("���� : %d�� ��ϵǾ� ���� �ʽ��ϴ�.\n", x->no);
            return -1;
        }
        else if((cond = MemberNoCmp(x, &(*p)->data)) == 0){
            break; // �˻� ���� 
        }
        else if(cond < 0){
            p = &((*p)->left); // ���� ���� Ʈ������ �˻� 
        }
        else{
            p = &((*p)->right); // ������ ���� Ʈ������ �˻�
        }
    }

    if((*p)->left == NULL){
        next = (*p)->right;
    }
    else{
        left = &((*p)->left);
        while((*left)->right != NULL){
            left = &(*left)->right;
        }
        next = *left;
        *left = (*left)->right;
        next->left = (*p)->left;
        next->right = (*p)->right;
    }
    temp = *p;
    *p = next;
    free(temp);

    return 0;
}

// ��� ����� �����͸� ���
void PrintTree(const BinNode *p){
    if(p != NULL){
        PrintTree(p->left);
        PrintLnMember(&p->data);
        PrintTree(p->right);
    }
}

// ��� ��带 ����
void FreeTree(BinNode *p){
    if(p != NULL){
        FreeTree(p->left);
        FreeTree(p->right);
        free(p);
    }
}