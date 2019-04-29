#include<stdio.h>

void uclid(int n1,int n2){

	if(n2==0){
		printf("%d",n1);
		return;
		}
	else
		return uclid(n2,n1%n2);

}



int main(){


	int n1,n2;


	scanf("%d %d",&n1,&n2);

	uclid(n1,n2);

	return 0;}