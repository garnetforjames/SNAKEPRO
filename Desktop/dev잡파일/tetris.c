#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>



#define BOARD_HEIGHT 20 // ������

#define BOARD_WIDTH 10  // ������

#define BOARD_X 4 //���忭x��ǥ

#define BOARD_Y 2 //������y��ǥ



#define CBLOCK_X 13

#define CBLOCK_Y 2

#define DELAY 100//����

#define RAND 4//����



#define LEFT 75

#define RIGHT 77

#define UP 72

#define DOWN 80

#define SPACE 32



int static score=0; //��������

int static level=1; //���ӷ���

int static speed=180;

int curX,curY; //�ܼ�Ŀ��

int board[BOARD_HEIGHT+1][BOARD_WIDTH+2]={0,};

int block[][4][4]={

      

        {

                {0,0,0,0},

                {1,0,0,0},

                {1,1,1,0},

                {0,0,0,0}},

        {

                {0,0,1,0},

                {0,0,1,0},

                {0,1,1,0},

                {0,0,0,0}},

        {

                {1,1,1,0},

                {0,0,1,0},

                {0,0,0,0},

                {0,0,0,0}},

        {

                {1,1,0,0},

                {1,0,0,0},

                {1,0,0,0},

                {0,0,0,0}},



    {

{0, 0, 0, 0},

{0, 0, 1, 0},

{1, 1, 1, 0},

{0, 0, 0, 0} },  

{

{0, 1, 1, 0},

{0, 0, 1, 0},

{0, 0, 1, 0},

{0, 0, 0, 0} },   

{

{1, 1, 1, 0},

{1, 0, 0, 0},

{0, 0, 0, 0},

{0, 0, 0, 0} },   

{

{1, 0, 0, 0},

{1, 0, 0, 0},

{1, 1, 0, 0},

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

{0, 0, 1, 0},

{0, 1, 1, 0},

{0, 1, 0, 0},

{0, 0, 0, 0} },

{  

{0, 0, 0, 0},

{1, 1, 0, 0},

{0, 1, 1, 0},

{0, 0, 0, 0} },  

{

{0, 0, 1, 0},

{0, 1, 1, 0},

{0, 1, 0, 0},

{0, 0, 0, 0} },



};

void removeCursor(void)

{

        CONSOLE_CURSOR_INFO curInfo;

        GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

        curInfo.bVisible=0;

        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}



void setCursor(int x, int y)

{

        COORD pos={x,y};

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);

}

COORD getCursor(void)

{

        COORD cur;

        CONSOLE_SCREEN_BUFFER_INFO curInfo;



        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);

        cur.X=curInfo.dwCursorPosition.X;

        cur.Y=curInfo.dwCursorPosition.Y;

        return cur;

}

//void showBlock(int rotation);



void showBoard(void)

{

        int x,y;

        

        //�߾Ӻ������

        for(x=1; x<=BOARD_WIDTH+1; x++)

        {

                board[BOARD_HEIGHT][x]=1; //board �迭�߾�1�ν�

                setCursor((BOARD_X)+x*2, BOARD_Y+BOARD_HEIGHT);  //�ܼ���ǥ

                printf("��");

        }

        //���ʺ������

        for(y=0; y<BOARD_HEIGHT+1; y++)

        {

                board[y][0]=1; //board �迭����1�ν�

                setCursor(BOARD_X, BOARD_Y+y);

                if(y==BOARD_HEIGHT)

                        printf("��");

                else

                        printf("��");

        }

        //�����ʺ������

        for(y=0; y<BOARD_HEIGHT+1; y++)

        {

                board[y][BOARD_WIDTH+1]=1; //board �迭������1�ν�

                setCursor(BOARD_X+(BOARD_WIDTH+2)*2, BOARD_Y+y);

                if(y==BOARD_HEIGHT)

                        printf("��");

                else

                        printf("��");

        }

        

        //�𼭸���������

        board[20][0]=1;

        board[20][11]=1;

        





        //�����Ǽ��ں���

        //setCursor(6,2);

        //for(y=0; y<=BOARD_HEIGHT; y++){

        //      for(x=0; x<=BOARD_WIDTH+1; x++){

        //              setCursor(4+(x*2),2+y);

        //              printf("%d ",board[y][x]);

        //      }

        //      printf("\n");

        //}





        puts(" ");

}



