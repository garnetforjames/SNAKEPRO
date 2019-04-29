#include<stdio.h>
#include<string.h>


typedef struct student{

	char name[100];
	char id[100];
	int subnum;
	char subject[10][50];
	double score[100];
	double avg;
	double total;
}st;

int main(){

	int n,i,j,k;
	int num=0;
	char key;
	char deleteinfo[100];
	st s[100];
	st temp;
	while(1){


		scanf("%c",&key);

		switch(key){

		case 'I':
			scanf("%s %s %d",&s[num].name,&s[num].id,&s[num].subnum);
			s[num].total=0;
			for(i=0;i<s[num].subnum;i++){
				scanf("%s %lf",&s[num].subject[i],&s[num].score[i]);
				s[num].total+=s[num].score[i];
				}
			s[num].avg=s[num].total/(double)s[num].subnum;
			num++;
				break;
		
		case 'P':
			for(i=0;i<num;i++){
				if(s[i].name[0]!='0')
				{
				printf("%s %s %d %.2lf\n",s[i].name,s[i].id,s[i].subnum,s[i].avg);

				}
				}
				
				break;
		case 'S':
					for(i=0;i<num;i++){
						for(j=0;j<num-1;j++){

							if(strcmp(s[j].name,s[j+1].name)>0){

								temp=s[j];
								s[j]=s[j+1];
								s[j+1]=temp;
							}
						}
					}
						for(i=0;i<num;i++){
				if(s[i].name[0]!='0')
				{
				printf("%s %s %d %.2lf\n",s[i].name,s[i].id,s[i].subnum,s[i].avg);

				}
				}
					break;
		case 'D':	scanf("%s",&deleteinfo);
					for(i=0;i<num;i++){

						if(strcmp(deleteinfo,s[i].name)==0){
							s[i].name[0]='0';
							}
					}
					break;
		default:break;
		

		}
		if(key=='Q'){
			break;}
	}

	return 0;}