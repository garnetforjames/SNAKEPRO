#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
/* Size of gameboard */
#define  GBOARD_WIDTH    70
#define  GBOARD_HEIGHT   40

void setcolor(int color, int bgcolor)//컬러  
{
	//  0 cl black
	// 12 cl red  
	// 10 cl green
	// 15 cl white  

	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
    curInfo.bVisible=0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
}

typedef struct _SNAKE //몸통 배열  
{
   int x;
   int y;
   int endisable;
}SNAKE;

typedef struct _EWORD
{
	char letter;
	int endisable;
}EWORD;

typedef struct _WORDL
{
	struct _EWORD A[10];
	int length;
	int progress;
}WORDL;

typedef struct _WPOS
{
	int x;
	int y;
} WPOS;

int numofitem;
int super = 0;
int revealt = 0;
int reveal = 0;
WORDL round[5];
char word[5][20] = {{'M','A','R','V','E','L'}, {'I','R','O','N','M','A','N'}, {'S','P','I','D','E','R','M','A','N'},{'B','L','A','C','K','P','A','N','T','H','E','R'},{'C','A','P','T','A','I','N','A','M','E','R','I','C','A'}};
WPOS wpos[10];
int stage = 1;
int life;
int SnakeLength = 0;
int wallcollision = 0;
int head_pos_x;
int head_pos_y;
int speed = 200;
SNAKE snake[2600];
int gameBoardInfo[5][GBOARD_HEIGHT][GBOARD_WIDTH];
int key_save, key_check;
int Gameover = 0;
int reverse = 0;

