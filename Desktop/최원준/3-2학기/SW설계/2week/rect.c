#include<stdio.h>
#include<Windows.h>
int main(void)
{
	CONSOLE_SCREEN_BUFFER_INFO curlnfo;
	HANDLE console;
	console=GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferinfo(console,&curlnfo(커서값));
	printf("[%d,%d]\n"curlnfo.dwCursorPosition.X,curlnfo.dwCursorPosition.Y);
	puts("첫번째 안녕하세요");

		GetConsoleScreenBufferinfo(console,&curlnfo);
	printf("[%d,%d]\n"curlnfo.dwCursorPosition.X,curlnfo.dwCursorPosition.Y);
	puts("두번째 안녕하세요");

	getchar();

return 0;}
