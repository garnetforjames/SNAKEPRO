#include<stdio.h>
#include<string.h>

typedef struct info{

	int carnum;
	int stdnum;
	char str[100];
	char d1[100],d2[100];
	char t1[100],t2[100];

}st;

void sort(struct info p[], int size){

int i,j;
struct info temp;

	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(p[i].stdnum>p[j].stdnum){
		temp=p[i];
		p[i]=p[j];
		p[j]=temp;
		}
		}
	}



}



int check_invalid(struct info p[],int size,int num){

int i,j,flag,stdid,stdindex;
for(i=0;i<size;i++){
	if(p[i].carnum=num){
		stdid=p[i].stdnum;
		stdindex=i;
	}
}
for(i=0;i<size;i++){
						
	if(i==stdindex){
		continue;
	}
	else if(stdid==p[i].stdnum){
		return 1;
	}
}
return 0;
	
					

}
void numfee(int num,int size,struct info s[]){

	int i,j;
	int time1=0,time2=0,flag=0,result1=0,result2=0;
	int a,b;
	if(check_invalid(s,size,num)==1)
	{
		printf("100000\n");
	}
	else
	{
		for(i=0;i<size;i++)
			{
				if(s[i].carnum==num)
					{
						result1=((s[i].t1[0]-'0')*10+(s[i].t1[1]-'0'))*60+((s[i].t1[3]-'0')*10+(s[i].t1[4]-'0'));
						result2=((s[i].t2[0]-'0')*10+(s[i].t2[1]-'0'))*60+((s[i].t2[3]-'0')*10+(s[i].t2[4]-'0'));

					}
			}
		
		printf("%d %d\n",result1,result2);
		
	if(result2-result1<=60){
		printf("3000\n");
	}
	else if((result2-result1)/10*1000>30000){
		printf("30000\n");
	}
	else
		printf("%d\n",(result2-result1)/10*1000);
	}
}

int main(){
	
	st s[10];
	
	int i,j,k;
	int n;
	int n1,num;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{

		scanf("%d %d %s %s %s %s",&s[i].carnum,&s[i].stdnum,&s[i].d1,&s[i].t1,&s[i].d2,&s[i].t2);
					
		
	}


	//sort(s,n);
	//print_invalid(s,n);
	scanf("%d",&n1);
	for(i=0;i<n1;i++){

		scanf("%d",&num);
		numfee(num,n,s);
	}



	return 0;
		
}