void gotoxy(int x, int y)
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void wposinit()
{
	int r = rand()%5;
	
	switch(r)
	{
		case 0:
			wpos[0].x=10;
			wpos[0].y=6;
			
			wpos[1].x=GBOARD_WIDTH-8;
			wpos[1].y=GBOARD_HEIGHT-6;
   
			wpos[2].x=GBOARD_WIDTH-3;
			wpos[2].y=6;

			wpos[3].x=GBOARD_WIDTH/2-10;
			wpos[3].y= GBOARD_HEIGHT/2+6;

			wpos[4].x= 14;
			wpos[4].y= GBOARD_HEIGHT -6;

			wpos[5].x=GBOARD_WIDTH/2;
			wpos[5].y= GBOARD_HEIGHT/2+9;

			wpos[6].x=GBOARD_WIDTH/2+32;
			wpos[6].y= GBOARD_HEIGHT/2+6;

			wpos[7].x=GBOARD_WIDTH/2-14;
			wpos[7].y= GBOARD_HEIGHT/2;
			
			wpos[8].x=GBOARD_WIDTH/2;
			wpos[8].y= GBOARD_HEIGHT-9;
			
			break;	
		case 1:
			wpos[0].x=6;
			wpos[0].y=6;
			
			wpos[1].x=GBOARD_WIDTH/2-14;
			wpos[1].y= GBOARD_HEIGHT/2;
   
			wpos[2].x=GBOARD_WIDTH/2+32;
			wpos[2].y= GBOARD_HEIGHT/2+6;
   
			wpos[3].x=GBOARD_WIDTH/2-8;
			wpos[3].y= GBOARD_HEIGHT/2+4;
   
			wpos[4].x= 14;
			wpos[4].y= GBOARD_HEIGHT -6;

			wpos[5].x=GBOARD_WIDTH/2;
			wpos[5].y= GBOARD_HEIGHT/2+9;

			wpos[6].x=GBOARD_WIDTH/2;
			wpos[6].y= GBOARD_HEIGHT/2+4;

			wpos[7].x=4;
			wpos[7].y= GBOARD_HEIGHT/2-1;
			
			wpos[8].x=GBOARD_WIDTH/2+16;
			wpos[8].y= GBOARD_HEIGHT/2-2;

			break;
		case 2:
			wpos[0].x=6;
			wpos[0].y=6;
			
			wpos[1].x=GBOARD_WIDTH-10;
			wpos[1].y=GBOARD_HEIGHT-3;
   
			wpos[2].x=GBOARD_WIDTH-14;
			wpos[2].y=9;
   
			wpos[3].x=GBOARD_WIDTH/2-2;
			wpos[3].y= GBOARD_HEIGHT/2+6;
   
			wpos[4].x= 10;
			wpos[4].y= GBOARD_HEIGHT -6;

			wpos[5].x=GBOARD_WIDTH/2+4;
			wpos[5].y= GBOARD_HEIGHT/2+9;

			wpos[6].x=GBOARD_WIDTH/2+32;
			wpos[6].y= GBOARD_HEIGHT/2+1;

			wpos[7].x=GBOARD_WIDTH/2-14;
			wpos[7].y= GBOARD_HEIGHT/2;
			
			wpos[8].x=GBOARD_WIDTH/2-14;
			wpos[8].y= GBOARD_HEIGHT/2-4;

			break;	
			
		case 3:
			wpos[0].x=6;
			wpos[0].y=6;
			
			wpos[1].x=GBOARD_WIDTH-10;
			wpos[1].y=GBOARD_HEIGHT-3;
   
			wpos[2].x=GBOARD_WIDTH-14;
			wpos[2].y=9;
   
			wpos[3].x=GBOARD_WIDTH/2-2;
			wpos[3].y= GBOARD_HEIGHT/2+6;
   
			wpos[4].x= 10;
			wpos[4].y= GBOARD_HEIGHT -6;

			wpos[5].x=GBOARD_WIDTH/2+4;
			wpos[5].y= GBOARD_HEIGHT/2+9;

			wpos[6].x=GBOARD_WIDTH/2+32;
			wpos[6].y= GBOARD_HEIGHT/2+1;

			wpos[7].x=GBOARD_WIDTH/2-14;
			wpos[7].y= GBOARD_HEIGHT/2;
			
			wpos[8].x=GBOARD_WIDTH/2-14;
			wpos[8].y= GBOARD_HEIGHT/2-4;
	
			wpos[9].x=GBOARD_WIDTH-4;
			wpos[9].y=GBOARD_HEIGHT/3+12;
			
			
			wpos[10].x=GBOARD_WIDTH/3- 14;
			wpos[10].y=GBOARD_HEIGHT/4+12;
			
			wpos[11].x=GBOARD_WIDTH-22;
			wpos[11].y=GBOARD_HEIGHT-33;
		case 4:
				wpos[0].x=6;
			wpos[0].y=6;
			
			wpos[1].x=GBOARD_WIDTH-10;
			wpos[1].y=GBOARD_HEIGHT-3;
   
			wpos[2].x=GBOARD_WIDTH-14;
			wpos[2].y=9;
   
			wpos[3].x=GBOARD_WIDTH/2-2;
			wpos[3].y= GBOARD_HEIGHT/2+6;
   
			wpos[4].x= 10;
			wpos[4].y= GBOARD_HEIGHT -6;

			wpos[5].x=GBOARD_WIDTH/2+4;
			wpos[5].y= GBOARD_HEIGHT/2+9;

			wpos[6].x=GBOARD_WIDTH/2+32;
			wpos[6].y= GBOARD_HEIGHT/2+1;

			wpos[7].x=GBOARD_WIDTH/2-14;
			wpos[7].y= GBOARD_HEIGHT/2;
			
			wpos[8].x=GBOARD_WIDTH/2-14;
			wpos[8].y= GBOARD_HEIGHT/2-4;
	
			wpos[9].x=GBOARD_WIDTH-4;
			wpos[9].y=GBOARD_HEIGHT/3+12;
			
			
			wpos[10].x=GBOARD_WIDTH/3- 14;
			wpos[10].y=GBOARD_HEIGHT/4+12;
			
			wpos[11].x=GBOARD_WIDTH-22;
			wpos[11].y=GBOARD_HEIGHT-33;
			
			wpos[12].x=GBOARD_WIDTH/5+14;
			wpos[12].y=GBOARD_HEIGHT/5+22;
			
			wpos[13].x=GBOARD_WIDTH/4+11;
			wpos[13].y=GBOARD_HEIGHT-36;
			
	}
}

