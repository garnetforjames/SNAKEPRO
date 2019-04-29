#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

int size,element;

int partition(int ar[],int start,int end){

	int pivot,left=0,right=0,i;
	int temp;
	int mid;
	left=start;
	right=end;

	 pivot = left + rand() % (right - left + 1);
	while(left<right){
		while((ar[left]<ar[pivot])&& (left<right))
			left++;
		while((ar[right]>=ar[pivot])&&(left<right))
			right--;
		if(left<right){
			temp=ar[left];
			ar[left]=ar[right];
			ar[right]=temp;
			if(left==pivot)
				pivot=right;
		}

}

temp=ar[pivot];
ar[pivot]=ar[right];
ar[right]=temp;

	return right;
}
void quickSort(int ar[],int start,int end){
	int n;
	if(start<end){
		n=partition(ar,start,end);
		quickSort(ar,start,n-1);
		quickSort(ar,n+1,end);
	}
}

void printar(int ar[],int start,int end){
	int i;
	for(i=start;i<=end;i++){
		printf(" %d",ar[i]);
	}
}
 void main(){
	 int i,*t,j,k;
	 scanf("%d",&size);
	 t=(int*)malloc(sizeof(int)*size);

	 for(i=0;i<size;i++){
		 scanf("%d",&t[i]);
	 }
	 quickSort(t,0,size-1);
	 printar(t,0,size-1);
	 getchar();
 }
