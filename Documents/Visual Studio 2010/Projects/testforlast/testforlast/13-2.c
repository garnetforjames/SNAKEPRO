#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int hcf(int n1,int n2){
	if(n2!=0)
		return hcf(n2,n1%n2);
	else
		return n1;
}


int main(void){
	int n1, n2;
	scanf("%d %d",&n1,&n2);
	printf("%d",hcf(n1,n2));


	return 0;}