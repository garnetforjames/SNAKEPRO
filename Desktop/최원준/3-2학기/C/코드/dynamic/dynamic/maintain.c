#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


 typedef struct complex{

	double real;
	double imag;
	double abs;

}complex;

 void abs_val(struct complex *p1,struct complex *p2,struct complex *p3){
	complex temp;

	double p,q,r;

	p=p1->real*p1->real+p1->imag*p1->imag;
	q=p2->real*p2->real+p2->imag*p2->imag;
	r=p3->real*p3->real+p3->imag*p3->imag;

	if(p<q){
		temp=*p1;
		*p1=*p2;
		*p2=temp;
		}
	if(p<r){
		temp=*p1;
		*p1=*p3;
		*p3=temp;
		}

		
}

struct complex add(struct complex c1,struct complex c2){
	complex c3;
	c3.real=c1.real+c2.real;
	c3.imag=c1.imag+c2.imag;

	return c3;

}

 struct complex sub(struct complex c1,struct complex c2){
	complex c3;
	c3.real=c1.real-c2.real;
	c3.imag=c1.imag-c2.imag;

	return c3;
	
}



int main(){
	
	int i;
	
	complex c[10];
	
	

	for(i=0;i<3;i++){
		scanf("%lf %lf",&c[i].real,&c[i].imag);
		
		}

	for(i=0;i<3;i++){
		printf("%f %f\n",c[i].real,c[i].imag);
	}
	*p=c[0];
	*q=c[1];
	*r=c[2];
	abs_val(p,q,r);

	c[2]=add(c[0],c[1]);
	printf("%+.1f  %+.1fi\n",c[2].real,c[2].imag);
	c[2]=sub(c[0],c[1]);
	printf("%+.1f  %+.1fi",c[2].real,c[2].imag);


	return 0;

	}