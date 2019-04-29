#include<stdio.h>
#include<stdlib.h>

#include<string.h>


int main(void){

	char x[100],y[100]="",*p[50],*temp;
	int i,j,cnt,len;

	gets(x);
	len=strlen(x);

	cnt=0;
	p[cnt]=x;
	for(i=0;i<len;i++){
		if(x[i]==' '){
			x[i]='\0';
			cnt++;
			p[cnt]=x+i+1;
		}
	}

	for(i=0;i<=cnt;i++){
		for(j=0;j<=cnt;j++){
			if(strcmp(p[i],p[j])<0){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	strcpy(y,p[0]);
	y[strlen(y)]=' ';
	for(i=1;i<=cnt;i++){
		strcat(y,p[i]);
		y[strlen(y)]=' ';
	}
	puts(y);
	return 0;}