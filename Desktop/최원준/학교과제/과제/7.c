#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main(){
	int i,j,arr[10];
		srand((unsigned)time(NULL));
	for(i=0;i<6;i++){
		arr[i]=(rand()%45)+1;
	}
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			if(i==j){continue;}
			if(arr[i]==arr[j]){
				arr[i]=(rand()%45)+1;
			}
		}
	}
	for(i=0;i<6;i++){
		printf("%d ",arr[i]);
	}

	return 0;
}

