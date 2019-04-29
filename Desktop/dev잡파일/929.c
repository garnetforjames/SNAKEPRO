#include<stdio.h>

int main(){
	int arr[5];
	int *p=arr,max1,max2,temp;
	int *q=arr; 
	for(p=arr;p<arr+5;p++){
		scanf("%d",p);
	
	}
	p=arr;
	max1=*p;
	max2=*(p+1);
	printf("%d %d\n",max1,max2);
	for(p=arr;p<arr+5;p++){
		if(*p>=max1){
			max1=*p;
		}

	for(q=arr;q<p;q++){
		if(q==&max1){
			continue;
		}
		if(*q>=max2){
			max2=*q;
		}
	}	
		
		
	}
	printf("%d\n%d",max1,max2);

			


	return 0;}
