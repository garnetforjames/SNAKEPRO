#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int m;


typedef struct array{

	int data;

	struct array *Link;
}Bucket;


void searchdata(Bucket *p,int data){
	int value;
	Bucket *q,*r;
	q=p;
	value=data%m;

	if((q+value)->data==data){
		
		printf("%d\n",value);
	}
	else if((q+value)->data!=data&&(q+value)->Link==NULL){
		printf("0\n");
	}
	else {

		r=q+value;
		while(r->Link!=NULL){
			
			if(r->data==data){
				printf("%d\n",value);
				return;}

			r=r->Link;


		}


	
	}}

void insertdata(Bucket* p,int data){
	Bucket *q;
	int idx;
	q=p;
	idx=data%m;
	q=p+idx;
	if(q->data==0){
		q->data=data;}
	if(q->data!=0){
		q=q->Link;
		q->data=data;
	}
	else q=q->Link;
		 insertdata(q,data);



}

void initBucket( Bucket *p){

	Bucket *q;
	for(q=p;q<p+m;q++){
		q->data=0;
	}

}

void printBucket(Bucket*p){
	Bucket *q,*r;
	for(q=p;q<p+m;q++){
		if(q->Link==NULL){
			printf(" %d",q->data);
		}
		else

		{	r=q;
			while(r->Link!=NULL){
				printf(" %d",r->data);
				r=r->Link;


			}

	}
}
}

void removedata(Bucket*p,int data){
	Bucket *q,*r;
	int value;
	q=p;
	r=p;
	value=data%m;
	r=q+value;
	if((q+value)->data==data){
		(q+value)->data=0;
		printf("%d\n",value);
		return;
		}
	else
	{	while(r->Link!=NULL){

		if(r->data==data){
			printf("%d\n",value);
			return;
		}
		r=r->Link;
	}
	}
	printf("0\n");
	return;

}
int main(){

	Bucket bucket[100];
	Bucket *p;

	char op;
	int data;
	
	scanf("%d",&m);
	p=bucket;
	

	while(1){

		scanf("%c",&op);

		switch(op){

		case 'i':	scanf("%d",&data);
					insertdata(p,data);
					break;

		case 's':	scanf("%d",&data);
					searchdata(p,data);
					break;

		case 'd':	scanf("%d",&data);
					removedata(p,data);
					break;


		case 'p':	printBucket(p);
					break;




		}
		if(op=='e'){
			break;}

	}

	

	return 0;}