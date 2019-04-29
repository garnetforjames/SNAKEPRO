#include <stdio.h>
#include <stdlib.h>
#include<time.h>
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
	double start,end,result;
	int	*x, n, i;
	
	scanf("%d", &n);
	x = (int*)malloc(sizeof(int)*n);
	
	for (i = 0; i < n; i++)
		{
			x[i]=(int)rand%n;
		}
	start=clock();
	
			 prefixAverage1(x, n)[i];
		
	end=clock();
	result=(end-start)/CLOCKS_PER_SEC;
	printf("%.12fms\n",result);
	start=clock();
			 prefixAverages2(x, n)[i];
		
	end=clock();
	result=(end-start)/CLOCKS_PER_SEC;
	printf("%.12fms",result);
	return 0;
}