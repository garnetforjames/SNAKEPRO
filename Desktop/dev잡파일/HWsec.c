#include<stdio.h>
#include<string.h>

int main(){
	
	char str[101]={1};
	char str1[50][50];
	char *p;
	p=str;
	int i,j,k,length;
	int num=0;
	
	
	gets(str);
	
	length=strlen(str);
	for(p=str;p<str+length;p++){
	printf("%c",*p);
}

	//printf("%d",length);
	for(p=str;p<str+length;p++){
		
						
		if(	*p==' '){
			num++;
			j=0;
			continue;
				}
				
		else{
		
			str1[num][j]=*p;
			j++;
				}
	
							}
//t	printf("%c\n",str1[0][0]);
	for(i=0;i<num;i++){
	
			for(j=0;;j++){
			
				printf("%s",str1[i][j]);
		}
				printf("\n");
			
					}	
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	




