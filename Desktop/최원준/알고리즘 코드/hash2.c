#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int m,n;
int cnt=0;
int getNextBucket(int v,int i){

	return (v+i)%m;
}
int isempty(int *p){
	if(*p==0){
		return 1;
	}
	else
		return 0;
}

void initarray(int *p){
	int i;
	int *q;
	q=p;
	for(i=0;i<m;i++){
		*(q+i)=0;
		}


}
void printarray(int *p){
	int i;

	for(i=0;i<m;i++){
		printf(" %d",*(p+i));
	}
}
int hashfunction(int data){
	int v;

	return v=data%m;
}


void Insert(int *p, int data){
	int v,i,b,j;
	i=0;
	v=hashfunction(data);

	while(i<m){
		b=getNextBucket(v,i);
		if(isempty(p+b)==1){
			*(p+b)=data;
			for(j=0;j<cnt;j++){
				printf("C");
				}
				printf("%d\n",b);
				cnt=0;
				return;
			}
		else 
			{	i=i+1;
				cnt++;
			}
	
	}
		
}



void search(int*p, int data){


	int i,v,j;
	int b;
	i=0;
	v=hashfunction(data);

	while(i<m){
		b=getNextBucket(v,i);

		if(isempty(p+b)==1)
			{	printf("-1\n");

			return;}
		else if(data==*(p+b)){
				printf("%d ",b);
				printf("%d\n",data);
				return;
			}
			i=i+1;
			
	}
	printf("-1\n");
	return;


				}


int main(){


	char op;
	int *p=NULL;

	int data;

	scanf("%d %d",&m,&n);
	p=(int*)malloc(m*sizeof(int));
	initarray(p);
	//printarray(p);
	while(1){
	scanf("%c",&op);

	switch(op){

	case 'i': scanf("%d",&data);
			  Insert(p,data);
			  break;

			


	case 's':scanf("%d",&data);
			 search(p,data);
			 break;
				

	}
	if(op=='e'){
		break;}
	}



	return 0;}