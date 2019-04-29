#include "main.h"

void start_Game(Node **HEAD, XY *tails)
{
	Node *obs = NULL;
	char ip = '\0';
	int s_see = SEE_LEFT, count = 0;
	int gameSpd = 250, score = 0;
	short ctime = (short)time(0);
	short mtime;
	while (1)
	{
		if (_kbhit())
		{
			ip = _getch();
			switch (ip)
			{
			case LEFT:
				s_see = SEE_LEFT;
				break;
			case RIGHT:
				s_see = SEE_RIGHT;
				break;
			case UP:
				s_see = SEE_UP;
				break;
			case DOWN:
				s_see = SEE_DOWN;
				break;
			case ESC:
				exit(1);
				break;
			}
			ip = '\0';
		}
		else 
		{//키 입력이 없을때
			moveSnake(*HEAD, s_see);
			checkObject(HEAD, tails, &obs);
			gotoxy(tails->x * 2, tails->y);
			printf("◈");
			if (obs != NULL)
			{
				gotoxy(obs->x * 2, obs->y);
				printf("▦");
			}
			Sleep(gameSpd);
		}
		mtime = (short)time(0);
		if (mtime - ctime >= 1)//게임 속도 조절
		{
			ctime = mtime;
			count++;
			if (count == 10)
			{
				count = 0;
				if (gameSpd - (*HEAD)->t * 2 > 40)
					gameSpd -= (*HEAD)->t * 2;
			}
			score += ((*HEAD)->t*(*HEAD)->t) * 10 + (*HEAD)->t;//점수 계산
			gotoxy(0, MAP_Y + 1);//점수 출력
			printf("SCORE [%d] / TAILS [%d] / GAME SPEED [%d]", score, (*HEAD)->t, gameSpd);

		}
	}
}

void end_Game() {
	gotoxy(0, MAP_Y / 2);
	printf("               Game Over");
	_getch();
	exit(1);
}

void main()
{
	Node *HEAD = NULL;
	XY tails = { 0,0 };
	srand((unsigned)time(NULL));
	printf("  지렁이 게임 스타트");
	_getch();
	system("cls");
	init_Game(&HEAD, &tails);
	start_Game(&HEAD, &tails);
}