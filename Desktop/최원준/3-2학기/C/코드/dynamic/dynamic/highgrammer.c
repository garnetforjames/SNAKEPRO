#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct st{
	
	int carnum;
	int id;
	char *indate;
	char *intime;
	char *outdate;
	char *outtime;
	int flag;

}st;

st check_invalidst( st *p,int n){

	int i;
	int j;

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(i==j){
				continue;
			}
			if(p[i].id==p[j].id){
				p[i].flag++;
			}
		}
	}

}
int main(){

	st *p=NULL,temp;
	int n,i,j,k;
	char temin[100],temout[100],temindate[100],temoutdate[100];
	
	scanf("%d",&n);
	p=(struct st*)malloc(n*sizeof(struct st));
	
	for(i=0;i<n;i++){
		p[i].flag=0;
		
		scanf("%d %d",&p[i].carnum,&p[i].id);
		
		scanf("%s",&temindate);
		p[i].indate=(char*)malloc((strlen(temindate)+1)*sizeof(char));
		strcpy(p[i].indate,temindate);
		scanf("%s",&temin);
		p[i].intime=(char*)malloc((strlen(temin)+1)*sizeof(char));
		strcpy(p[i].intime,temin);

		scanf("%s",&temoutdate);
		p[i].outdate=(char*)malloc((strlen(temoutdate)+1)*sizeof(char));
		strcpy(p[i].outdate,temoutdate);
		scanf("%s",&temout);
		p[i].outtime=(char*)malloc((strlen(temout)+1)*sizeof(char));
		strcpy(p[i].outtime,temout);
	

	}
	
	check_invalidst(p,n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(p[i].flag!=0){
				if(p[j].id>p[j+1].id){
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		if(p[i].flag==1){
			printf("%d\n",p[i].id);
		}
	}

	for(i=0;i<n;i++){
		free(p[i].indate);
		free(p[i].intime);
		free(p[i].outdate);
		free(p[i].outtime);
	}
	free(p);
	return 0;}
/*
7
5321 160123 2017-09-03 07:00 2017-09-03 15:12
1234 151237 2017-09-03 08:00 2017-09-03 13:42
8623 158762 2017-09-03 06:00 2017-09-03 23:59
9752 171893 2017-09-03 13:55 2017-09-03 15:22
5715 151237 2017-09-03 15:43 2017-09-03 17:31
7474 160123 2017-09-03 16:41 2017-09-03 19:00
6309 174099 2017-09-03 15:33 2017-09-03 14:12




*/