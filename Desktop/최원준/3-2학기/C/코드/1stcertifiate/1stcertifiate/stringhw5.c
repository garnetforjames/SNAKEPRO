#include<stdio.h>
#include<string.h>

void check_s(char *p,char *q){

	int ch1[26]={0},ch2[26]={0},i,flag=0,flag2=0;

	for(i=0;p[i];i++){
	ch1[p[i]-'a']++;
	}
	for(i=0;q[i];i++){
	ch2[q[i]-'a']++;
	}
	for(i=0;i<26;i++){
		if(ch1[i]-ch2[i]>0){
			flag+=(ch1[i]-ch2[i]);
		}
		else if(ch2[i]-ch1[i]>0){
			flag2+=(ch2[i]-ch1[i]);
		}

	}


	if(flag<=1&&flag2<=1){
	printf("%s\n",p);
	}
}


int main(void){


	char s1[101],s2[50][101],*p;
	int i,j,n,len;
	gets(s1);
	len=strlen(s1);
	p=s1;
	n=0;
	for(i=0;i<=len;i++){
		if(s1[i]==' '|| s1[i]=='\0'){
			s1[i]='\0';
			strcpy(s2[n++],p);
			p=s1+i+1;
			}
	}
	//scanf("%d",&n);
	for(i=0;i<n;i++){
						printf("%s\n",s2[i]);
					}
	return 0;
}

