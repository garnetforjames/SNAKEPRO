#include <stdio.h>
#include <stdlib.h>

int*prefixAverage1(int*x, int n)
{
	int i, j, *A = (int*)malloc(sizeof(int)*n);
	float sum=0;

	for (i = 0; i < n; i++)
	{	sum=0;
			for(j=0;j<=i;j++)
			{
				sum += x[j];
			}
				A[i]=sum/(i+1)+0.5;
	}

return A;
}


int*prefixAverages2(int*x, int n)
{	
	int i, *a = (int*)malloc(sizeof(int)*n);
	float sum = 0;
for (i = 0; i < n; i++)
	{
		sum += x[i];
		a[i]=sum/(i+1)+0.5;
	}
return a;

}
int main(){
	int	*x, n, i;
	scanf("%d", &n);
	x = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	for (i = 0; i < n; i++)
	{

		printf(" %d", prefixAverage1(x, n)[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf(" %d", prefixAverages2(x, n)[i]);
	}
	return 0;
}