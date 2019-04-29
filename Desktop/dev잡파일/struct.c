#include<stdio.h>
#include<string.h>

struct student{
	char name[10];
	int kor;
	int math;
	int eng;
	double mean;
	char grade;
};


int main(){
	double sum=0;
	int i,n;
	double mean=0;
	struct student stu[50];
	struct student *pst;


	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		
		pst=&stu[i];
		scanf("%s %d %d %d",&pst->name,&pst->kor,&pst->math,&pst->eng);
		sum= pst->kor +pst->math +pst->eng;
		mean=(sum/3);
		pst->mean=mean;
		if(pst->mean>=90)
		{
		
			pst->grade='A';
		}
		else if(pst->mean>=80){
			pst->grade='B';
		}
		else if(pst->mean>=70){
				pst->grade='C';
			
		}
		else 
			{
				pst->grade='D';}
				

	}
	
	for(i=0;i<n;i++){
		pst=&stu[i];
		printf("%s %.1f %c\n",pst->name,pst->mean,pst->grade);
		
	}
	
	return 0;
	
}
