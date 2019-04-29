#include<stdio.h>
#include<string.h>


typedef struct student{
	char name[31];
	char num[10];
	int sub;
	char subject[11][31];
	double grade[11][31];
	double mean;
}st;

int main(){


	st s[100];
	st temp;
	int num=0,i,j;
	int length;
	char key;
	char nme[101];

	while(1){

		scanf("%c",&key);
   
		switch(key){

		case 'I': getchar(); 
		    scanf("%s %s %d",&s[num].name,&s[num].num,&s[num].sub);
					s[num].mean=0;
					for(i=0;i<s[num].sub;i++)
						{
							scanf("%s %lf",&s[num].subject[i],&s[num].grade[i][0]);
							s[num].mean=s[num].mean+s[num].grade[i][0];
						}
					s[num].mean=s[num].mean/s[num].sub;

					num++;
					break;

		case 'S':	
					for(i=0;i<num;i++)
						{
					
							for(j=0;j<num;j++)
							{
								if(strcmp(s[j].name,s[j+1].name)>0)
									{
										temp=s[j];
										s[j]=s[j+1];
										s[j+1]=temp;
									}
							}
						}

					break;

		case 'P': 
				 for(i=0;i<num;i++){
					 if(s[i].name[0]!='\0')
										{
												printf("%s %s %d %.2lf\n",s[i].name,s[i].num,s[i].sub,s[i].mean);
							
										}
					 else 
						 continue;
								}
				  break;
		case 'D':
				getchar();
				scanf("%s",&nme);
			
				for(i=0;i<num;i++){
					if(strcmp(s[i].name,nme)==0)
					{		length=strlen(s[i].name);
					for(j=0;j<length;j++){

							s[i].name[j]='\0';

										}

					}

								}

					break;
		






		}
		if(key=='Q'){
			break;
		}
	}


					

		return 0;}