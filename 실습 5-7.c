// �� ���� 1���� ���� ��ġ�ϴ� ������ ��������� �����մϴ�. 
#include <stdio.h>

int pos[8]; // �� �������� ���� ��ġ. pos[1] = 4 --> 1�������� ���� ��ġ�� 4��. 

// �� �������� ���� ��ġ�� ���
void print(void){
	int i;
	for(i=0; i<8; i++){
		printf("%2d", pos[i]);
	}
	printf("\n"); 
}

// i���� ���� ��ġ 
void set(int i){
	int j;
	for(j=0; j<8; j++){
		pos[i] = j;
		if(i==7){ // ��� ���� ��ġ�� ��ħ
			print(); 
		}
		else{
			set(i+1);
		}
	}
}
\
int main(void){
	set(0);
	return 0;
}
