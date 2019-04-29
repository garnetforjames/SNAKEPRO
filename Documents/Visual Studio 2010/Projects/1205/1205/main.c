#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct info{
char  *name;
char *phone;
char *birth;


};
void Registration(struct info *s,struct info *start,int size){

	struct info *p,*q,*r,temp,data;
	

	char tmpname[100],tmpBirth[100],tmpPhone[100];
	p=s;
	
	if(size>=99){

		printf("OVERFLOW\n"); 
		return;
		}
	
	
	
	printf("Name:");

	scanf("%s",&tmpname);
	p->name=(char*)malloc((strlen(tmpname)+1)*sizeof(char));
	strcpy(p->name,tmpname);
	printf("Phone_number:");
	scanf("%s",&tmpPhone);
	p->phone=(char*)malloc((strlen(tmpPhone)+1)*sizeof(char));
	strcpy(p->phone,tmpPhone);

	printf("Birth:");
	
	scanf("%s",&tmpBirth);
	p->birth=(char*)malloc((strlen(tmpBirth)+1)*sizeof(char));
	strcpy(p->birth,tmpBirth);

	data=*p;
	for(q=start;q<start+size;q++){
		if(strcmp(q->name,p->name)>0){
			
			break;
		}
	}
	for(r=start+size;r>q;r--){
		temp=*r;
		*r=*(r-1);
		*(r-1)=temp;
	}
	*(r)=data;
	
}
	

void RegFromFile(struct info*p, int size){

	FILE *fp;
	char name[100],birth[100],phone[100];
	int i;
	for(i=0;i<size;i++){
	      fp = fopen("data.txt", "r");

	fgets((p+i)->name, sizeof((p+i)->name), fp);
	while(!feof(fp))
		{
          printf("%s\n", (p+i)->name);
          fgets((p+i)->name, sizeof((p+i)->name), fp);
		}
    fclose(fp);

	}
}

void ShowAll(struct info *p,int size){

	struct info *q;
	for(q=p;q<p+size;q++){
		if(q->phone[0]!=NULL){
		printf("%s %s %s\n",q->name,q->phone,q->birth);
		}
	}



}

int Delete(struct info *p,char*d, int size){
	
	struct info *q;
	struct info *r,*temp;
	//printf("%s\n",d);
	for(q=p;q<p+size;q++){
	//	printf("%s\n",q->name);
		if(strcmp(q->name,d)==0){
			
			for(r=q;r<p+size-1;r++){
				*r=*(r+1);
			}
			temp=r;
			free(temp->birth);
			free(temp->name);
			free(temp->phone);
			free(temp);

			return 1;
			}
		}

	//printf("NO MEMBER\n");
	return 0;


}

void FindByBirth(struct info *p,int month,int size){
	struct info *q,*r,temp;
	int sum=0;
	

	for(q=p;q<p+size;q++){
		if(q->phone[0]!=NULL){
				sum+=((q->birth[4]-'0')*10);
				sum+=(q->birth[5]-'0');
		if(sum==month){
				printf("%s %s %s\n",q->name,q->phone,q->birth);
					
		}
		sum=0;
		}
	}
	

}


int main(){
	
	struct info **s=NULL,*p;
	int  key,i,month,num,j;
	char deletename[21],*q;
	i=0;
	
	
	printf("Max_num:");
	scanf("%d",&num);
	s=(struct info**)malloc(num*sizeof(struct info*));

	while(1){



		p=(*s);
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d",&key);
		switch(key){
		
		case 1:
				if(num-1<i){
					printf("OVERFLOW\n");
					break;	
				}
				s[i]=(struct info*)malloc(sizeof(struct info));
				p=s[i];
				Registration(p+i,p,i);
				i++;
				if(i<=100){
					printf("<<%d>>\n",i);}
				break;
			   	

		case 2:	ShowAll(p, i);
				break;
		case 3: if(i==0){
				printf("NO MEMBER\n");
				break;
				}
				else{
				printf("Name:"); 
				scanf("%s",&deletename);
				q=deletename;
				if(Delete(p,q,i)==1){
					i--;}

				break;}

		case 4:	printf("Birth:"); 
				scanf("%d",&month);
				FindByBirth(p,month,i);
				
				break;

		
		
		case 5:RegFromFile(p,i);
			 break;
		}
		if(key==6){
			for(j=0;j<i;j++){
				free(s[j]->birth);
				free(s[j]->name);
				free(s[j]->phone);
			}
			free(s);

			break;}
	}

	return 0;

}