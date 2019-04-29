#include<stdio.h>
#include<stdlib.h>


int N,M;

void sort(int **p,int num,int row,int col){
	int tmp;
	int i,j;
	col=col-1;
	for(i=col+1;i<=col+num;i++){
		for(j=col+1;j<col+num;j++){
			if(p[row][j]<p[row][j+1]){
				tmp=p[row][j];
				p[row][j]=p[row][j+1];
				p[row][j+1]=tmp;
			}
		}
	}

}
void print_all(int**p,int N,int M){
	int i,j;

	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}

}

int main(void){

	int **p;
	int N,M;
	int i,j,row,col,num;
	


	scanf("%d %d",&N,&M);
	p=(int**)malloc(sizeof(int*)*N);
	for(i=0;i<N;i++){
		p[i]=(int*)malloc(sizeof(int)*M);
	
		for(j=0;j<M;j++){
			scanf("%d",&p[i][j]);
		}
	}

	scanf("%d %d %d",&row,&col,&num);
	
	sort(p,num,row,col);
	print_all(p,N,M);

	return 0;}