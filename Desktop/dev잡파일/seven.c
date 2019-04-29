#include<stdio.h>



struct arr{
	
	int grade;
	int count;
};


int main(){
	int count=0;
	int seven;
	int third;
	struct arr ar[10];
	int i,j;
	for(i=0;i<10;i++){
		
		scanf("%d",&ar[i].grade);
	
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(ar[i].grade>ar[j].grade)
			count++;		
		}	
		ar[i].count=count;
		count=0;
		
	}
	for(i=0;i<10;i++){
		if(ar[i].count==3)
		{third=i;
				}
		else if(ar[i].count==7)
			{seven=i;
				}
}
printf("%d %d",ar[seven].grade,ar[third].grade);
return 0;

}
