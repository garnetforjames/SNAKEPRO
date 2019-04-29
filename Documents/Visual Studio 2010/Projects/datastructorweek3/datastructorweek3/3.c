#include<stdio.h>

#include<stdlib.h>

int split(int n){

	if(n<=0)
		return 0;

	printf("%d\n",n%10);
	split(n/10);

}

int main(){

	int n;
	scanf("%d",&n);

	split(n);
	return 0;}