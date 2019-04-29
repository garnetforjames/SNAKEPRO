#include<stdio.h>
#include<stdlib.h>


void printHeap(int *heap,int size){
	int i;
	for(i=1;i<=size;i++){
		printf(" %d",heap[i]);
	}}




void DownHeap(int *heap,int index,int last){
	int left=2*index;
	int right=left+1;
	int temp,bigger;
	if(left>last)
		return ;
	bigger=left;
	if((right<=last)&&(heap[right]>heap[bigger]))
		bigger=right;
	if(heap[index]<heap[bigger]){
		temp=heap[index];
		heap[index]=heap[bigger];
		heap[bigger]=temp;
		DownHeap(heap,bigger,last);
	}
}
void rbuildheap(int *heap,int N,int index){


		if(index>N)
			return;
		rbuildheap(heap,N,2*index);
		rbuildheap(heap,N,2*index+1);
		DownHeap(heap,index,N);
		
		
}
	

			
void main(){
	
	int i,heap[100];
	int size;
	scanf("%d",&size);
	for(i=1;i<=size;i++){

		scanf("%d",&heap[i]);
		
	}
	rbuildheap(heap,size,1);
	printHeap(heap,size);


	getchar();
}
