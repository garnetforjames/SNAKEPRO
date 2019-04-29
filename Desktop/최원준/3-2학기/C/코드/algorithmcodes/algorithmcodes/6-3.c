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
	char YN[100];
	 int i,*t,j,key;
	 int a,b,cnt;
	 int mid;
	 scanf("%d %d",&a,&b);
	 t=(int*)malloc(sizeof(int)*b-a);
	 scanf("%d",&cnt);
	 for(i=a;i<=b;i++){
		 t[i]=i;
	 }
	
	 scanf("%s",YN);
	 //printf("%s",YN);
	 for(i=0;i<cnt;i++){
		 if(YN[i]=='Y'){

			 mid=(a+b)/2+1;
			 a=mid;
		 }
		 else if(YN[i]=='N'){
			 mid=(a+b)/2;
			 b=mid;
		 }
	 }

	 printf("%d",mid);



	return 0;}