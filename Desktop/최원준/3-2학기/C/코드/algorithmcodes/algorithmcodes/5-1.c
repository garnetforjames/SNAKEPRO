#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
void partition(struct Node*source,struct Node** beginRef,struct Node**endRef)
{
	struct Node* p;
	struct Node* q;

	q=source;
	p=source->next;
	while(p!=NULL){
		p=p->next;
		if(p!=NULL){
			q=q->next;
			p=p->next;
		}}
	*beginRef=source;
	*endRef=q->next;
	q->next=NULL;
}

struct Node* sortedMerge(struct Node* a,struct Node *b){
	struct Node* result=NULL;

	if(a==NULL)
	{return (b);}
	else if(b==NULL)
	{return (a);}

	if(a->data<=b->data){
		result =a;
		result->next=sortedMerge(a->next,b);
	}
	else
	{	result =b;
		result->next=sortedMerge(a,b->next);
	}
		return (result);
}
void mergesort(struct Node** headRef){
	struct Node*  head= *headRef;
	struct Node* a;
	struct Node* b;

	if((head==NULL)|| (head->next==NULL))
	{ return ;}

	partition(head,&a,&b);

	mergesort(&a);
	mergesort(&b);

	*headRef =sortedMerge(a,b);
}




void printList(struct Node* node){
	while(node!=NULL){
		printf(" %d",node->data);
		node=node->next;
	}
}
void insertnode(struct Node ** head,int _data){
	struct Node * newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=_data;
	newnode->next=(*head);
	*head=newnode;
}
int main(){

	int size,n,i;

	struct Node* List=NULL;

	scanf("%d",&size);

	for(i=0;i<size;i++){

		scanf("%d",&n);
		insertnode(&List,n);
	}
	mergesort(&List);
	printList(List);
	getchar();
	return 0;
}
