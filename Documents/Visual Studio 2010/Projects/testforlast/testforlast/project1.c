#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct student{

	char name[100];
	char phone[21];
	char birth[21];

}info;

void registration(info *p,int *count){

	int i;
	char temp[100];
		printf("%d\n",count);
	if((*count)>=100)

	{
		printf("OVERFLOW\n");
		return;
	}

	printf("Name:");
	scanf("%s",(p+(*count))->name);
	printf("phone:");
	scanf("%s",(p+(*count))->phone);
	printf("birth:");
	scanf("%s",(p+(*count))->birth);

	*count++;
	printf("<<%d>>\n",*count);

	return;

}
void print_all(info *p,int *count){
	info *q;

	for(q=p;q<p+*count;q++)
	{
		
		printf("%s %s %s\n",q->name,q->phone,q->birth);
	
	}


}
void delete_info(info *p,int *count)
{
	info *q,*r;
	int i;
	int sum;
	char d_name[100];

	printf("Delete_Name:");
	scanf("%s",d_name);
	for(q=p;q<p+*count;q++){
		if(strcmp(q->name,d_name)==0){
			for(r=q;r<p+(*count);r++){
				*r=*(r+1);

			}
			*count++;
			return;
		}
	}

	return;
}
void findbyBirth(info *p,int *count)
{	info *q;
	int i;
	int sum=0;
	int month;

	printf("Birth:");
	scanf("%d",&month);

	for(q=p;q<p+*count;q++){
		sum=0;
		sum=(q->birth[4]-'0'*10)+(q->birth[5]-'0');
		if(sum==month){
			printf("%s %s %s\n",q->name,q->phone,q->birth);
		}
	}}

int main(){
	int input;
	int i,j,k,*count=0;
	info s[100],*p=&s[0];

	while(1){
		printf("<1.resistraion><2.showall><3.delete><4.findbyBirth><5.exit>\n");
		printf("NUMBER:");
		scanf("%d",&input);

		switch(input){

		case 1:	registration (p,count);
				break;
		case 2: print_all(p,count);
				break;
		case 3: delete_info(p,count);
				break;
		case 4:findbyBirth(p,count);
				break;
		case 5 :return 0;
				break;
		}
	}
	
	
	return 0;}