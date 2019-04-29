#include<stdio.h>
#include<string.h>



typedef struct student{
	char name[10];
	int grade;
}st;




int main(){

	st s[5];
	int i,j,sum=0;
	double avg=0;

	for(i=0;i<5;i++){
		scanf("%s %d",&s[i].name,&s[i].grade);
		sum+=s[i].grade;
	}
	avg=(double)(sum)/5;

	for(i=0;i<5;i++){
		if(s[i].grade<avg){
			printf("%s\n",s[i].name);
		}
	}

	return 0;}