void initial(int x,int y)

{

        curX=x;

        curY=y;

        setCursor(x,y);

}



//DeleteBlock�Լ��۵�������or �ƴ���Ȯ��

int detect(int rotation,int move1,int move2)

{

        int x,y;

        int arrX,arrY; //�迭��ǥ����

        COORD pos=getCursor();



        arrX=pos.X+move1;

        arrY=pos.Y+move2;

        

        arrX=(arrX/2)-2;

        arrY=arrY-BOARD_Y;



                

        for(y=0; y<4; y++)

        {

                for(x=0; x<4; x++)

                {

                        if( (block[rotation][y][x]==1) && board[arrY+y][arrX+x]==1)

                                return 1;  //����ͺ�����ħ

                }

        }

        return 0;  //��ġ������



}



//��������

void showBlock(int rotation)

{

        int x,y;

        COORD cursor=getCursor();

        int prove;

        //int n=(rotation-1)%4;

        prove=detect(rotation,0,0);

        if(prove==0)

        {

                //�ܼ�â��ġ�����迭������1�����������¾���

                for(y=0; y<4; y++)

                {

                        for(x=0; x<4; x++)

                        {

                                setCursor(cursor.X + (x*2), cursor.Y+ y);

                                if(block[rotation][y][x]==1)

                                        printf("��");

                        }

                }

                setCursor(cursor.X, cursor.Y);

        }

}



        

void DeleteBlock(int rotation,int move1,int move2)

{

        int pr;

        int x,y;

        

        COORD cursor=getCursor();



        pr=detect(rotation,move1,move2);

        

        if(pr==0)

        {

                for(y=0; y<4; y++)

                {

                        for(x=0; x<4; x++)

                        {

                                        setCursor(cursor.X+ (x*2), cursor.Y+y);

                                        if(block[rotation][y][x]==1)

                                                printf(" ");

                        }

                }

                setCursor(cursor.X+move1, cursor.Y+move2);

        }

}





//��Ϻ����ǿ���1�ν�

void boardConginition(int n,int move1, int move2)

{

        int x1,y1;

        COORD pos=getCursor();

        

        int arrX = pos.X + move1;  //�ܼ���ǥ��

        int arrY = pos.Y + move2;  //�ܼ���ǥ��

        int x,y;



        //Ŀ����ġ�����迭��ġ��������

        arrX=arrX/2-2; //�ܼ���ǥ�迭����ȯ��

        arrY=arrY-2;     //�ܼ���ǥ�迭�ຯȯ��



        //�����ǿ�������̵���1�ν�

        for(y=0; y<4; y++)

        {

                for(x=0; x<4; x++)

                {

                        if(block[n][y][x]==1)

                        {

                                board[arrY+y][arrX+x] =1;

                        }

                }

        }

        return ;



}



//�迭��Ͽű�

void array_down(int column)

{

        int y,x;

        

        //board�迭����ٿ�

        for(y=column; y>=0; y--)

        {

                for(x=1; x<=10; x++)

                {

                        board[y][x]=board[y-1][x];

                }

        }

        //board�迭0�࿡0����

        for(x=1; x<=10; x++)

                board[0][x]=0;



        /*board�迭1����ü���*/

        for(y=1; y<=19; y++)

        {

                for(x=1; x<=10; x++)

                {

                        setCursor((BOARD_X)+x*2+1, y+BOARD_Y);

                        if(board[y][x]==1)

                                printf("��");

                        else

                                printf("  ");

                }

        }

                

}

//�������ھ����

void scoreLevel(void)

{



        setCursor(40,3);

        printf("�ڷ�������Ŭ�����");

        setCursor(40,5);

        printf("����\n",level);

        setCursor(40,7);

        printf("����\n",score);

}

//�������ھ���

void countScore(void)

