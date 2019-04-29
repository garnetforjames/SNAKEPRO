#include<stdio.h>
#include<string.h>


typedef struct student{

int carnum;
int stid;
char date_in[100];
int hour1,min1;
char date_out[100];
int hour2,min2;
}st;
int check_invalid(int numcar, st s[],int size){

	int i,j,k;
	for(i=0;i<size;i++){
		if(s[i].carnum==numcar){
		for(j=0;j<size;j++){
			if(s[i].stid==s[j].stid&&i!=j)
			{return 1;
			}
		}
	}
	}
	return 0;


}

void numfee(st s[],int size,int numcar){

	int i,j,k;
	int mindiff,t1,t2;

	if(check_invalid(numcar,s,size)==1){
		printf("100000\n");
	}
	else{
	for(i=0;i<size;i++){
		if(numcar==s[i].carnum){
			t1=s[i].hour1*60+s[i].min1;
			t2=s[i].hour2*60+s[i].min2;
			mindiff=t2-t1;
		}

	}
	printf("%d %d %d\n",mindiff,t1,t2);

	if(mindiff<60){
		printf("3000\n");
	}
	else if(((mindiff-60+9)/10*1000)+3000>30000){
		printf("30000\n");
	}
	else
		printf("%d\n",(mindiff-60+9)/10*1000+3000);
	

	}
}

int main(){

	st s[100];

	int i,j,n,k;
	int numcar;
	scanf("%d",&n);

	for(i=0;i<n;i++){

		scanf("%d %d %s %d:%d %s %d:%d",&s[i].carnum,&s[i].stid,&s[i].date_in,&s[i].hour1,&s[i].min1,&s[i].date_out,&s[i].hour2,&s[i].min2);


	}

	scanf("%d",&k);
	for(i=0;i<k;i++){

		scanf("%d",&numcar);
		numfee(s,n,numcar);
	}
	return 0;}