void initWordInfo()
{
	int i;
	round[stage-1].length = strlen(word[stage-1]);
	for(i=0; i<round[stage-1].length; i++)
	{
		round[stage-1].A[i].letter = word[stage-1][i];
		round[stage-1].A[i].endisable = 1;
		gameBoardInfo[stage-1][wpos[i].y][wpos[i].x] = 2;
	}
	round[stage-1].progress = 0;
	for(i=0; i<round[stage-1].length; i++)
	{
		if(gameBoardInfo[stage-1][wpos[i].y][wpos[i].x] == 2)
			gotoxy(2*wpos[i].x,wpos[i].y);
			printf("%c",round[stage-1].A[i].letter);
	}
}



COORD GCCP(void) //GetCurrentCursorPos
{
    COORD curPoint;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curPoint.X=curInfo.dwCursorPosition.X;
    curPoint.Y=curInfo.dwCursorPosition.Y;
    
    return curPoint;
}

int mainframe()
{
	int position=0;
	int check=0;
	system("mode con cols=100 lines=45");
	printf("\n\n\n\n\n\n");
	printf("      ┌───┐ ┌────┐┌────┐┌┐┌────┐\n");
	printf("      │┌─┐└┐│┌──┐││┌──┐│└┘└─┐┌─┘\n");
	printf("      ││ └┐│││  ││││  ││    ││\n");
	printf("      ││  ││││  ││││  ││    ││\n");
	printf("      ││  ││││  ││││  ││    ││\n");
	printf("      ││ ┌┘│││  ││││  ││    ││\n");
	printf("      │└─┘┌┘│└──┘│││  ││    ││\n");
	printf("      └───┘ └────┘└┘  └┘    └┘\n");
	printf("      ┌────┐┌────┐┌────┐┌────┐┌────┐\n");
	printf("      │┌───┘│┌──┐││┌──┐││┌───┘│┌───┘\n");
	printf("      ││    ││  ││││  ││││    ││\n");
	printf("      ││    │└──┘/││  │││└───┐│└───┐\n");
	printf("      ││    │┌──＼││  ││└───┐│└───┐│\n");
	printf("      ││    ││  ││││  ││    ││    ││\n");
	printf("      │└───┐││  │││└──┘│┌───┘│┌───┘│\n");
	printf("      └────┘└┘  └┘└────┘└────┘└────┘\n");
	printf("      ┌────┐┌┐  ┌┐┌────┐\n");
	printf("      └─┐┌─┘││  │││┌───┘\n");
	printf("        ││  ││  ││││\n");
	printf("        ││  │└──┘││└───┐\n");
	printf("        ││  │┌──┐││┌───┘\n");
	printf("        ││  ││  ││││\n");
	printf("        ││  ││  │││└───┐\n");
	printf("        └┘  └┘  └┘└────┘\n");
	printf("      ┌┐    ┌────┐┌────┐┌────┐\n");
	printf("      ││    └─┐┌─┘│┌──┐││┌───┘\n");
	printf("      ││      ││  ││  ││││\n");
	printf("      ││      ││  ││  │││└───┐\n");
	printf("      ││      ││  ││  │││┌───┘\n");
	printf("      ││      ││  ││  ││││\n");
	printf("      │└───┐┌─┘└─┐││  │││└───┐\n");
	printf("      └────┘└────┘└┘  └┘└────┘\n");

	gotoxy(70, 16);
	printf("Start Game");
	gotoxy(70, 28);
	printf("Exit");
	gotoxy(67, 16);
	printf("▶");

	while (1)
	{
		int key;

		if (_kbhit() != 0)
		{
			key = _getch();

			if (check == 1)
			{
				if (position == 0)
				{
					gotoxy(67, 16);
					printf(" ");
				}
				else
				{
					gotoxy(67, 28);
					printf(" ");
				}
				check--;
			}

			switch (key)
			{
			case UP:
				if (position > 0)
					position--;
				//gotoxy(67, 35);
				//	printf("%d", position);
				break;
			case DOWN:
				if (position < 1)
					position++;
				//gotoxy(67, 35);
				//	printf("%d", position);
				break;
			case ENTER:
				return position;					//Game start에서 엔터를 쳤을 경우 0을 반환, Exit에서 엔터를 쳤을 경우 1을 반환
			}

			if (check == 0)
			{
				if (position == 0)
				{
					gotoxy(67, 16);
					printf("▶");
				}
				else
				{
					gotoxy(67, 28);
					printf("▶");
				}
				check++;
			}
		}
	}
}

