#include<stdio.h>

int swap(int *p,int *q){
	
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;

	
}


int main(){

	int arr[50];
	int N,i,*p=arr,*q=arr;
	int n1,n2;
	scanf("%d",&N);

	for(i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d %d",&n1,&n2);
	p=arr+n1;
	q=arr+n2;
	swap(p,q);
	
	for(i=0;i<N;i++){

		printf(" %d",arr[i]);
	}

	return 0;}