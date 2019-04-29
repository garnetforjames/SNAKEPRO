#include<stdio.h>

#include<stdlib.h>

int mostOnes(int **p,int N){
	int i,j,max=0,cnt=0,maxidx=0;

	for(i=0;i<N;i++){
		cnt=0;
		for(j=0;j<N;j++){
			if(p[i][j]==1)
				{
					cnt++;
				}
			
			
			if(p[i][j]==0||j==N-1)
				{
					if(cnt>max)
						{
							max=cnt;
							maxidx=i;
							break;
						}
				}

						}
				


					}

return maxidx;
}

int main(){

	int **arr;
	int N,i,j;


	scanf("%d",&N);
	
	arr=(int**)malloc(N*sizeof(int*));

	for(i=0;i<N;i++){
		arr[i]=(int*)malloc(N*sizeof(int));
		for(j=0;j<N;j++){
			scanf("%d",&arr[i][j]);
		}
	}


	printf("%d",mostOnes(arr,N));


	for(i=0;i<N;i++){
		free(arr[i]);
	}
	free(arr);


	return 0;

}