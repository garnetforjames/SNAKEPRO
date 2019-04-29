#include <stdio.h>

void main()
{
	int n,i,result=0;
	int input[20];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
			scanf("%d",&input[i]);
	}
	
	result=max(n-1,input);
	printf("%d",result);

}
int max(int n, int*input)
{
	int k;
	if(n==0)
		return input[0];
	k=max(n-1,input);
	if(k<input[n])
		return input[n];
	else
		return k;
}