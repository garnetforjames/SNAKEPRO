#include<stdio.h>
#include<string.h>




int main(){

	char str[100],temp;
	int i,j,length;

	scanf("%s",str);
	length=strlen(str);
	
	//printf("%d\n",length);
	
	for(i=0;i<length;i++){
		printf("%s\n",str);
		temp=str[0];
		for(j=0;j<length;j++)
		{	
			str[j]=str[j+1];
			if(j==length-1){
				str[j]=temp;}
		}


	}

	return 0;}