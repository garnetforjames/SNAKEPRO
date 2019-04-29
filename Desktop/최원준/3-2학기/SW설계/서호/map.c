#include "main.h"
void init_Game(Node **HEAD, XY *tails)//게임 초기화
{
	int i = 0, k = 0;
	for (i = 0; i <= MAP_Y; i++)//맵 테두리 만들기
	{
		for (k = 0; k <= MAP_X; k++)
		{
			if (i == 0 || i == MAP_Y || k == 0)
			{
				printf("▥");
			}
			if (k == MAP_X)
			{
				gotoxy(MAP_X * 2, i);
				printf("▤");
			}
		}
		printf("\n");
	}
	insertNode(&(*HEAD), MAP_X - 2, MAP_Y / 2);
	createTail(tails, NULL);
}

void checkWall(Node *HEAD)
{
	if (HEAD->x < 1 || HEAD->x >= MAP_X || HEAD->y < 1 || HEAD->y >= MAP_Y)
		end_Game();
}