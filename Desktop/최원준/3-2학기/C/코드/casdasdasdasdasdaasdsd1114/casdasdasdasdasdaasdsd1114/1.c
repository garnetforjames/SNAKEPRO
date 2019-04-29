#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input(int *p,int N){
	int i;
	int *q;
	q=p;
	for(q=p;q<p+N;q++){
		scanf("%d",q);
	}

	


}

void output(int *p,int N){
	int  *q;
	q=p;
	for(q=p;q<p+N;q++){
		printf(" %d",*q);
	}

}


int main(){
	int N,M,k;
	int *p,*q,arr1[100],arr2[100],*tem1,*tem2;
	p=arr1;
	q=arr2;
	scanf("%d %d",&M,&N);
	
	input(p,M);
	input(q,N);
	scanf("%d",&k);
	tem1=p+M-1;
	tem2=q+N-1;
	while(1){
	if(p<tem1){	
	output(p,k);
	p=p+k;
	}
	if(q<tem2){
	output(q,k);
	q=q+k;}
	if(p>tem1&&q>tem2){
		break;}
	}
	

	return 0;}