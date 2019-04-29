#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>

#include<string.h>


typedef struct QueueNode {

	struct QueueNode * next;

	struct QueueNode * before;

	int data;


}Queue;

Queue * front;
Queue * rear;


Queue* createQueue(Queue* Q) {

	Queue *temp = (Queue*)malloc(sizeof(Queue));
	Q = temp;
	Q->before = NULL;
	Q->next = NULL;
	front = Q->before;
	rear = Q->before;
	Q->data = 0;
}


Queue* add_front(Queue*Q,int info)

{
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	if (Q->data == 0)
	{
		Q->data = info;
		
	}

	else
	{
	
		temp->data = info;
		temp->next = Q->before;
		temp->before = NULL;
		Q->before = temp->next;
	}

}

Queue* add_rear(Queue*Q, int info)
{
	Queue *temp,*que;
	
	while (temp != NULL)
	{
		temp = temp->next;

	}
	*que = (*Queue)malloc(sizeof(Queue));


}