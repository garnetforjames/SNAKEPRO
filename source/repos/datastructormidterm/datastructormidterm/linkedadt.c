
#include<stdio.h>
#include<stdlib.h>



typedef struct listNode {
	int Data;
	struct listNode *Next;
	struct listNode *Prev;

}Node;

Node* createNode(int data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));

	newNode->Data = data;
	newNode->Next = NULL;
	newNode->Prev = NULL;

	return newNode;
}

void deleteNode(Node* Node) {

	free(Node);

}

Node* getNodeAt(Node* head,int index)
{
	Node* horse = head;
	int count = 0;

	while (horse != NULL)
	{
		if (count++ == index)
		{
			return horse;
		}
		horse = horse->Next;
	}

	return NULL;

}
int countNode(Node *head)
{

	int count = 0;
	Node*horse = head;
	while (horse != NULL)
	{
		horse = horse->Next;
		count++;
	}
	return count;

}

void addNode(Node** Head, Node* newNode)
{
	// �ƹ� ��尡 ���°��
	Node * horse = *Head;
	if (*Head == NULL  )
	{
		*Head = newNode;

	}

	else 
	{
		while (horse->Next != NULL)
		{
			horse = horse->Next;
		}
		horse->Next = newNode;
		newNode->Prev = horse;

	}
}
void insertNode(Node* Current, Node*newNode)
{
	//���������

	if (Current->Prev == NULL && Current->Next == NULL)
	{
		Current->Next = newNode;
		newNode->Prev = Current;
	}

	//��尡 �ƴ� ��

	if (Current ->Next== NULL)
	{
		Current->Next = newNode;
		newNode->Prev = Current;

	}

	else
	{
		Current->Next->Prev = newNode;
		newNode->Prev = Current;
		newNode->Next = Current->Next;
		Current->Next = newNode;

	}



}

void removedNode(Node** head, Node * remove) 
{
	//remove��尡 �ص��϶�
	if (*head == remove)
	{
		*head = remove->Next;

	}

	//remove�� Next�� NUll�� �ƴҶ�

	if (remove->Next != NULL) {
		remove->Next->Prev = remove->Prev;

	}

	//remove�� prev�� NULL�� �ƴҶ�

	if (remove->Prev != NULL)
	{
		remove->Prev->Next = remove->Next;

	}
	deleteNode(remove);


}

main() {





}