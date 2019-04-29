#include<stdio.h>

void print_star(int x);

int main(){

	int n;
	scanf("%d",&n);
	print_star(n);
	return 0;}

void print_star(int n){
	int i,j,k;
	for(i=0;i<2*n;i++){
		if(i<n){
			for(j=0;j<=i;j++){
				printf(" ");}
			for(j=i;j<2*n-i-1;j++){
				printf("*");}}
		else{k=i;
			i=i%4;
			for(j=0;j<n-i;j++){
				printf(" ");}
			for(j=n-i;j<=n+i;j++){
				printf("*");
			}
			i=k;
		}
		
		printf("\n");
	}
}