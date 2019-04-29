#include<stdio.h>
#include<string.h>
int num;
void count(char*s,char c,int cnt)
{
	
	char *temp=s;

	
	if(*temp=='\0')
		{
			printf("%d",cnt);
			return;
		}
	else if (*temp== c )
		{
			
			s++;
			++cnt;
		
			return count(s,c,cnt);
		}
	else
	
	{
			s++;
	
			return count(s,c,cnt);
	}
		
}



int main()
{
	
	char str[101],*p;
	char c;
	//p=str;
	scanf("%s",str);
	p=str;
	getchar();
	c=getchar();
	//printf("%s\n%c",p,c);
	num=0;
	count(p,c,num);



	return 0;
}
