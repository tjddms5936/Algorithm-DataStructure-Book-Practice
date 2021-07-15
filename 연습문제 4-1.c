#include <stdio.h>
#include "IntStack.h"

int main(void){
    IntStack s;
    if(Initialize(&s, 64) == -1){
        puts("���� ������ �����Ͽ����ϴ�.");
        return 1;
    }    
    while(1){
        int menu, x;
        printf("���� ������ ��: %d / %d\n", Size(&s), Capacity(&s)); 
        printf("(1)PUSH (2)POP (3)PEEK (4)PRINT (0)TERMINATE :"); scanf("%d", &menu);
    	if(menu == 0){
        	break;
    	}
    	switch (menu){
    	case 1 : // push
        	printf("������:"); scanf("%d", &x);
        	if(Push(&s, x) == -1){
            	printf("PUSH�� �����Ͽ����ϴ�..");
        	}
        	break;
    	case 2 : // pop
        	if(Pop(&s, &x) == -1){
            	printf("POP�� �����Ͽ����ϴ�..");
        	}
        	else{
            	printf("POP �����ʹ� %d �Դϴ�.", x);
        	}
        	break;
    	case 3 : // peek
        	if(Peek(&s, &x) == -1){
            	printf("PEEK�� �����Ͽ����ϴ�.");
        	}
        	else{
            	printf("PEEK �����ʹ� %d �Դϴ�.", x);
        	}
        	break;
    	case 4 : // print
        	Print(&s);
        	break;
    	}
    	case 5 : // search�Լ� ���
    		printf("�˻� �� : "); scanf("%d", &x)
    		int idx;
    		if((itx = Search(&s, x)) == -1){
    			printf("�˻��� �����߽��ϴ�.");
			}
			else{
				printf("�˻��� �����߽��ϴ�. \n");
				printf("%d�� ���� �� %d��°�� �ֽ��ϴ�.", x, idx);
			}
			break;
		case 6 : // clear�Լ� ���
			Clear(&s);
			break;
		case 7 : // isempty, isfull �Լ� ���
			printf("%s.\n", IsEmpty(&s) ? "����ֽ��ϴ�." : "������� �ʽ��ϴ�.");
			printf("%s.\n", IsFull(&s) ? "�� �� �ֽ��ϴ�." : "�� �� ���� �ʽ��ϴ�.");
			break; 
	}
    	Terminate(&s);
    return 0;
}
