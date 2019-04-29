#include<stdio.h>

struct student {
	
	int sex;
	int weight;
	int height;
	
};




int main(){
	int n,i,j;
	int cnt1=0,cnt2=0,cnt3=0;
	struct student stu[10];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d %d %d",&stu[i].sex,&stu[i].weight,&stu[i].height);
		
		
	}
	for(i=0;i<n;i++){
		if(stu[i].sex==1)
		{
		
		
			{if(stu[i].height>=175){
				if(stu[i].weight>=70){
					cnt1++;
				}
				else if(stu[i].weight>=60&&stu[i].weight<70){
					cnt2++;
				}
				else 
					cnt3++;
				
			}else if(stu[i].height>=165&&stu[i].height<175)
				{ 
					if(stu[i].weight>=60&&stu[i].weight<70){
						cnt1++;
					}
					else if(stu[i].weight>=70){
						cnt3++;
					}
					else
						cnt2++;
					}	
		
			else if(stu[i].height<165){
					if(stu[i].weight<60){
					cnt1++;}
					else if(stu[i].weight>=60&&stu[i].height<70){
						cnt3++;
					}
					else
						cnt2++;
					}
					}
				}
				
				else{
				
					if(stu[i].height>=175){
					if(stu[i].weight>=60){
						cnt1++;
						
					}
					else if(stu[i].weight>=50&&stu[i].weight<60){
						cnt2++;
						
					}
					else 
						cnt3++;
					}		
					else if(stu[i].height<175&&stu[i].height>=165){
						if(stu[i].weight>=60){
							cnt3++;
						}
						else if(stu[i].weight<60&stu[i].weight>=50){
							cnt1++;
						}
						else
							cnt2++;
						}
					
					else{
						if(stu[i].weight>=60){
							cnt2++;
						}
						else if(stu[i].weight>50&&stu[i].weight<60)
						{cnt3++;
						}		
						else
						cnt1++;
						
										}
					}
					}	
		
		printf("%d %d %d",cnt1,cnt2,cnt3);
		return 0;
}
