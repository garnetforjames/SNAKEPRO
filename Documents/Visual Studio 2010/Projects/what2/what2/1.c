#include<stdio.h>


int main(){

	double weight;
	int age,i;


	FILE*fp;
	
	fp=fopen("test.txt","r");
	
	for(i=0;i<3;i++){
			fscanf(fp,"%lf%d",&weight,&age);
			printf("%.2f %d\n",weight,age);
		}

	fclose(fp);

	
    return 0;
}



