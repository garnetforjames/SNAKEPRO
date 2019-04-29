#include<stdio.h>
#include<string.h>
int main(){
	
	char str[101];
	char str1[101][101];
	int i,j=0,num=0,count1=0,count2=0,flag1,flag2,max1=0,max2=0;
	int length;
	gets(str);
	length=strlen(str);
	
	for(i=0;i<length;i++){
		if(str[i]!='\0'){
			
			
			str1[num][j]=str[i];
			j++;
		}
		else if(str[i]=='\0'){
			num++;
			j=0;	
		}
		
	}
	
	for(i=0;i<num;i++){
		for(j=0;;j++){
			if(str1[i][j]==NULL)
		 		break;
			else
		 		printf("%c",str1[i][j]);
		}
	printf("\n");
	}
		
	for(i=0;i<num;i++){
		for(j=0;;j++){
			if(str1[i][j]!=NULL)
				if(str1[i][j]=='a'||str1[i][j]=='e'||str1[i][j]=='i'||str1[i][j]=='o'||str1[i][j]=='u')
					count1++;
				else
					count2++;
			
			if(max1<count1)
				max1=count1;
				flag1=i;
			if(max2<count2)
				max2=count2;
				flag2=i;
				
		}
		count1=0;
		count2=0;
	}
	
	
	for(i=0;;i++){
		if(str1[flag1][i]==NULL)
			break;
		else
		 printf("%c",str1[flag1][i]);
	}
	printf(" %d\n",max1);
	
	for(i=0;;i++){
		if(str1[flag2][i]==NULL)
			break;
		else
			printf("%c",str1[flag2][i]);
			
	}
	printf(" %d",max2);
	
	//printf("%s %d\n%s %d",str[flag1][0],max1,str1[flag2][0]);
	
	
	
		
	
	
	return 0;
	
}
