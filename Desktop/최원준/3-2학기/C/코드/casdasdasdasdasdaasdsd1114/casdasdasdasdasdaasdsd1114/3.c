#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	int n,i,j,cnt=0,k,max=0,maxid=-1,cnt1=0;
	char *p=NULL;
	char **pch,temp[101];


	scanf("%d",&n);
	p=(char*)malloc((n+1)*sizeof(char));
	pch=(char**)malloc(n*sizeof(char*));
	if(p==NULL){

		printf("Not enough memory");
		return-1;
	}
	scanf("%s",p);
	getchar();
	
	
	for(i=0;i<n;i++){
		gets(temp);

		pch[i]=(char*)malloc((strlen(temp)+1)*sizeof(char));
		strcpy(pch[i],temp);

			for(j=0;j<strlen(pch[i])-2;j++){
					for(k=0;k<strlen(p);k++){
							if(p[k]==pch[i][j+k]){
											cnt1++;
									}
							if(cnt1==strlen(p)){
									cnt++;
									j=j+strlen(p)-1;
					
				}
			}
			cnt1=0;
			}
			
			printf("%d\n",cnt);
		if(cnt>max){
			max=cnt;
			maxid=i;
			}
		cnt=0;
	}

	


	if(max==0){
		printf("NONE");
	}
	else{
	printf("%s",pch[maxid]);
	}
	for(i=0;i<3;i++){
		free(pch[i]);
	}
	free(pch);
	free(p);


	//printf("%s",p);

	return 0;}