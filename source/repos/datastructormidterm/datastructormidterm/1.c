#include<stdio.h>



int main() 
{
	int arr[100][100], i, j, k;
	int N, M,num=1,flag=0;

	j = 1;
	k = 1;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N*M; i++) {
		
		if (k == 1&&flag==0)
		{
			arr[j - 1][k - 1] = num;
			num++;

			if (j == N) 
			{
				flag = 1;
				



			}
			j = k + 1;
			k = 0;
		}

		if (k != 1) 
		{
			arr[j - 1][k - 1] = num;
			num++;
			k--;
			j++;
		
		
		}


	}


	for (i = 0; i < N; i++) 
	{
		for (j = 0; j < M; j++)
		{
			printf(" %d", arr[i][j]);
		}
	
		printf("\n");
	
	}


	return 0;
}