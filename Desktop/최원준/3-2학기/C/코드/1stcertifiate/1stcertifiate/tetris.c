
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h> 
#define COL GetStdHandle(STD_OUTPUT_HANDLE)

void gotoxy(int x, int y)
{
    COORD Pos = { x-1, y-1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void CursorUtil_Hide(){
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
int block[7][4][4] = {
	{
		{0,0,0,0},
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,0,0,1},
		{0,1,1,1},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,0,1,1},
		{0,1,1,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,1,1,0},
		{0,0,1,1},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,0,1,0},
		{0,1,1,1},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,1,0,0},
		{0,1,1,1},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	}
};
int originalBlock[7][4][4] = {0};
int map[22][14] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
int collisionMap[22][14] = {0};
int immutabilityMap[22][14] = {0};
int randBlock = 0; 
int nowHeight = 0;
int score = 0;
int x, y, px, py, Move, Move2, NewBlock = 0;
int CollisionCheck();
int setColor(int a);
void MoveSwitch(int a);
void drawBlocks(int move);
void drawBoard();
void deleteBlocks();
void InputKeyboard();
void bringNewBlocks();
void deleteLine();
void turnBlocks(); 
int main()
{
	int i,j,e;
	int startTickCount;
	drawBoard();
	CursorUtil_Hide();
	srand(time(NULL));
	for(i=0;i<22;i++)
	{
		for(j=0;j<14;j++)
		{
			collisionMap[i][j]=map[i][j];
			immutabilityMap[i][j]=map[i][j];	
		}
	}
	for(i=0;i<7;i++)
	{
		for(j=0;j<4;j++)
		{
			for(e=0;e<4;e++)
				originalBlock[i][j][e]=block[i][j][e];
		}
	}
	gotoxy(15,4);
	randBlock = rand()%7;
	x=6;
	y=1;
	px=17;
	py=4;
	drawBlocks(1); 
	startTickCount=GetTickCount();
	while(1)
	{
		if (GetTickCount() - startTickCount >= 1000){ //1초가 지났을때 
            drawBlocks(1);
            if(CollisionCheck()==1)
                bringNewBlocks();		
            deleteBlocks();
            y++;
			py++;
			drawBlocks(1);
			startTickCount=GetTickCount();
    	} else { //1초가 아직 안지났을때 
    		InputKeyboard();
		}
	}
}
void drawBoard()
{
	int i,j;
	gotoxy(5,3);
	for(i=0;i<14;i++)
		printf("■");
	for(i=0;i<21;i++)
		printf("\n    ■");
	gotoxy(5, 24);
	for(i=0;i<14;i++)
		printf("■");
	for(i=0;i<21;i++)
	{
		gotoxy(31,4+i);
		printf("■");
	}
	gotoxy(40,5);
	printf("-TETRIS-");
	gotoxy(40,6);
	printf("  By hosung337(Snow Man)");
	gotoxy(40,10);
	printf("SCORE : 0");
}
void drawBlocks(int move)
{
	int i,j;
	int color=12;
	static int num=1;
	
	for(i=0;i<22;i++)
	{
		for(j=0;j<14;j++)
			collisionMap[i][j]=immutabilityMap[i][j];
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if (block[randBlock][i][j]==1)
			{
				color=setColor(num);
				SetConsoleTextAttribute(COL, color);
				map[y+i][x+j]=num;
				gotoxy(px+j*2, py+i);
				printf("■");
				if(num==7)
					num=1;
				else if(NewBlock==1)
					num++, NewBlock=0;
				if (move==1)
					collisionMap[y+i+1][x+j]=0;
				else if (move==2)
					collisionMap[y+i][x+j-1]=0;
				else if (move==3)
					collisionMap[y+i][x+j+1]=0;
			}
		}
	}
}
void deleteBlocks()
{
	int i,j;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if (block[randBlock][i][j]==1)
			{
				map[y+i][x+j]=0;
				gotoxy(px+j*2, py+i);
				printf("  ");
			}
		}
	}	
}
int CollisionCheck()
{
	int i,j;
	for(i=0;i<22;i++)
	{
		for(j=0;j<14;j++)
		{
			if(collisionMap[i][j]!=immutabilityMap[i][j])
				return 1;
		}
	}
	return 0;
}
void InputKeyboard()
{
	int i,j; 
	char temp = 0;
	drawBlocks(2);
	if(CollisionCheck()==1)
	{
		Move=1;
		for(i=0;i<22;i++)
		{
			for(j=0;j<14;j++)
				collisionMap[i][j]=immutabilityMap[i][j];
		}
	} else {
		MoveSwitch(0);
	}	
	drawBlocks(3);
	if(CollisionCheck()==1)
	{
		Move2=1;
		for(i=0;i<22;i++)
		{
			for(j=0;j<14;j++)
				collisionMap[i][j]=immutabilityMap[i][j];
		}
	} else {
		MoveSwitch(1);
	}	
	if(kbhit())
	{
		temp = getch();
		if(temp<0) 
			temp = getch();
		if(temp==75)
		{
			deleteBlocks(); 
			if (Move!=1)
			{
				x-=1;
				px-=2;	
			}
			drawBlocks(2);	
			if(CollisionCheck()!=1)
				Move=0;	
		} else if(temp==77) {
			deleteBlocks(); 
			if (Move2!=1)
			{
				x+=1;
				px+=2;	
			}
			drawBlocks(3);	
			if(CollisionCheck()!=1)
				Move2=0;				
		} else if(temp==80) {
            drawBlocks(1);
            if(CollisionCheck()==1)
            	bringNewBlocks();
            deleteBlocks();
            y++;
			py++;
			drawBlocks(1);			
		} else if(temp==72) {
			deleteBlocks();
			turnBlocks();
		} else if(temp==32) { 
			while(1)
			{
				drawBlocks(1);
		        if(CollisionCheck()==1)
		            break;
		        deleteBlocks();
		        y++;
				py++;
				drawBlocks(1);				
			}
			bringNewBlocks();	
		}
	} 
} 
void bringNewBlocks()
{
	int i,j;
	int exitOuterLoop=0;
	for(i=1;i<=20;i++)
	{
		for(j=1;j<=12;j++)
		{
			if(map[i][j]>=1)
			{
				nowHeight=i;
				exitOuterLoop=1;
				break;
			}
		}
		if(exitOuterLoop==1)
			break;
	}
	deleteLine();
	for(i=0;i<22;i++)
	{
		for(j=0;j<14;j++)
		{
			collisionMap[i][j]=map[i][j];
			immutabilityMap[i][j]=map[i][j];	
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			block[randBlock][i][j]=originalBlock[randBlock][i][j];
	}
	gotoxy(15,4);
	randBlock = rand()%7;
	x=6;
	y=1;
	px=17;
	py=4;	
	Move=0;
	Move2=0;
	NewBlock=1;
	for(j=0;j<4;j++) //게임 오버 조건 
	{
		if(map[4][6+j]>=1)
		{
			gotoxy(40,10);
			SetConsoleTextAttribute(COL, 0x000c);
			printf("                                    ");
			gotoxy(40,10);
			printf("GAME OVER!");
			gotoxy(5,25);
			system("pause>nul");
			SetConsoleTextAttribute(COL, 0x0007);
			exit(0);
		}
	}	
	drawBlocks(1); 		
}
void MoveSwitch(int a)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(map[y+1][x+i]>=1)
		{
			if(a==0)
				Move=0;
			else if(a==1)
				Move2=0;
			break;
		}
	}		
}
void turnBlocks()
{
	int i,j;
	int tempArr[4][4];
	int e=0;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			tempArr[i][j]=block[randBlock][i][j];
	}
	for(i=0;i<4;i++)
	{
		for(j=3;j>=0;j--)
		{
			block[randBlock][i][e]=tempArr[j][i];
			e++;	
		}
		e=0;
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(block[randBlock][i][j]==1)
				collisionMap[y+i][x+j]=0;
		}
	}
	if(CollisionCheck()==1)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				block[randBlock][i][j]=tempArr[i][j];
		}
	}
}
void deleteLine()
{
	int i,j,e,r;
	int num=0;
	for(r=1;r<=20;r++)
	{
		for(i=20;i>=1;i--)
		{
			for(j=12;j>=1;j--)
			{
				if(map[i][j]>=1)
					num++;	
			}
			if(num==12)
			{
				for(j=1;j<=12;j++)
					map[i][j]=0;
				for(j=i-1;j>=nowHeight;j--)
				{
					for(e=1;e<=12;e++)
					{
						map[j+1][e]=map[j][e];
						map[j][e]=0;	
					}
				}
				score+=100;
				gotoxy(40,10);
				SetConsoleTextAttribute(COL, 0x0007);	
				printf("SCORE : %d", score);
			}
			num=0;
		}		
	}

	gotoxy(7,4);
	for(j=1;j<=20;j++)
	{
		for(e=1;e<=12;e++)
		{
			if(map[j][e]>=1)
			{
				SetConsoleTextAttribute(COL, setColor(map[j][e]));
				printf("■");	
			}	
			else
				printf("  ");
		}
		gotoxy(7,4+j);
	}
}
int setColor(int a)
{
	switch(a)
	{
		case 1: return 12;
		case 2: return 14;
		case 3: return 3;
		case 4: return 9;
		case 5: return 1;
		case 6: return 5;
		case 7: return 15;
	}
}
