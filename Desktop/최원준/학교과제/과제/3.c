#include<stdio.h>


int find_maxlocation(int a[],int size);


int main(){

	int n,i,arr[101];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	printf("%d",find_maxlocation(arr,n));
	return 0;}



int find_maxlocation(int a[],int size){
	int i,k,maxid=0,max=a[0];

	for(i=0;i<size;i++){
		if(a[i]>max){
			k=i;
			max=a[k];
			maxid=k;
		}
		else continue;
	}

		return maxid;
		
}