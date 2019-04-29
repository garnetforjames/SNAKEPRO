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
	else 
	{

		Q->front->left = temp;
		temp->right = Q->front;
		Q->front = temp;

	}
}


void add_rear(node *Q, int info)
{
	deque *temp = (deque*)malloc(sizeof(deque));

	temp->data = info;
	if (Q->front == NULL )
	{
		Q->front = temp;
		Q->rear = temp;
		
		temp->left = NULL;
		temp->right = NULL;
		//printf("clear\n\n\n");

	}
	else
	{
		Q->rear->right= temp;
		temp->left = Q->rear;
		Q->rear = temp;
		temp->right = NULL;
	}
}

void delete_front(node*Q)
{
	deque* temp;

	temp = Q->front;
	if (Q->rear == Q->front)
	{
		printf("underflow\n");
		exit(1);
	}
	Q->front = Q->front->right;
	free(temp);



}
void delete_rear(node* Q)
{
	deque *temp;
	temp = Q->rear;
	if (Q->rear == Q->front)
	{
		printf("underflow\n");
		exit(1);
	}
	else
	{
		Q->rear = Q->rear->left;
		Q->rear->right = NULL;
		free(temp);
	}

}
void print_QUE(node*Q)
{
	deque * temp;
	temp = Q->front;
	while (temp)
	{
		printf(" %d", temp->data);
	
		temp= temp->right;

	}
	printf("\n");
}
int main() {
	char op,location;
	int n,data;
	int i;


	node  *L;
	L = (node*)malloc(sizeof(node));
	L->front = NULL;
	L->rear = NULL;
	//L=createdeque() ;
	
		scanf("%d", &n);
		getchar();
		//printf("clear\n\n\n");
		for (i = 0; i < n; i++)
		{

			scanf("%c", &op);
	
			switch (op) 
			{

			case 'A':
			{	scanf("%c", &location);
				scanf("%d", &data);
				getchar();
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
				
				getchar();
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
				getchar();
				break;
			}
			//printf("clear\n\n\n");
		}



	
	return 0;
}