#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct deque {

	struct deque *left;
	struct deque *right;
	int data;

}deque;


typedef struct QUE {

	struct deque  *front;
	struct deque * rear;

}node;

node * createdeque() {
	node *Q=(node*)malloc(sizeof(node));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;


}

int isEmpty(node*Q) {

	if (Q->front == Q->rear)
	{
		return 0;
	}
	else
	{
		return 1;

	}
}

void add_front(node*Q, int info)
{
	deque *temp = (deque*)malloc(sizeof(deque));
	
	//2가지 경우 엠티큐 OR 내용이있을경우

	temp->data = info;
	

	if (Q->front ==NULL)
	{
		Q->front = temp;
		Q->rear = temp;
		temp->left = NULL;
		temp->right = NULL;
		
		
	}
	else if(Q->front!=Q->rear)
	{

		Q->front->left = temp;
		temp->right = Q->front;
		Q->front = temp;

	}
}


void add_rear(node *Q, int info)
{
	deque *temp = (deque*)malloc(sizeof(deque));

	if (Q->front == NULL && Q->rear == NULL)
	{
		Q->front = temp;
		Q->rear = temp;
		temp->data = info;
		temp->left = NULL;
		temp->right = NULL;
		//printf("clear\n\n\n");

	}
	else
	{
		Q->rear->right = temp;
		temp->left = Q->rear;
		temp->data = info;
		temp->right = NULL;
	}
}

void delete_front(node*Q)
{
	deque* temp;

	temp = Q->front;
	Q->front = Q->front->right;
	free(temp);



}
void delete_rear(node* Q)
{
	deque *temp;
	temp = Q->rear;
	Q->rear = Q->rear->left;
	free(temp);
}
void print_QUE(node*Q)
{
	node * temp;
	temp = Q->front;
	while (temp)
	{
		printf(" %d", temp->front->data);
	
		temp= temp->front->right;

	}
}
int main() {
	char op,location;
	int n,data;
	int i;


	node * L;
	L=createdeque ;
	
		scanf("%d", &n);
		
		//printf("clear\n\n\n");
		for (i = 0; i < n; i++)
		{

			scanf("%c", &op);

			switch (op) {

			case 'A':
			{	scanf("%c", &location);
			scanf("%d", &data);

			if (location == 'F')
			{
				add_front(L, data);
			}
			else if (location == 'R')
			{
				add_rear(L, data);
			}
			break;
			}
			//
			case 'D':
			{	scanf("%c", &location);
			scanf("%d", &data);
			if (location == 'F')
			{
				delete_front(L);
			}
			else if (location == 'R')
			{
				delete_rear(L);
			}
			break;
			}

			case 'P':print_QUE(L);
				break;
			}
			//printf("clear\n\n\n");
		}



	
	return 0;
}
