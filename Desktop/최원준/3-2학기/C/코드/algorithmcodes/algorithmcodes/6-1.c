#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int size;

int rfindElement(int arr[],int key,int left,int right){
	int mid;
	mid=(left+right)/2;
	if(left>right){
		if(arr[mid]<=key){
			return mid;}
		else
			return -1;
	}
	if(key==arr[mid]){
		return mid;
	}
	else if(key<arr[mid]){
		return rfindElement(arr,key,left,mid-1);
	}
	else if(key>arr[mid]){
		return rfindElement(arr,key,mid+1,right);
	}

	}



int main(){

	
	 int i,*t,j,key;
	 scanf("%d",&size);
	 t=(int*)malloc(sizeof(int)*size);
	 scanf("%d",&key);
	 for(i=0;i<size;i++){
		 scanf("%d",&t[i]);
	 }

	 printf(" %d",rfindElement(t,key,0,size-1));

	return 0;}