void InitGameBoardInfo()
{
	int x, y;
	for(x=0; x<GBOARD_WIDTH; x++)
		gameBoardInfo[stage-1][0][x] = 10;
	for(y=1; y<GBOARD_HEIGHT-1; y++)
	{
		gameBoardInfo[stage-1][y][0] = 10;
		for(x=1; x<GBOARD_WIDTH-1; x++);
			gameBoardInfo[stage-1][y][x] = 0;
		gameBoardInfo[stage-1][y][GBOARD_WIDTH-1] = 10;
	}
	for(x=0; x<GBOARD_WIDTH; x++)
		gameBoardInfo[stage-1][GBOARD_HEIGHT-1][x] = 10;		
}

void item_create()
{
	COORD save;
	char itemtem;
	int i,j,k,l,n;
	int item_case[3];
	int item;
	k=0;
	
	for(;numofitem<1;numofitem++)
	{		
		i=rand()%GBOARD_WIDTH;
    	j=rand()%GBOARD_HEIGHT;
    	//	printf("clear");
    	if(gameBoardInfo[stage-1][j][i]==0)
    	{   
		//	printf("clear");
			item=rand()%3+3;
		//	printf("%d",item);
		
			gameBoardInfo[stage-1][j][i]=item;
			
    		save = GCCP();
			gotoxy(2*i, j);
	
			switch(item)
			{
			case 3:
				printf("★");
				//printf("clear\n");
				break;
			case 4:
				printf("◎");
				//printf("clear\n");
				break;
			case 5:				
				printf("♥") ;
				//printf("clear\n");
				break;
			}
    		//printf("%c", object);
    		gotoxy(save.X, save.Y);
    		k++; 
    	}
    	else
    	{
    		numofitem--;
		}
    }	
}

void obs()
{
	COORD save;
    int i,j,k,l,n;
    char object;
    k=0;
    while(k<5)
    {
		i=rand()%GBOARD_WIDTH;
    	j=rand()%GBOARD_HEIGHT;
    	if(gameBoardInfo[stage-1][j][i]==0)
    	{   
    		gameBoardInfo[stage-1][j][i]=1;
    		save = GCCP();
			gotoxy(2*i, j);
			while(1)
			{
				n=0;
				object = rand()%26+65;
				for(l=0; l<round[stage-1].length; l++)
				{
					if(word[stage-1][l] == object)
					{
						n++;
					}
				}
				if(n==0)
					break;
			}
    		printf("%c", object);
    		gotoxy(save.X, save.Y);
    		k++; 
    	}
    }
}

void ADD_LIFE()
{
	COORD save;
	life++;
	
	save = GCCP();
	gotoxy(2*GBOARD_WIDTH+8, 10);
	setcolor(12, 0);
	printf("♥(Life) X %d", life);
	gotoxy(save.X, save.Y);
	setcolor(7, 0);
}

void SUPER_EFFECT();

void REVEAL(int n)
{
	int i;
	
		
	for(i=0; i<round[stage-1].length; i++)
	{
		if(gameBoardInfo[stage-1][wpos[i].y][wpos[i].x] == 2)
		{
			gotoxy(2*wpos[i].x,wpos[i].y);
			printf("%c",round[stage-1].A[i].letter);
		}
	}
	
	setcolor(7, 0);
}

