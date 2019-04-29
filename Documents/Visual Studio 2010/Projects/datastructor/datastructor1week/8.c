#include<stdio.h>
#include<stdlib.h>
typedef struct student{


	char name[10];
	double avg;
	int kor,eng,math;
}st;


int main(){
	
	int i,j,k,N;
	st *s;

	scanf("%d",&N);
	s=(st*)malloc(N*sizeof(st));

	for(i=0;i<N;i++){
		scanf("%s %d %d %d",&s[i].name,&s[i].kor,&s[i].eng,&s[i].math);
		s[i].avg=(double)(s[i].eng+s[i].kor+s[i].math)/3;
	}

	for(i=0;i<N;i++){
		printf("%s %.1f ",s[i].name,s[i].avg);
		if(s[i].math>=90||s[i].eng>=90||s[i].kor>=90){
			printf("GREAT ");
		}
		if(s[i].math<70||s[i].kor<70||s[i].eng<70){
			printf("BAD");
		}
		printf("\n");
	}


	free(s);


return 0;

}