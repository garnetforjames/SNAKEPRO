#include<stdio.h>
#include<stdlib.h>


int plus(int n1,int n2){
	return n1+n2;
}
int minus(int n1,int n2){

	return n1-n2;
}
int multiply(int n1,int n2){
	return n1*n2;
}

int main(void){



	int num1,num2, result1, result2, result3;

	int (*handle[3])(int,int)={plus,minus,multiply};

	scanf("%d %d",&num1,&num2);
	result1=handle[0](num1,num2);
	result2=handle[1](num1,num2);
	result3=handle[2](num1,num2);
	printf("%d %d %d",result1,result2,result3);



	return 0;}