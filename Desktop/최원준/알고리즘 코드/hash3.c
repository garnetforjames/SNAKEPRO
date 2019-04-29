#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int m,n,q;
int cnt=0;
int data;
int getNextBucket(int v,int i){

	return (v+i*doublehashing(data))%m;
}
int doublehashing(int _data){

	return q-(_data%q);
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
int hashfunction(int _data){
	int v;

	return v=_data%m;
}


void Insert(int *p, int _data){
	int v,i,b,j;
	i=0;
	v=hashfunction(_data);

	while(i<m){
		b=getNextBucket(v,i);
		if(isempty(p+b)==1){
			*(p+b)=_data;
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



void search(int*p, int _data){


	int i,v,j;
	int b;
	i=0;
	v=hashfunction(_data);

	while(i<m){
		b=getNextBucket(v,i);

		if(isempty(p+b)==1)
			{	printf("-1\n");

			return;}
		else if( _data==*(p+b)){
				printf("%d ",b);
				printf("%d\n", _data);
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



	scanf("%d %d %d",&m,&n,&q);
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
				
	case'p':printarray(p);
			printf("\n");
			break;

	}
	if(op=='e'){
		printarray(p);
		
		break;}
	}



	return 0;}