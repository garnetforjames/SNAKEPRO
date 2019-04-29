#include "main.h"
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
Node* getNode()//노드 생성
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->tail = NULL;
	return newNode;
}
void insertNode(Node **head, int x, int y)//queue
{
	if (*head == NULL)
	{
		*head = getNode();
		(*head)->x = x;
		(*head)->y = y;
		(*head)->t = 0;
	}
	else
		insertNode(&(*head)->tail, x, y);
}
void insertObs(Node **Obs, int x, int y)//스택
{
	Node *tmp = *Obs;
	*Obs = getNode();
	(*Obs)->x = x;
	(*Obs)->y = y;
	if (*Obs != NULL)
		(*Obs)->tail = tmp;
}