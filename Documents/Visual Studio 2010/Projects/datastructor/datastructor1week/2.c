#include<stdio.h>

void ABC(int i,int *p){
	
	int j,*q=(p+i);
	int *index=q;
	int max=-99999,temp=*q;

	//printf("%d\n",*q);
	for(q=(p+i);q<p+10;q++){
		if(*q>=max)
			{
				max=*q;
				index=q;
			}
	}
	*(p+i)=max;
	*index=temp;

}


int main(){

	int arr[100];
	int i,*p=arr;

	for(i=0;i<10;i++)
	{

		scanf("%d",&arr[i]);
	
	}

	for(i=0;i<10;i++)
	{
		ABC(i,p);
	}
	for(i=0;i<10;i++)
	{
		printf(" %d",arr[i]);
	}

	return 0;
}