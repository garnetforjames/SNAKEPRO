#include<stdio.h>
#include<string.h>

typedef struct student{


	char major[101];
	int stdnum;
}st;

void sortbydic(st s[],int size){

	int i,j;
	st temp;
	for(i=0;i<size;i++){

			for(j=0;j<size-1;j++){

				if(strcmp(s[j].major,s[j+1].major)>0){
					temp=s[j];
					s[j]=s[j+1];
					s[j+1]=temp;
				}
			}
	}



}
void sortbynum(st s[], int size){

	int i, j, k;
	st temp;
	for(i=0;i<size;i++){
		for(j=0;j<size-1;j++){

			if(s[j].stdnum>s[j+1].stdnum){
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}

}



int main(){

	st s[100];
	int n,i,j,k;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		getchar();
		gets(s[i].major);
		
		scanf("%d",&s[i].stdnum);
	
		
	}
	 //sortbydic(s,n);
	 sortbynum(s,n);
	 sortbydic(s,n);
	
	
	for(i=0;i<n;i++){
		printf("%s %d\n",s[i].major,s[i].stdnum);
	}

	return 0;}