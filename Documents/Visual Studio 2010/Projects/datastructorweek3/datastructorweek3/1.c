#include<stdio.h>
int result=0;
int sum(int N){
	
	
	if(N==0){
		return result;
	}
	else
		result+=N;

		return sum(N-1);

}

int main(){

	int n;

	scanf("%d",&n);
	printf("%d",sum(n));


	return 0;}