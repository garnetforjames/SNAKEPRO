#include<stdio.h>
#include<stdlib.h>



int main(){

	int i,j,k;
	int *x,*y,*z,N;

	scanf("%d",&N);

	x=(int*)malloc(N*sizeof(int));
	y=(int*)malloc(N*sizeof(int));
	z=(int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++){
		scanf("%d",&x[i]);
	}
	for(i=0;i<N;i++){
		scanf("%d",&y[i]);
	}
	for(i=0,j=N-1;i<N&&j>=0;i++,j--)
	{
		z[i]=x[i]+y[j];
	}
	for(i=0;i<N;i++){
		printf(" %d",z[i]);}

	free(x);
	free(y);
	free(z);


	return 0;}