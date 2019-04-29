#include<stdio.h>
#include<string.h>
#include<stdlib.h>
	int m;
typedef struct Bucket{
	int data;
	struct Bucket *link;
}bucket;

void initBucket(Bucket *p){
	int i;

	for(i=0;i<m;i++){
		(p+i)->data=0;
		(p+i)->link=NULL;
	}


}

void findElement(Bucket *p, int data){
	int v;
	Bucket *q,*temp;
	q=p;
	temp=q->link;
	v=data%m;
	if((p+v)->data==data){
		printf("%d\n",v);
		return;
	}
	else{

		if(q->link!=NULL){
			while(temp){
				if(temp->data==data){
					printf("%d\n",v);
					return;
				}
				else
					temp=temp->link;}
		}

	}

		

	printf("0\n");
	return;

}


void print(bucket *p){
	int i;
	bucket *q;
	q=p;
	for(i=0;i<m;i++){
		if((p+i)->data!=0){
			printf(" %d",(p+i)->data);
		}
		else{
			if((p+i)->link!=NULL){
				q=p+i;
				q=q->link;
				while(q){
					printf(" %d",q->data);
					q=q->link;				
				}
			}
		}
	}
}

void insert(bucket*p,int data){
	bucket *q;
	int v;
	q=p;
	v=data%m;
	q=p+v;
	if(q->data!=0){
		q->data=data;}
	else
	{	if(q->link!=NULL)
		{


		}


	}
}
void Search(bucket *p,int data){

}

void Delete(bucket *p, int data){


}

int main(){
	int i,j,k;
	int data;
	bucket *p=NULL;

	char op;


	scanf("%d",&m);

	p=(bucket*)malloc(m*sizeof(bucket));
	initBucket(p);
	

	while(1){
		scanf("%c",&op);
		switch(op){

		case 'i': scanf("%d",&data);
				  insert(p,data);

				  break;

		case 'd':scanf("%d",&data);
				 Delete(p,data);
				 break;
		case 'p':print(p);
				 break;

		case 's':scanf("%d",&data);
				 Search(p,data);
				 break;
		}

		if(op=='e'){
			break;}
	}

	free(p);



	return 0;}
