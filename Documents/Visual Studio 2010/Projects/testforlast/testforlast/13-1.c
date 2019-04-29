#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void){

	int a,b,c,d;
	unsigned int r;

	scanf("%d %d %d %d",&a,&b,&c,&d);
	r=(a<<24)+(b<<16)+(c<<8)+d;
	printf("%d %#x\n",r,r);

	scanf("%d %d %d %d",&a,&b,&c,&d);
	r=(a<<24)|(b<<16)|(c<<8)|d;
	printf("%d %#x\n",r,r);

	scanf("%d",&a);
	r=a<<1;
	printf("%d\n",r);

	scanf("%d",&b);
	r>>2;
	printf("%d\n",r);

	scanf("%d %d",&c,&d);
	r=c>>(d-1);
	r=r&1;
	printf("%d\n",r);
	


	return 0;}