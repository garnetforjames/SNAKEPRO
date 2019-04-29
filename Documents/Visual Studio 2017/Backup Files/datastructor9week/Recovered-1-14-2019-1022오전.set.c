#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>






typedef struct queue {

	int data;
	struct queue *left;
	struct queue *right;

}Que;

typedef struct {
	Que *front;
	Que*rear;

}QueueType;

QueueType * createQue()
{
	QueueType *Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}
int isEmpty(QueueType *Q)
{
	if (Q->front == NULL)
	{
		printf("it is empty Que!\n");
		return 1;

	}
	else
		return 0;
}

