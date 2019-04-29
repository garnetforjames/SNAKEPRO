#include<stdio.h>
#include<string.h>



int main(){
	char str[101],op='+';


	char *p,*q;
	int i,j,k,len,flag=0;
	double N,num[10];

	gets(str);
	len=strlen(str);

	j=0;//j 숫자를 저장할 인덱스 j 초기화
	N=0;//숫자 계산할 변수 초기화

	for(i=0;i<=len;i++){
		if(str[i]>='0'&&str[i]<='9')//문자가 숫자이면
			{
			N=N*10+(str[i]-'0');//N에 변수 저장
			flag=1;//플래그 1로
			}
		else{
			if(flag==1){
				if(op=='+')
				{
					num[j]=N;//+일경우 숫자만 저장후 인덱스증가
					j++;
				}

				else if(op=='-')
				{
					num[j]=-N;//-일 경우 숫자만 저장 후 인덱스 증가
					j++;
				}
				else if(op=='*')
				{
					num[j-1]*=N;//곱하기 일 경우 이전 숫자와 곱셈후 다시 저장,인덱스 증가시키지않음
				}
				else if(op=='/')
				{
					num[j-1]/=N;//나누기 일 경우 이전 숫자를 나누고 다시저장, 인덱스 증가 없음
				}
				N=0;//숫자 초기화
				flag=0;//플래그초기화
			}
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){//operation 연산자 입력
				op=str[i];
			}
	}
}
N=0;
for(i=0;i<j;i++){
	N+=num[i];//*,/연산이 끝난 나머지숫자를 모두 더함
}
printf("%lf\n",N);//출력
return 0;
}
