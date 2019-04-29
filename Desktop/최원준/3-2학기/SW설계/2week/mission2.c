#include<stdio.h>
#include<Windows.h>
void SetCurrentCursorPos(int x, int y)

{

    COORD pos={x, y};

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

COORD GetCurrentCursorPos(void)

{

    COORD curPoint;

    CONSOLE_SCREEN_BUFFER_INFO curInfo;

   

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

    curPoint.X=curInfo.dwCursorPosition.X;

    curPoint.Y=curInfo.dwCursorPosition.Y;

   

    return curPoint;

}
void ShowBlock(char blockInfo[4][4])

{

    int x,y;

    COORD curPos=GetCurrentCursorPos();

    for(y=0; y<4; y++)

    {

        for(x=0; x<4; x++)

        {

            SetCurrentCursorPos(curPos.X + (x*2), curPos.Y + y);

           

            if(blockInfo[y][x] == 1)

                printf("■");

        }

    }

    SetCurrentCursorPos(curPos.X, curPos.Y);

}



char blockModel[][4][4]=
{
	{
		{0,0,0,0},
		{1,0,0,0},
		{1,1,1,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,0,1,0},
		{1,1,1,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,1,0,0},
		{1,1,1,0},
		{0,0,0,0}
	},
			
	{
		{0,1,0,0},
		{0,1,0,0},
		{0,1,0,0},
		{0,1,0,0}
	},
	{
		{0,0,0,0},
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{1,1,0,0},
		{1,1,0,0},
		{0,0,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0}
	}
	

};
	
int main (void)
{
	SetCurrentCursorPos(0,0);
	ShowBlock(blockModel[0]);

	SetCurrentCursorPos(10,0);
	ShowBlock(blockModel[1]);

	SetCurrentCursorPos(20,0);
	ShowBlock(blockModel[2]);

	SetCurrentCursorPos(0,10);
	ShowBlock(blockModel[3]);

	SetCurrentCursorPos(10,10);
	ShowBlock(blockModel[4]);

	SetCurrentCursorPos(20,10);
	ShowBlock(blockModel[5]);

	SetCurrentCursorPos(0,20);
	ShowBlock(blockModel[6]);
	getchar();
	return 0;
}
	
	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//CONSOLE_SCREEN_BUFFER_INFO curlnfo;
	//HANDLE console;
	//console=GetStdHandle(STD_OUTPUT_HANDLE);

	//GetConsoleScreenBufferInfo(console, &curlnfo);
	//printf("[%d,%d]\n",curlnfo.dwCursorPosition.X,curlnfo.dwCursorPosition.Y);
	//puts("첫번째 안녕하세요");

		//GetConsoleScreenBufferInfo(console,&curlnfo);
//	printf("[%d,%d]\n",curlnfo.dwCursorPosition.X,curlnfo.dwCursorPosition.Y);
	//puts("두번째 안녕하세요");

