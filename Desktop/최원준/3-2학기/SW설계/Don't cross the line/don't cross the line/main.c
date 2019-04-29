#include "main.h"

int mainframe()
{
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

	int position = 0;
	int check = 0;

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
				gotoxy(67, 35);
				//	printf("%d", position);
				break;
			case DOWN:
				if (position < 1)
					position++;
				gotoxy(67, 35);
				//	printf("%d", position);
				break;
			case ENTER:
				return (position + 1) % 2;					//Game start에서 엔터를 쳤을 경우 1을 반환, Exit에서 엔터를 쳤을 경우 0을 반환
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
		{
			//키 입력이 없을때
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

void RemoveCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void main()
{
	Node *HEAD = NULL;
	XY tails = { 0,0 };
	int gamestart = 1;
	RemoveCursor();
	gamestart = mainframe();
	gotoxy(67, 36);
	printf("%d", gamestart);
	srand((unsigned)time(NULL));
	_getch();
	if (gamestart == 0)
		return;
	system("cls");
	init_Game(&HEAD, &tails);
	start_Game(&HEAD, &tails);
}