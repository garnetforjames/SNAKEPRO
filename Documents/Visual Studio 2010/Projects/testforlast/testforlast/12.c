#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct book{
	int id;
	char *title;
};

int main(void){
	char temp[100];
	int i,j,M,N,*p=NULL,**pp=NULL;
	struct book *q=NULL;

	p=(int *)malloc(sizeof(int));

	*p=10;
	printf("%d\n",*p);
	free(p);

	scanf("%d",&N);
	p=(int*)malloc(N*sizeof(int));
	
	for(i=0;i<N;i++){
		scanf("%d",p+i);
	}
	for(i=0;i<N;i++){
		printf("%d ",*(p+i));
	}
	free(p);

	scanf("%d %d",&M,&N);
	pp=(int**)malloc(M*sizeof(int*));
	for(i=0;i<M;i++)
		pp[i]=(int*)malloc(N*sizeof(int));
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&pp[i][j]);
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d ",pp[i][j]);
		}
	printf("\n");
	}
	for(i=0;i<M;i++)
		free(pp[i]);
	free(pp);

	scanf("%d\n",&N);
	q=(struct book*)malloc(N*sizeof(struct book));
	for(i=0;i<N;i++){
		gets(temp);
		q[i].title=(char*)malloc((strlen(temp)+1)*sizeof(char));
		strcpy(q[i].title,temp);
	}
	for(i=0;i<N;i++){
		printf("%s\n",q[i].title);
	}
	for(i=0;i<N;i++)
		free(q[i].title);
	free(q);
	



	return 0;}

