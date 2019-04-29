#include"main.h"


//void SUPER_ITEM()

void createTail(XY *tails, Node *obs)//보너스 꼬리 아이템 생성 함수
{
	int flag = 1;
	while (flag)
	{
		flag = 0;
		tails->x = rand() % (MAP_X - 1) + 1;
		tails->y = rand() % (MAP_Y - 1) + 1;
		
		while (obs != NULL)//장애물 위치와 중복체크
		{
			if (obs->x == tails->x&&obs->y == tails->y)
			{
				flag = 1;
				break;
			}
			obs = obs->tail;
		}
	}	
	gotoxy(tails->x * 2, tails->y);
	printf("♪");
}
void createitem(XY *tails, Node *obs)//보너스 꼬리 아이템 생성 함수
{
	int flag = 1;
	while (flag)
	{
		flag = 0;
		tails->x = rand() % (MAP_X - 1) + 1;
		tails->y = rand() % (MAP_Y - 1) + 1;

		while (obs != NULL)//장애물 위치와 중복체크
		{
			if (obs->x == tails->x&&obs->y == tails->y)
			{
				flag = 1;
				break;
			}
			obs = obs->tail;
		}
	}
	gotoxy(tails->x * 2, tails->y);
	
	printf("apple");
}

void createObs(Node *Head, Node **obs, XY *tails) 
{
	Node *tmp = *obs;
	int flag = 1;
	XY oxy = { 0,0 };
	while(flag)
	{
		flag = 0;
		oxy.x = rand() % (MAP_X - 1) + 1;
		oxy.y = rand() % (MAP_Y - 1) + 1;
		if ((oxy.x == tails->x&&oxy.y == tails->y) || (oxy.x == Head->x&&oxy.y == Head->y))
		{
			flag = 1;
			continue;
		}
		while (tmp != NULL)
		{
			if (tmp->x == oxy.x&&tmp->y == oxy.y)
			{
				flag = 1;
				break;
			}
			tmp = tmp->tail;
		}
	}
	insertObs(&(*obs), oxy.x, oxy.y);
	gotoxy(oxy.x * 2, oxy.y);
	printf("▦");
}

void checkObject(Node **HEAD, XY *tails, Node **obs)
{
 

	Node *tmp = (*HEAD)->tail;

	checkWall(*HEAD);//벽
	
	while (tmp != NULL)
	{

		if (tmp->x == (*HEAD)->x&&tmp->y == (*HEAD)->y)
			end_Game();
		tmp = tmp->tail;
	}

	if ((tails->x == (*HEAD)->x) && (tails->y == (*HEAD)->y))
	{
		insertNode(&(*HEAD), (*HEAD)->x, (*HEAD)->y);
		(*HEAD)->t++;
		createTail(tails, *obs);
		createObs(*HEAD, &(*obs), tails);
		createObs(*HEAD, &(*obs), tails);
	}

	while (*obs != NULL)
	{
		if ((*obs)->x == (*HEAD)->x && (*obs)->y == (*HEAD)->y)
			end_Game();
		obs = &(*obs)->tail;
	}
}

void moveSnake(Node *HEAD,int s)
{
	Node *tmp = HEAD;
	XY tmp1 = { HEAD->x,HEAD->y };
	XY tmp2 = tmp1;
	if (s == SEE_LEFT)
		HEAD->x -= 1;
	else if (s == SEE_RIGHT)
		HEAD->x += 1;
	else if (s == SEE_UP)
		HEAD->y -= 1;
	else
		HEAD->y += 1;
	HEAD = HEAD->tail;
	while (HEAD != NULL)//꼬리들 좌표 전달
	{
		tmp2.x = HEAD->x;
		tmp2.y = HEAD->y;
		HEAD->x = tmp1.x;
		HEAD->y = tmp1.y;
		tmp1.x = tmp2.x;
		tmp1.y = tmp2.y;
		HEAD = HEAD->tail;
	}
	gotoxy(tmp2.x * 2, tmp2.y);//맨 뒤 꼬리 지우기
	//printf(" ");
	gotoxy(tmp->x * 2, tmp->y);//머리출력
	printf("◎");
	if(tmp->tail != NULL)//몸통

	
	{ 
		gotoxy(tmp->tail->x * 2, tmp->tail->y);
		
			
		//printf("%c",a);
		
		//insertNode()
	}
}
