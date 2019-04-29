#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "block.h"
#include <conio.h> 
#define LEFT 75
#define RIGHT 77
#define UP 72
#define space 32
/* Size of gameboard */
#define  GBOARD_WIDTH    10
#define  GBOARD_HEIGHT   20
/* Starting point of gameboard */
#define  GBOARD_ORIGIN_X  4
#define  GBOARD_ORIGIN_Y  2
int speed; 
int block_id;
int gameBoardInfo[GBOARD_HEIGHT+1][GBOARD_WIDTH+2];






void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
    curInfo.bVisible=0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
}

void SetCurrentCursorPos(int x, int y)
{
    COORD pos={x,y};
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
    RemoveCursor();
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

void ShiftLeft()
{
	DeleteBlock(blockModel[block_id]);
	SetCurrentCursorPos(GetCurrentCursorPos().X-2,GetCurrentCursorPos().Y);
	ShowBlock(blockModel[block_id]);
	 
}

void ShiftRight()
{
	DeleteBlock(blockModel[block_id]);
	SetCurrentCursorPos(GetCurrentCursorPos().X+2,GetCurrentCursorPos().Y);
	ShowBlock(blockModel[block_id]);
	 
}

int BlockDown()
{
	COORD curPos;
	if(!DetectCollision(curPos.X, curPos.Y+1, blockModel[block_id]))
	{
		return 0;
		}
			
DeleteBlock(blockModel[block_id]);
curPos.Y+=1;
SetCurrentCursorPos(curPos.X, curPos.Y);
ShowBlock(blockModel[block_id]);
return 1;
}


void RotateBlock()

{
	COORD curPos;
    int block_base;

    DeleteBlock(blockModel[block_id]);

    block_base=block_id-block_id%4;

    block_id=block_base+(block_id+1)%4;

    SetCurrentCursorPos(curPos.X, curPos.Y);

    ShowBlock(blockModel[block_id]);


}



void ReverseRotateBlock()
{
	int block_base;
	DeleteBlock(blockModel[block_id]);
	block_base = block_id - block_id%4;
	block_id = block_base + (4+block_id-1)%4;
	ShowBlock(blockModel[block_id]);
	 
}
void BlockUP()
{
	DeleteBlock(blockModel[block_id]);
	SetCurrentCursorPos(GetCurrentCursorPos().X, GetCurrentCursorPos().Y-1);
	ShowBlock(blockModel[block_id]);
	 
}
void BlockLU()
{
	DeleteBlock(blockModel[block_id]);
	SetCurrentCursorPos(GetCurrentCursorPos().X-2, GetCurrentCursorPos().Y-1);
	ShowBlock(blockModel[block_id]);
	 

}
void BlockRU()
{
	DeleteBlock(blockModel[block_id]);
	SetCurrentCursorPos(GetCurrentCursorPos().X+2, GetCurrentCursorPos().Y-1);
	ShowBlock(blockModel[block_id]);
	 
}
void BlockLD()
{
	DeleteBlock(blockModel[block_id]);
	SetCurrentCursorPos(GetCurrentCursorPos().X-2, GetCurrentCursorPos().Y+1);
	ShowBlock(blockModel[block_id]);
	 
}
void BlockRD()
{
	DeleteBlock(blockModel[block_id]);
	SetCurrentCursorPos(GetCurrentCursorPos().X+2, GetCurrentCursorPos().Y+1);
	ShowBlock(blockModel[block_id]);
	 
}
void spaceDown(){
		
			

	while(BlockDown());
	

			}
			
void ProcessKeyInput(){
	int key,i;
	
	for(i=0;i<20;i++){
		
			if(_kbhit()!=0){	 
				key=_getch();
				switch(key){
			
				case LEFT:
					ShiftLeft();
					break;
				case RIGHT:
					ShiftRight();
					break;
				case UP:
					RotateBlock();
					break;
				case space:
					spaceDown();
					break;
				}
				

			}
		
   		Sleep(speed);//block 의 속도를 제어할 수 있다  
   		}
	
	
	}


int DetectCollision(int posX, int posY, char blockModel[4][4])
{
	int x, y;
	int arrX= posX/2;
	int arrY= posY;
	for(x=0; x<4; x++)
		{ for(y=0; y<4; y++)
		{
			if(blockModel[y][x]==1 && gameBoardInfo[arrY+y][arrX+x]==1)
					return 0;
		}
	}
		return 1;
}

void DrawGameBoard()
{
	int x,y;
	for(y=0;y<=GBOARD_HEIGHT ;y++){
		
		SetCurrentCursorPos(GBOARD_ORIGIN_X,GBOARD_ORIGIN_Y+y);
		if(y==GBOARD_HEIGHT)
			printf("└") ;
		else
			printf("│");
			
	}
		 
	for(x=0;x<2*(GBOARD_WIDTH-1);x++){
	 	
		printf("─");
	}	
	for(y=0;y<=GBOARD_HEIGHT;y++){
		SetCurrentCursorPos(2*GBOARD_WIDTH+GBOARD_ORIGIN_X,GBOARD_ORIGIN_Y+y);
			if(y==GBOARD_HEIGHT)
			printf("┘") ;
		else
			printf("│");
		
	} 
	
}
void RedrawBlocks(void)

{   int x, y;

    int cursX, cursY;

    for(y=0; y<=GBOARD_HEIGHT; y++)

    {   for(x=0; x<=GBOARD_WIDTH+1; x++)

        {   cursX= x*2 + GBOARD_ORIGIN_X;

            cursY= y + GBOARD_ORIGIN_Y;

            SetCurrentCursorPos(cursX, cursY);

            if(gameBoardInfo[y][x]==1)

            {  printf("■");

            }

            else {  printf("  ");    }

        }

    }

}
void ADDBlockToBoard(void){
	 COORD curPos=GetCurrentCursorPos();
	int x,y,arrCurX,arrCurY;
	for(y=0;y<4;y++){
		
		for(x=0;x<4;x++){
			
			arrCurX=(curPos.X-GBOARD_ORIGIN_X)/2;
			arrCurY=(curPos.Y-GBOARD_ORIGIN_Y);
			
			
			if(blockModel[block_id][y][x]==1)
					
			gameBoardInfo[arrCurY+y][arrCurX+x]==1;
			
		}
		
	}
	
}
int IsGameOver(){
	COORD curPos;
	if(!DetectCollision(curPos.X, curPos.Y+1, blockModel[block_id])){
		return 0;
			}
	 return 1;
	
}


int main()
{	int key;
	int x,y;
	int i;


 for(y=0; y<GBOARD_HEIGHT; y++){

        gameBoardInfo[y][0]=1;

        gameBoardInfo[y][GBOARD_WIDTH+1]=1;

 }

   

 for(x=0; x<GBOARD_WIDTH+2; x++){

        gameBoardInfo[GBOARD_HEIGHT][x]=1;

 }	
 
 	
	RemoveCursor();
	RedrawBlocks();
	
	//DrawGameBoard();
	while(1){
		srand((unsigned int)time(NULL));
		SetCurrentCursorPos(8,0);
		speed=90;
		block_id = (rand()%7)*4;
    	RemoveCursor();
		ShowBlock(blockModel[block_id]);
	
	if(IsGameOver()){
	
			break;	}
			
		while(1){
			if(BlockDown()==0){
 		
		 		ADDBlockToBoard();
		 		break;
				}
			
			ProcessKeyInput();
			
		
		}
		SetCurrentCursorPos(8,2);
		puts("Game Over!!!");
	}
	
		getchar();
		return 0;
}

