#include<stdio.h>
#include<windows.h>
#include<conio.h> 
#define LEFT 75
#define RIGHT 77
#define UP 72



int main(){
	
	
	int i=0;
	int key;
	
	
	
//	puts("Ű�� �Է��ϼ���!!");
//	key=_getch();
//	printf("�Էµ� Ű�� ascii�ڵ�=%d",key);
	 
	while(1){
	
		while(!_kbhit())
		{
	
			puts("Ű�� �Է��ϼ���!!");
			Sleep(1000);
			i++;
		}
		key=_getch();
		
		printf("�Էµ� Ű�� ascii�ڵ�=%d\n",key);
	
	}
		

	
	
	
}


