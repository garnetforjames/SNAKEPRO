#include<stdio.h>
#include<malloc.h>
int size;

void insertionSort(int a[],int size){
	int i,j,t,temp;
	for(i=1;i<size;i++){
		temp=a[i];
		j=i;
		while((j>0)&&(a[j-1]>temp)){
			a[j]=a[j-1];
			j=j-1;
		}
		a[j]=temp;
	//	for(t=0;t<size;t++){
//			printf(" %d",a[t]);}
//		printf("\n");
	}
	for(t=0;t<size;t++){
		printf(" %d",a[t]);
	}

	}
void main(){
	int i,n,*t,j,k;
	scanf("%d",&n);
	t=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&t[i]);
	}
	insertionSort(t,n);

	getchar();

}