int DetectCollision()
{
	int i;
	COORD save;
	if(gameBoardInfo[stage-1][head_pos_y][head_pos_x]==1)
		return 1;
	if(gameBoardInfo[stage-1][head_pos_y][head_pos_x]==2)
	{
		round[stage-1].progress++;
		for(i=0; i<round[stage-1].length; i++)
		{
			if(wpos[i].x == head_pos_x && wpos[i].y == head_pos_y)
			{
				save = GCCP();
				gotoxy(2*GBOARD_WIDTH+15-round[stage-1].length+2*i, 4);
				setcolor(10, 0);
				printf("%c", word[stage-1][i]);
				gotoxy(save.X, save.Y);
				setcolor(7, 0);
				break;
			}
		}
		obs();
	}
	
	if(gameBoardInfo[stage-1][head_pos_y][head_pos_x]==3)
	{
		super = 5000/speed;
		numofitem--; 
		item_create();
	}
	
	if(gameBoardInfo[stage-1][head_pos_y][head_pos_x]==4)
	{
		revealt = 2000/speed;
		numofitem--;
		item_create();
	}
	
	if(gameBoardInfo[stage-1][head_pos_y][head_pos_x]==5)
	{
		ADD_LIFE();
		numofitem--;
		item_create();
	}
	
	if(gameBoardInfo[stage-1][head_pos_y][head_pos_x]==10)
	{
		wallcollision++;
	}
	
	return 0;
}

void gameover()
{
	int key;
	gotoxy(GBOARD_WIDTH, GBOARD_HEIGHT/2);
	//gotoxy(2*GBOARD_WIDTH+7, GBOARD_HEIGHT/2);
	printf("GAME OVER\n");
	Gameover = 1;
	/*system("cls");	
	for(int y=0; y<GBOARD_HEIGHT; y++)
	{
		for(int x=0; x<GBOARD_WIDTH; x++)
			printf("%d", gameBoardInfo[stage-1][y][x]);
		printf("\n");
	}*/
}

void gameclear()
{
	int key;
	gotoxy(GBOARD_WIDTH, GBOARD_HEIGHT/2);
	//gotoxy(2*GBOARD_WIDTH+7, GBOARD_HEIGHT/2);
	printf("GAME CLEAR\n");
	/*system("cls");	
	for(int y=0; y<GBOARD_HEIGHT; y++)
	{
		for(int x=0; x<GBOARD_WIDTH; x++)
			printf("%d", gameBoardInfo[stage-1][y][x]);
		printf("\n");
	}*/
}

void HeadMove()
{
	int i;
	COORD save;
	for(i=0; i<10; i++)
	{	
		if (_kbhit())   // 키보드 입력이 있으면 if문 실행  
        {
        	_getch();
            key_save = _getch();  //방향키 저장  
			reverse = 1;              // reverse 1값 저장
        }
        if (reverse == 1)      //상단 if문에서 reverse 값 1 저장되었으므로, 실행  
        {
            if (!(key_check == DOWN && key_save == UP) &&       //머리 진행 방향이 DOWN일때 UP을 눌렀거나   
                !(key_check == UP && key_save == DOWN) &&       //머리 진행 방향이 up일때 DOWN을 눌렀거나   
                !(key_check == LEFT && key_save == RIGHT) &&    //머리 진행 방향이 LEFT일때 RIGHT를 눌렀거나  
                !(key_check == RIGHT && key_save == LEFT))    //머리 진행 방향이 RIGHT일때 LEFT를 눌르지 않았을 경우만 키값전달
            {
                key_check = key_save;
            }
        }
			
		Sleep(speed/10);
	}
	switch(key_check)
	{
	case LEFT:
		head_pos_x--;
		break;
	case RIGHT:
		head_pos_x++;
		break;
	case UP:
		head_pos_y--;
		break;
	case DOWN:
		head_pos_y++;
		break;
	}
	
	if(SnakeLength>1 && DetectCollision())
	{
		//printf("%d, %d, %d", gameBoardInfo[stage-1][head_pos_y][head_pos_x], head_pos_x, head_pos_y);		//에러 테스트용 
		life--;
		save = GCCP();
		gotoxy(2*GBOARD_WIDTH+8, 10);
		setcolor(12, 0);
		printf("♥(Life) X %d", life);
		gotoxy(save.X, save.Y);
		setcolor(7, 0);
	}
	if(wallcollision>0)
	{
		life=0;
		save = GCCP();
		gotoxy(2*GBOARD_WIDTH+8, 10);
		setcolor(12, 0);
		printf("♥(Life) X %d", life); 
		gotoxy(save.X, save.Y);
		setcolor(7, 0);
	}
	if(life<=0)
	{
		gameover();
	}
	if(key_check == DOWN || key_check == UP || key_check == LEFT || key_check == RIGHT)
	{
		gotoxy(2*snake[SnakeLength-1].x, snake[SnakeLength-1].y);
		setcolor(10,0);
		printf("◇");
		gameBoardInfo[stage-1][snake[SnakeLength-1].y][snake[SnakeLength-1].x] = 1;
		gotoxy(2*head_pos_x, head_pos_y);
		printf("◈");
		setcolor(7,0);
		snake[SnakeLength].x = head_pos_x;
		snake[SnakeLength].y = head_pos_y;
		snake[SnakeLength].endisable = 1;
		SnakeLength++;
	}
}

