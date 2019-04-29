#include<stdio.h>
#include<stdlib.h>



int fibo(int N){
	if(N==0)
		return 0;
	else if(N==1)
		return 1;
	else 
		return fibo(N-1)+fibo(N-2);
}
int main(void){

	int N;
	scanf("%d",&N);
	printf("%d\n",fibo(N));


	return 0;}