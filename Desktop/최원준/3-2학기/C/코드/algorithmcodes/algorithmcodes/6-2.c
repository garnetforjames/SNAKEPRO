#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int size;

void findelement(int arr[],int key){

	int mid;
	int left,right,result;
	left=0;
	right=size-1;
	mid=(left+right)/2;

	while(1){
	
		if(arr[mid]==key){

					result=mid;
					break;
					}

		else if(left>right){
			 if(arr[left]>=key){
				     result=left;
			         break;}
			 else {
					 result= size;
					 break;}
					}
		else if(arr[mid]>key){
					right=mid-1;
						}
		else {
			
			
			left=mid+1;

					}
			mid=(left+right)/2;
	}
	printf(" %d",result);
	
}



int main(){

	 int i,*t,j,key;
	 scanf("%d",&size);
	 t=(int*)malloc(sizeof(int)*size);
	 scanf("%d",&key);
	 for(i=0;i<size;i++){
		 scanf("%d",&t[i]);
	 }
	 findelement(t,key);
	
	return 0;}