void SUPER_EFFECT()
{
	int i;
	COORD save;
	for(i=0; i<10; i++)
	{	
		if (_kbhit())   // 키보드 입력이 있으면 if문 실행  
        {
        	_getch();
            key_save = _getch();  //방향키 저장  
			reverse = 1;              // reverse 1값 저장
        }
        if (reverse == 1)      //상단 if문에서 reverse 값 1 저장되었으므로, 실행  
        {
            key_check = key_save;
        }
			
		Sleep(speed/10);
	}
	switch(key_check)
	{
	case LEFT:
		head_pos_x--;
		break;
	case RIGHT:
		head_pos_x++;
		break;
	case UP:
		head_pos_y--;
		break;
	case DOWN:
		head_pos_y++;
		break;
	}
	
	DetectCollision();
	
	if(wallcollision>0)
	{
		life=0;
		save = GCCP();
		gotoxy(2*GBOARD_WIDTH+8, 10);
		setcolor(12, 0);
		printf("♥(Life) X %d", life);
		gotoxy(save.X, save.Y);
		setcolor(7, 0);
	}
	if(life<=0)
	{
		gameover();
	}
	
	if(key_check == DOWN || key_check == UP || key_check == LEFT || key_check == RIGHT)
	{
		gotoxy(2*snake[SnakeLength-1].x, snake[SnakeLength-1].y);
		printf(" ");
		gameBoardInfo[stage-1][snake[SnakeLength-1].y][snake[SnakeLength-1].x] = 0;
		gotoxy(2*head_pos_x, head_pos_y);
		setcolor(11,0);
		printf("◈");
		setcolor(7,0);
		snake[SnakeLength].x = head_pos_x;
		snake[SnakeLength].y = head_pos_y;
		snake[SnakeLength].endisable = 1;
		SnakeLength++;
	}
}

void DrawGameBoard()
{
	int x, y;
	// 윗줄 
	for(x=0; x<GBOARD_WIDTH; x++)
		printf("▦");
	//세로줄 
	printf("\n");
	for(y=0; y<GBOARD_HEIGHT-2 ;y++)
	{
		printf("▦");
		for(x=0; x<2*(GBOARD_WIDTH-2); x++)
			printf(" ");
		printf("▦\n");
	}
	//아랫줄 
	for(x=0; x<GBOARD_WIDTH; x++)
		printf("▦");
} //내부 사이즈 (70-2)*(40-2)

