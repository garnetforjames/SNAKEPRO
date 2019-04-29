#include<stdio.h>


 struct t{

	int hour;
	int min;
	int second;
};

int main(){

	int t1,t2,t3;
	struct t time[3];

	scanf("%d %d %d",&time[0].hour,&time[0].min,&time[0].second);
	
	t1=time[0].hour*3600+time[0].min*60+time[0].second;

	scanf("%d %d %d",&time[1].hour,&time[1].min,&time[1].second);

	t2=time[1].hour*3600+time[1].min*60+time[1].second;

	t3=t2-t1;

	time[2].hour=t3/3600;
	t3=t3%3600;
	time[2].min=(t3/60);
	t3=t3%60;
	time[2].second=t3;
	printf("%d %d %d",time[2].hour,time[2].min,time[2].second);




	return 0;}

