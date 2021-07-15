// 하노이의 탑
#include <stdio.h>

// 원반[1] ~ 원반[no]를 X기둥에서 Y기둥으로 옮김
void move(int no, int x, int y){ // no : 옮겨야 할 원반의 개수, x : 시작 기둥의 번호, y : 목표 기둥의 번호
	if(no>1){
		move(no-1, x, 6-x-y); // 이 프로그램은 기둥 번호를 정수 1, 2, 3으로 나타냄. 기둥 번호의 합이 6이므로 중간기둥은 6-x-y임. 
		// 그룹을 시작 기둥에서 중간 기둥으로!  
	} 
	printf("원반[%d]를 %d 기둥에서 %d 기둥으로 옮김\n", no, x, y);
	if(no>1){
		move(no-1, 6-x-y, y); // 그룹을 중간 기둥에서 목표 기둥으로!  
	}
}

int main(void){
	int n; // 원반의 개수
	printf("하노이의 탑\n원반 개수 :"); scanf("%d", &n);
	move(n, 1, 3); 
	return 0;
}
