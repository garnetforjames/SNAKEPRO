#include<stdio.h>

 
int main(){

	int n;
	int i,j,arr[101][101],val=1;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		arr[i][j]=val;
			val++;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",arr[i][j]);
			}
		printf("\n");
	}

	return 0;}