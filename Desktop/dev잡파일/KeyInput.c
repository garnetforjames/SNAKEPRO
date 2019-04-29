#include<stdio.h>
#include<windows.h>
#include<conio.h> 
#define LEFT 75
#define RIGHT 77
#define UP 72



int main(){
	
	
	int i=0;
	int key;
	
	
	
//	puts("키를 입력하세요!!");
//	key=_getch();
//	printf("입력된 키의 ascii코드=%d",key);
	 
	while(1){
	
		while(!_kbhit())
		{
	
			puts("키를 입력하세요!!");
			Sleep(1000);
			i++;
		}
		key=_getch();
		
		printf("입력된 키의 ascii코드=%d\n",key);
	
	}
		

	
	
	
}