{

        score+=10;

        if(score%30==0)

        {

                level+=1;

                speed-=30;

        }

        scoreLevel();

}

/* 1~10�������ǿ���ü��1�εǸ��ϻ����

        �������array_down�Լ�����*/

void control(void)

{

        int i;

        int x,y;

        int z=0;

        

        //19����ͽ����ؼ�1������ݺ�

        for(y=19; y>=1; y--)

        {

                //���������4���ݺ�

                for(z=0; z<4; z++)

                {

                        i=0;

                        //1������10����������

                        for(x=1; x<11; x++)

                        {

                                //�����

                                if(board[y][x]==1)

                                {

                                        i++;

                                        //1��10�������ϻ���

                                        if(i==10)

                                        {

                                                for(x=1; x<11; x++)

                                                {

                                                        setCursor((x+2)*2,y+2);

                                                        printf("  ");

                                                }

                                                //��������κ�ϳ�����

                                                countScore();

                                                array_down(y);

                                        }



                                }

                        }

                }

        }



        

}



int gameOver(int rotation)

{

        if(detect(rotation,0,0))

                return 5; //���ӳ�

        else

                return 0;

}



int gameWin(void)

{

        if(level==10)

                return 1; //���ӽ�

        else

                return 0;

}



void moveBlock(void)

{

        

        int n;

        int kb;

        int prove;

        int winOver;//���Ӱ��

        int c=2;
		srand(time(NULL));

        

        

        //���ӽ��۳�

        while(1)

        {

                

                initial(CBLOCK_X,CBLOCK_Y); //��ϻ�����ġ��ǥ

                

                n=(rand()%RAND)*4;//��������

                n=rand()%RAND;

                n=rand()%7;//��ϸ�����

                n = n * 4;

                 n = 6;



                if(gameWin())

                {

                        setCursor(35,20);

                        printf("GAME WIN");

                        getchar();

                        exit(1);

                }

                if(gameOver(n))

                        break;

                                

                

                //����Ѱ������̵�

                while(1)                                

                {

                        int ww=0;

                        int var;

                        int k=0;

                        int tmp;

                        //��ϾƷ����̵�

        

                        while(!_kbhit())

                        {

                                //��ϼ�

                                showBlock(n);

                                //������Ÿ��

                                Sleep(DELAY+speed);

                                //�Ʒ��̵���1�ִ���Ȯ��

                                if(detect(n,0,1)==1) 

                                {       

                                        ww=1;

                                        boardConginition(n,0,0);//���庮���迭1�߰�

                                        control();

                                        break;

                                }

                                DeleteBlock(n,0,1);  //board�迭+1��

                        }

                        //detect�Լ������迭��1�߽߰�����

                        if(ww==1)

                                break;

                        

                        kb=_getch();

                      

                        switch(kb)

                        {

                                case LEFT:

                                        DeleteBlock(n,-2,0);

                                        showBlock(n);

                                        break;

                                case RIGHT:

                                        DeleteBlock(n,2,0);

                                        showBlock(n);

                                        break;

                                case UP:

                                        

                                        // ù�������Ѵ�

                                        k = n / 4;

                                        k *= 4;

                                

                                        // �����������������ΰ�

                                        if((n+1) <= (k+3))

                                        {

                                                k = n + 1;

                                        }



                                        prove=detect(k,0,0);

                                        if(prove==0)

                                        {

                                                DeleteBlock(n,0,0);

                                                n = k;

                                                showBlock(n);

                                                break;

                                        }

                                        break;

                                case DOWN:

                                        DeleteBlock(n,0,2);

                                        //showBlock(n);

                                        break;

                                case SPACE:

                                        while(1)

                                        {

                                                DeleteBlock(n,0,1);

                                                if(detect(n,0,1)==1 )

                                                {

                                                        showBlock(n);

                                                        boardConginition(n,0,0);

                                                        break;

                                                }

                                                

                                        }





                        }

                        

                }

                

        }

        

        setCursor(35,20);

                printf("GAME OVER");

}









int main()

