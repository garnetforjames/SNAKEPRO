#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){


	int i,j,N;
	char in[100],**p=NULL,*temp;
	scanf("%d",&N);
	getchar();

	p=(char**)calloc(N,sizeof(char *));
	
	for(i=0;i<N;i++){
	gets(in);
	p[i]=(char*)realloc(p[i],strlen(in)+1);
	strcpy(p[i],in);
	}
	for(i=0;i<N-1;i++){
		for(j=0;j<N-1;j++){
			if(strcmp(p[j],p[j+1])>0){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				}
		}
	}

	for(i=0;i<N;i++){
		printf("%s\n",p[i]);
	}


	for(i=0;i<N;i++){
		free(p[i]);
	}
	free(p);
	return 0;
}