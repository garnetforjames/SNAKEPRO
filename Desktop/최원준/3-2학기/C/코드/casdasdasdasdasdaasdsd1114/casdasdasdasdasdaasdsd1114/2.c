#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct complex{
	double real;
	double imag;
	double abs;
}complex;

struct complex add (complex complex1,complex complex2){
	
	complex1.real+=complex2.real;
	complex1.imag+=complex1.imag;
	return complex1;

}

struct complex sub(complex complex1,complex complex2){
	complex1.real-=complex2.real;
	complex1.imag-=complex1.imag;
	return complex1;
}
void abs_val(complex  *p1,complex  *p2,complex  *p3){
	complex *temp;
	double p[3],tmp;
	int i,j;
	p1->abs=p1->real*p1->real+p1->imag*p1->imag;
	p2->abs=p2->real*p2->real+p2->imag*p2->imag;
	p3->abs=p3->real*p3->real+p3->imag*p3->imag;
	
	for(i=0;i<3;i++){
		


}




int main(){
	complex num[3];
	complex *p,*q,*r;
	int i;
	for(i=0;i<3;i++){
		scanf("%lf %lf",&num[i].real,&num[i].imag);
	}
	*p=num[0];
	*q=num[1];
	*r=num[2];

	abs_val(p,q,r);

	add(num[0],num[1]);
	printf("%+.1lf %+.lfi\n",num[0].real,num[0].imag);
	sub(num[0],num[1]);
	printf("%+.1lf %+.lfi",num[0].real,num[0].imag);
	return 0;
}