{

        removeCursor(); //Ŀ������������



        setCursor(2,1); //����ǥ�ý�����ġ����

        showBoard(); //�������

        scoreLevel();

        

        moveBlock(); //������¿�����

        

        getchar();



}


/*

//�ڵ��Է� 
#include <stdio.h>
#include <windows.h>
int main(void)
{
COORD p1={0, 0}; // structure included in windows.h
COORD p2={6, 6}; // composed of x, y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p1);
printf("��");
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p2);
printf("��");
getchar();
return 0;
}


#include <stdio.h>
#include <windows.h>
int main(void)
{
CONSOLE_SCREEN_BUFFER_INFO curInfo; // structure included in windows.h
HANDLE console;
console=GetStdHandle(STD_OUTPUT_HANDLE);
GetConsoleScreenBufferInfo(console, &curInfo);
printf("[%d, %d] \n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);
puts(��ù��° �ȳ��ϼ���");
GetConsoleScreenBufferInfo(console, &curInfo);
printf("[%d, %d] \n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);
puts(���ι�° �ȳ��ϼ���");
getchar();
return 0;
}

#include<stdio.h>
#include<Windows.h>
int main(void){

	int i=0,j=0;
	HANDLE console;
	console=GetStdHandle(STD_OUTPUT_HANDLE);

			for(i=0;i<5;i=i++){
				for(j=0;j<10;j+=2){

	
				 COORD p1={j,i};

				SetConsoleCursorPosition(console,p1);
				 printf("�Ҭ� ");
				}
			}
		
		
			
		
		
	
	
	
	getchar();

return 0;}

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

                printf("�Ҭ�");

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

//Ű����
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "block.h"
#include <conio.h> 


int block_id;

void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
    curInfo.bVisible=0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
}

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
    RemoveCursor();
	int x,y;
    COORD curPos=GetCurrentCursorPos();
    
    for(y=0; y<4; y++)
    {
        for(x=0; x<4; x++)
        {
            SetCurrentCursorPos(curPos.X + (x*2), curPos.Y + y);
			
            if(blockInfo[y][x] == 1)
                printf("�Ҭ�");
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

void BlockDown()
{
	DeleteBlock(blockModel[block_id]);
	SetCurrentCursorPos(GetCurrentCursorPos().X, GetCurrentCursorPos().Y+1);
	ShowBlock(blockModel[block_id]);
	 
}

void RotateBlock()
{
	int block_base;
	DeleteBlock(blockModel[block_id]);
	block_base = block_id - block_id%4;
	block_id = block_base + (block_id+1)%4;
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

int main()
{	int key;

	RemoveCursor();
	srand((unsigned int)time(NULL));
	SetCurrentCursorPos(0, 0);
    int i;
	block_id = (rand()%7)*4;
    ShowBlock(blockModel[block_id]);
 	while(1){
		
		while(!_kbhit()){
			
			
		}	 
		key=_getch();
		switch(key){
			
		case 97:
			ShiftLeft();
			break;
		case 100:
			ShiftRight();
			break;
		case 119:
			BlockUP();
			break;
		case 120:
			BlockDown();
			break;
		case 113:
			BlockLU();
			break;
		case 101:
			BlockRU();
			break;
		case 112:
			BlockLD();
			break;
		case 99:
			BlockRD();
			break;
			
			
			
			
		}
	 	
	 	
	 }
    
	
	getchar();
	return 0;
}
 
//memory copy
v memcpy ( ) �Լ� ��� ��

memcpy(dest, src, size )


dest  - address of memory recorded(destination)
src   - address of memory read(source)
size  - size of byte

v memcpy () ��� ����


  memcpy(&gameBoardInfo[8][1],


                     &gameBoardInfo[7][1], GBOARD_WIDTH * sizeof(int));


for(line=0; y-line>0  ; line++)

{

   memcpy(&gameBoardInfo[ y-line ][1], &gameBoardInfo[  y-line-1   ][1],

                                            GBOARD_WIDTH*sizeof(int) );





    for(x=1; x<GBOARD_WIDTH+1; x++)

    {  

       if(gameBoardInfo[y][x]!=1)

       break;

    } 


*/

