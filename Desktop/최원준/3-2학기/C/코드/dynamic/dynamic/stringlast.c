#include<stdio.h>
#include<string.h>


int main(){
	char str[101];
	char str1[100][100];
	char *p,*q;
	int n,i,j,k,length,num=0;
	gets(str);
	length=strlen(str);
	p=str;
	q=str;

	for(p=str;p<=str+length;p++){
		if(*p==' '){
			*p='\0';
			strcpy(str1[num],q);
			p++;
			num++;
			q=p;
		}
		else if(*q=='\0'){
			strcpy(str1[num],q);
			num++;
		}
	}





	return 0;}