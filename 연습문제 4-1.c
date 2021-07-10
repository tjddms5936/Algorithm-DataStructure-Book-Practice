#include <stdio.h>
#include "IntStack.h"

int main(void){
    IntStack s;
    if(Initialize(&s, 64) == -1){
        puts("스택 생성에 실패하였습니다.");
        return 1;
    }    
    while(1){
        int menu, x;
        printf("현재 데이터 수: %d / %d\n", Size(&s), Capacity(&s)); 
        printf("(1)PUSH (2)POP (3)PEEK (4)PRINT (0)TERMINATE :"); scanf("%d", &menu);
    	if(menu == 0){
        	break;
    	}
    	switch (menu){
    	case 1 : // push
        	printf("데이터:"); scanf("%d", &x);
        	if(Push(&s, x) == -1){
            	printf("PUSH에 실패하였습니다..");
        	}
        	break;
    	case 2 : // pop
        	if(Pop(&s, &x) == -1){
            	printf("POP에 실패하였습니다..");
        	}
        	else{
            	printf("POP 데이터는 %d 입니다.", x);
        	}
        	break;
    	case 3 : // peek
        	if(Peek(&s, &x) == -1){
            	printf("PEEK에 실패하였습니다.");
        	}
        	else{
            	printf("PEEK 데이터는 %d 입니다.", x);
        	}
        	break;
    	case 4 : // print
        	Print(&s);
        	break;
    	}
    	case 5 : // search함수 사용
    		printf("검색 값 : "); scanf("%d", &x)
    		int idx;
    		if((itx = Search(&s, x)) == -1){
    			printf("검색에 실패했습니다.");
			}
			else{
				printf("검색에 성공했습니다. \n");
				printf("%d는 스택 중 %d번째에 있습니다.", x, idx);
			}
			break;
		case 6 : // clear함수 사용
			Clear(&s);
			break;
		case 7 : // isempty, isfull 함수 사용
			printf("%s.\n", IsEmpty(&s) ? "비어있습니다." : "비어있지 않습니다.");
			printf("%s.\n", IsFull(&s) ? "꽉 차 있습니다." : "꽉 차 있지 않습니다.");
			break; 
	}
    	Terminate(&s);
    return 0;
}
