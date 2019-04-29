#include<stdio.h>
#include<windows.h>
#include<time.h>
char blockModel[][4][4] =	
{

    {
        {0, 0, 0, 0}, 
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0} },   
    {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0} },    
    {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0} },    
    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0} },


    {
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0} },   
    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0} },    
    {
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {0, 1, 0, 0},
        {0, 0, 0, 0} },    
    {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0} },


    {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0} },   
    {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0} },    
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0} },    
    {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0} },


    {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0} },   
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0} },    
    {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0} },    
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0} },
 

    {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0} },   
    {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0} },    
    {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0} },    
    {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0} },



    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0} },   
    {
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0} },    
    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0} },   
    {
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0} },  
 

    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0} },   
    {
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0} }, 
    {   
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0} },   
    {
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0} }
};


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

                printf("бс");

        }

    }

    SetCurrentCursorPos(curPos.X, curPos.Y);

}
void DeleteBlock(char blockInfo[4][4])

{

    int x,y;

    COORD curPos=GetCurrentCursorPos();

    for(y=0; y<4; y++)

    {

        for(x=0; x<4; x++)

        {

            SetCurrentCursorPos(curPos.X + (x*2), curPos.Y + y);

           

            if(blockInfo[y][x] == 1)

                printf(" ");

        }

    }

    SetCurrentCursorPos(curPos.X, curPos.Y);

}

void direction(int d){
	
	
	COORD CPOS=	GetCurrentCursorPos();
	switch(d){
		
		case 0: SetCurrentCursorPos(CPOS.X,CPOS.Y-1); break;
		case 1: SetCurrentCursorPos(CPOS.X+2,CPOS.Y-1); break;
		case 2: SetCurrentCursorPos(CPOS.X+2,CPOS.Y); break;
		case 3: SetCurrentCursorPos(CPOS.X+2,CPOS.Y+1); break;
		case 4: SetCurrentCursorPos(CPOS.X,CPOS.Y+1); break;
		case 5: SetCurrentCursorPos(CPOS.X-2,CPOS.Y+1); break;
		case 6: SetCurrentCursorPos(CPOS.X-2,CPOS.Y); break;
		case 7: SetCurrentCursorPos(CPOS.X-2,CPOS.Y-1); break;
		
		
	
	}
	
	
	
}


int main(){
	
	
	int i;
	
	srand((unsigned int )time(NULL));
	
	
	while(1){
		
		srand((unsigned int )time(NULL));
		int block_id=4*rand()%7;
		
		int direct=rand()%8;
		int PosX=rand()%50;
		int PosY=rand()%50;
		SetCurrentCursorPos(PosX,PosY);
		
		
		for(i=0;i<25;i++){
			ShowBlock(blockModel[block_id+i%4]);
			Sleep(300);
			DeleteBlock(blockModel[block_id+i%4]);
			direction(direct);
				
			
		}	
		
		
		
	}
	
	
	
	
		
	
	getchar();
	
		
	
	
	
	
	
	
}


