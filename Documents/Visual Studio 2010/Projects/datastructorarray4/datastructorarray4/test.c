#include<stdio.h>


void fill_vlock(int num[][100],int N, int x,int y, int*cnt)
{
	int i,j;
	while(1)
	{
		if(x<0||y>=N)
			break;
		num[y++][x--]=(*cnt)++;
	}


}
	int main()
	{
		int N,M,cnt=1,i,j;
		int num[100][100];

		scanf("%d %d",&N,&M);
		
		for(i=0;i<M;i++)
		{
		    fill_vlock(num,N,i,0,&cnt);
		    
		}

		for(j=1;j<N;j++)
		{   
		    fill_vlock(num,N,M-1,j,&cnt);
		    
		}

		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				printf(" %d",num[i][j]);
	
			}

			printf("\n");

		}

		return 0;

	}


