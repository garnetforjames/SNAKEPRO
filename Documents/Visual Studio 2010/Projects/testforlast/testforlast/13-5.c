#include<stdio.h>
#include<stdlib.h>


void rearrange1(int *x,int *y,int *z){
	int t;

	t=*x;
	*x=*y;
	*y=*z;
	*z=t;
}
void rearrange2(int *x,int *y,int *z){
	int *t;
	t=x;
	x=y;
	y=z;
	z=t;
}

void rearrange3(int **x){
	int *t;
	t=*x;
	*x=*(x+1);
	*(x+1)=*(x+2);
	*(x+2)=t;

}

int main(void){
	int a=1,b=2,c=3;
	int*p[3]={&a,&b,&c},**pp=p;
	rearrange1(p[0],p[1],p[2]);
	printf("%d %d %d\n",a,b,c);
	printf("%d %d %d\n",*p[0],*p[1],*p[2]);

	rearrange2(p[0],p[1],p[2]);
	printf("%d %d %d\n",a,b,c);
	printf("%d %d %d\n",*p[0],*p[1],*p[2]);

	rearrange3(pp);
	printf("%d %d %d\n",a,b,c);
	printf("%d %d %d\n",*p[0],*p[1],*p[2]);

	return 0;
}