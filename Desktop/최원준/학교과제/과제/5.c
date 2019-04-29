#include<stdio.h>


int ceiling (double x);

int main(){
	double n;
	scanf("%lf",&n);
	printf("%d",ceiling(n));
	return 0;}

int ceiling(double x){
	if((x-(int)x)==0){return x;}
	else x=x+1;
		return x;
}



