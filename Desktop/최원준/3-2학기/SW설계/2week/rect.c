#include<stdio.h>
#include<Windows.h>
int main(void)
{
	CONSOLE_SCREEN_BUFFER_INFO curlnfo;
	HANDLE console;
	console=GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferinfo(console,&curlnfo(Ŀ����));
	printf("[%d,%d]\n"curlnfo.dwCursorPosition.X,curlnfo.dwCursorPosition.Y);
	puts("ù��° �ȳ��ϼ���");

		GetConsoleScreenBufferinfo(console,&curlnfo);
	printf("[%d,%d]\n"curlnfo.dwCursorPosition.X,curlnfo.dwCursorPosition.Y);
	puts("�ι�° �ȳ��ϼ���");

	getchar();

return 0;}