int main()
{
	COORD save;
	srand(time(NULL));
	RemoveCursor();
	//PlaySound(TEXT("menu.wav"),NULL,SND_ASYNC|SND_LOOP);
	
	if(mainframe())
	{
		gotoxy(0, 39);
		return 0;
	}
	
	//PlaySound(TEXT("song.wav"),NULL,SND_ASYNC|SND_LOOP);
	
	while(1)
	{
		int i;
		system("cls");
		system("mode con cols=170 lines=43");
		wposinit();
		RemoveCursor();
		InitGameBoardInfo();
		DrawGameBoard();
		initWordInfo();
		life = 2;
		numofitem = 0;
		key_check = 0;
		key_save = 0;
		if(stage==2)
			speed = 125;
		if(stage==3)
			speed = 100;
		
		gotoxy(2*GBOARD_WIDTH+15-round[stage-1].length, 4);
		for(i=0; i<round[stage-1].length; i++)
		{
			printf("%c ", word[stage-1][i]);
		}
		head_pos_x = GBOARD_WIDTH/2;
		head_pos_y = GBOARD_HEIGHT/2;
		gotoxy(2*head_pos_x, head_pos_y);
		setcolor(10,0);
		printf("◈");
		setcolor(7,0);
		snake[SnakeLength].x = head_pos_x;
		snake[SnakeLength].y = head_pos_y;
		snake[SnakeLength].endisable = 1;
		SnakeLength++;
		
		item_create();
		
		save = GCCP();
		gotoxy(2*GBOARD_WIDTH+8, 10);
		setcolor(12, 0);
		printf("♥(Life) X %d", life);
		gotoxy(save.X, save.Y);
		setcolor(7, 0);
		
		while(1)
		{
			if(revealt>0)
			{
				save = GCCP();
				gotoxy(2*GBOARD_WIDTH+8, 26);
				setcolor(14, 0);
				printf("◎ REVEAL", life);
				gotoxy(2*GBOARD_WIDTH+8, 27);
				printf("remain time : %ds", revealt*speed/1000);
				gotoxy(save.X, save.Y);
				REVEAL(reveal);
				setcolor(7, 0);
				reveal = 1;
				revealt--;
			}
			else
			{
				if(reveal == 1)
				{
					reveal = 0;
					REVEAL(reveal);
					gotoxy(2*GBOARD_WIDTH+8, 26);
					printf("          ", life);
					gotoxy(2*GBOARD_WIDTH+8, 27);
					printf("                ", revealt*speed/1000);
					gotoxy(save.X, save.Y);
					setcolor(7, 0);
				}
				
				
			}
			
			
			if(super>0)
			{
				save = GCCP();
				gotoxy(2*GBOARD_WIDTH+8, 18);
				setcolor(11, 0);
				printf("★ SUPER", life);
				gotoxy(2*GBOARD_WIDTH+8, 19);
				printf("remain time : %ds", super*speed/1000);
				gotoxy(save.X, save.Y);
				setcolor(7, 0);
				
				SUPER_EFFECT();
				super--;
				
				save = GCCP();
				gotoxy(2*GBOARD_WIDTH+8, 18);
				setcolor(11, 0);
				printf("★ SUPER", life);
				gotoxy(2*GBOARD_WIDTH+8, 19);
				printf("remain time : %ds", super*speed/1000); 
				gotoxy(save.X, save.Y);
				setcolor(7, 0);
			}
			else
			{
				save = GCCP();
				gotoxy(2*GBOARD_WIDTH+8, 18);
				setcolor(11, 0);
				printf("        ", life);
				gotoxy(2*GBOARD_WIDTH+8, 19);
				printf("                ", super*speed/1000);
				gotoxy(save.X, save.Y);
				setcolor(7, 0);
				
				HeadMove();
			}
			
			if(Gameover)
				break;
			if(round[stage-1].progress == round[stage-1].length)
			{
				gameclear();
				stage++;
				gotoxy(GBOARD_WIDTH-10, GBOARD_HEIGHT/2+1);
				system("pause");
				break;
			}
		}
		
		if(Gameover)
		{
			Gameover=0;
			break;
		}
		if(stage==5)
		{
			system("cls");
			gotoxy(GBOARD_WIDTH, GBOARD_HEIGHT/2);
			printf("ALL GAME CLEAR");
			break;
		}
	}
	
	gotoxy(0, 39);
	return 0;
}