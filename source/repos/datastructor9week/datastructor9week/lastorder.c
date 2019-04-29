#pragma warning (disable: 4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>




typedef int element;
int q;

typedef struct {

	element *queue;
	int front, rear;

}QueueType;


QueueType*createQueue(int n)
{
	int i;
	QueueType *Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->queue = (element*)malloc(n * sizeof(element));
	for (i = 0; i < n; i++)
	{
		Q->queue[i] = 0;

	}
	
	Q->front = 0;
	Q->rear = 0;
	return Q;

}


int isEmpty(QueueType *Q) 
{
	if (Q->front == Q-> rear )
	{
		//printf("Queue is empty!\n");
		return 1;
	}

	else return 0;
}


int isFull(QueueType*Q)
{
	if ((Q->rear+1)%q == Q->front)
	{
		//printf("Queue is Full!\n");
		return 1;
	}
	else
		return 0;
}
void printQueue(QueueType*Q, int size)

{
	int i;
	for (i = 0; i < size; i++)
	{
		printf(" %d", Q->queue[i]);
	}
	printf("\n");
}

void enQueue(QueueType*Q,int item,int size)
{
	if (isFull(Q))
	{
		printf("overflow");
		printQueue(Q, size);
		exit(1);
	}
	
	else
	{
		Q->rear = (Q->rear + 1) % q;

		Q->queue[Q->rear] = item;
		return;
	}

}

element deQueue(QueueType* Q)
{
	int temp;
	if (isEmpty(Q))
	{
		printf("underflow\n");

		exit(1);
	}
	else 
	{
		temp = Q->queue[Q->front++];

		Q->queue[Q->front]=0;
		return temp;

	}
}
element peek(QueueType*Q)
{

	if (isEmpty(Q))
	{
		
		exit(1);

	}
	else
	{
		return Q->queue[Q->front + 1];
	}

}



void main() 


{

	int n, i, data;
	char order;
	QueueType  *que;
	

	scanf("%d", &q);
	scanf("%d", &n);
	que=createQueue(q);

	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &order);
		switch (order)
		{
			
		case 'I':scanf("%d", &data);
				 enQueue(que, data,q);
				 //printf("clear\n\n");
				 break;
		case'P':
			     printQueue(que,q);
				 break;
		case'D':
				deQueue(que);
				break;
		
		}
	}




}
