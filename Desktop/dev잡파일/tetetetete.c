#include <stdio.h>
#include <windows.h>
#include <conio.h>


int main(void){
	COORD p1={0,0};
	COORD p2={6,6};
	
	HANDLE console;
	console=GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleCursorPosition(console,p1);
	printf("бс");
	
	SetConsoleCursorPosition(console,p2);
	printf("бс");
	
	getchar();
	return 0; 
	
}
