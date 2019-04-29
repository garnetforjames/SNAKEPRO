#include<stdio.h>

int sum(int x){
	int result,i;
	result=0;
	for(i=1;i<=x;i++){
		result+=i;
	}
	return result;



}

int main(){
	int x,i,sum1=0;

	scanf("%d",&x);
	for(i=1;i<=x;i++){
		sum1+=sum(i);
	}
	printf("%d",sum1);

	return 0;}