#include<stdio.h>
#include<stdlib.h>>
#include<string.h>



int main(void){
	
	
	
	char ch,x[100],y[100];
	int M;
	float F;
	
	scanf("%s",x);
	
	scanf("%c",&ch);
	
	scanf("%s",y);
	
	printf("x=%s  y=%s  ch=%c\n",x,y,ch);
	
	scanf("%s",x);
	ch=getchar();
	gets(y);
	printf("x=%s y=%s ch=%c\n",x,y,ch);
	
	scanf("%s",x);
	scanf("%d",&M);
	gets(y);
	printf("x=%s y=%s M=%d ch=%c\n",x,y,M,ch);
	
	scanf("%s",x);
	scanf("%f",&F);
	gets(y);
	printf("x=%s  y=%s  M=%.1f\n",x,y,F);
		
	
	
	
	
	
	return 0;
}
