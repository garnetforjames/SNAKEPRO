#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>




typedef struct listNode {

	struct listNode *next;
	int data;

}node;


typedef struct {
	node*head;

}headnode;

headnode* createnode(void)
{
	headnode*L;
	L = (headnode*)malloc(sizeof(headnode));
	L->head = NULL;
	return L;

}

void insertNode(headnode*L, int data)
{
	node*newnode;
	node*temp;
	newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	//printf("clear\n");
	if (L->head == NULL)
	{
		L->head = newnode;
		return;
	}
	else
	{
		temp = L->head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newnode;
	}
}

void union_set(headnode *L, headnode*M)
{
	node *tmp1, *tmp2;
	int flag = 0;
	tmp1 = L->head;
	tmp2 = M->head;

	while (1)
	{
		if (tmp1 == NULL && tmp2 == NULL)
		{
			break;
		}

		if (tmp1 == NULL)
		{
			printf(" %d", tmp2->data);
			flag = 1;
			tmp2 = tmp2->next;
			continue;
		}

		else if (tmp2 == NULL)
		{
			printf(" %d", tmp1->data);
			flag = 1;
			tmp1 = tmp1->next;
			continue;
		}

		if (tmp1->data > tmp2->data) {
			printf(" %d", tmp2->data);
			flag = 1;
			tmp2 = tmp2->next;
			continue;
		}
		else if (tmp1->data < tmp2->data)
		{
			printf(" %d", tmp1->data);
			flag = 1;
			tmp1 = tmp1->next;
			continue;
		}
		else  	if (tmp1->data == tmp2->data) {
			printf(" %d", tmp1->data);
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			continue;
		}


	}
	if (flag == 0)
	{
		printf(" 0");
	}
	printf("\n");
	return;

}

void intersect(headnode*L, headnode*M)
{
	int flag = 0;
	node *tmp1, *tmp2;
	tmp1 = L->head;
	tmp2 = M->head;
	while (1)
	{

		if (tmp1 == NULL || tmp2 == NULL)
		{
			break;
		}

		if (tmp1->data == tmp2->data)
		{
			flag = 1;
			printf(" %d", tmp1->data);
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			continue;
		}
		else if (tmp1->data > tmp2->data)
		{
			tmp2 = tmp2->next;
		}
		else
		{
			tmp1 = tmp1->next;

		}
	}
	//printf("clear\n");
	if (flag == 0)
	{
		printf(" 0\n");
		return;
	}
}
void print(headnode*L, headnode*M)
{
	node* tmp1;
	tmp1 = L->head;

	while (tmp1 != NULL)
	{
		printf(" %d", tmp1->data);
		tmp1 = tmp1->next;
	}
	printf("\n");
}
int main() {


	headnode *L, *M;
	L = createnode();
	M = createnode();
	int A, i, data;

	scanf("%d", &A);

	for (i = 0; i < A; i++)
	{
		scanf("%d", &data);
		insertNode(L, data);
	}
	//printf("clear\n");
	scanf("%d", &A);
	for (i = 0; i < A; i++) {
		scanf("%d", &data);
		insertNode(M, data);
	}
	//print(L, M);
	union_set(L, M);
	intersect(L, M);

	return 0;
}