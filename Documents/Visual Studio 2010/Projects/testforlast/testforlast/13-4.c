#include<stdio.h>
#include<stdlib.h>

double factorial(int n){
	if (n==0)
		return 1;
	else 
		return n*factorial(n-1);
}

int main(void){
	int i,n;
	double sum=1.0;

	scanf("%d",&n);
	for(i=1;i<=n;i++){
		sum+=1.0/factorial(i);}
	printf("%f\n",sum);
	return 0;
	}
