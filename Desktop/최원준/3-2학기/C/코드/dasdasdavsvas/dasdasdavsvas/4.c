#include<stdio.h>
#include<string.h>


typedef struct student{
	char name[10];
	char book[5][20];
	int score[5];
	int cnt,pcnt;
}st;





int main(){


	st s[100];
	int n,i,j,result;
	scanf("%d",&n);
	j=0;
	for(i=0;i<n;i++){
		scanf("%s",&s[i].name);
		j=0;
		while(1){
			scanf("%s",&s[i].book[j]);
			if(s[i].book[j][0]=='0'){
				s[i].cnt=j;
			
				break;}
			
			scanf("%d",&s[i].score[j]);
			
			j++;
		}
	}

		for(i=0;i<n;i++)
		{
			s[i].pcnt=0;
			for(j=0;j<s[i].cnt;j++)
			{

				if(s[i].score[j]>=50)
				{
					s[i].pcnt++;
				}
			}
		
			result=(s[i].pcnt*100)/5;
			
			printf("%s %d%%\n",s[i].name,result);
			
		}
		

	return 0;}