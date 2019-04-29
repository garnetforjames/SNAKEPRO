#include<stdio.h>
#include<malloc.h>
typedef int element;
int size;

void SelectionSort(int a[],int size){
	int i,j,t,max,num=0;
	element temp;
for(i=size-1;i>0;i--){
		max=i;
		for(j=i-1;j>=0;j--){
			if(a[j]>a[max])max=j;}
			temp=a[i];
			a[i]=a[max];
			a[max]=temp;
		//	for(t=0;t<size;t++){
		//		printf(" %d",a[t]);
	//		}
		//	printf("\n");

		}
	for(t=0;t<size;t++){
		printf(" %d",a[t]);}
	
}
void main(){
	int i,n,*t,j,k;
	scanf("%d",&n);
	t=(int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++){
		scanf("%d",&t[i]);
	}
	SelectionSort(t,n);
	getchar();

}