#include<stdio.h>
#include<stdlib.h>

node * get_entry(int position);

typedef struct node{
	struct node *before;
	int data;
	struct node *next;


}node;

node *header;
node *tailer;

node * getNode()
{

	node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}

void initlist()
{
	header=getNode();
	tailer=getNode();

	header->next=tailer;
	tailer->before=header;
	return;

}

node * add(int position, int item)
{
	node * temp=getNode();
	node *p= get_entry(position);

	if(p==NULL)
	{
		return p;
	}
	temp->data=item;
	temp->before=p;
	temp->next=p->next;
	p->next->before=temp;
	p->next=temp;
	
	return temp;

	


}

node * Delete(int position){


}

node * get_entry(int position){
	int i;
	node *temp=header;

	for(i=0;i<position;i++){
		temp=temp->next;
		if(temp==tailer)
		{
			printf("Invalid data\n");
			temp=NULL;
			return temp;
		}

	}
	return temp;


}

void print(){

	node *temp;
	temp=header;

	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}

	return;

}

int main()
{
	int position;
	int n,i,data;
	char input;

	initlist();
	scanf("%d",&n);

	for(i=0;i<n;i++){

		scanf("%c",&input);

		switch(input){

		case 'A':scanf("%d %d",&position,&data);
				 add(position,data);
				 break;



		case 'D':scanf("%d",&position);
				 Delete(position);
				 break;

		case 'P':print();
				 break;

		case 'G':scanf("%d",&position);
				 get_entry(position);
				 break;


		default: break;

		}

	}
	
	return 0;
}

