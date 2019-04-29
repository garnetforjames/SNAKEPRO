#include<stdio.h>
#include<string.h>

int main(){
	
	int result=0,a=0,b=0;
	int length,i,j=0,k,num=0;
	char str[100],str1[100][100];//입력받을 배열과 단위별로 나눌 2차원 배열 선언	 
	char str2[100];
	gets(str);
	length=strlen(str);

	for(i=0;i<length;i++){
		
		if(str[i]==' '){
			//문자가 공백일 경우 다음행의 문자열로 이동 
			num++;
			j=0;
			}
		
		else{
		
			str1[num][j]=str[i];//문자열을 한 행에 입력받는다 
	
			j++;}
			
	}
	
	

	
	length=strlen(str1[1]);//두번째 행의 길이 계산 

	for(i=0;i<length;i++){
		a=a+str1[1][i]-'0';//각각 아스키코드를 '0'값을 빼어 정수로 반환 

		if(i!=length-1){
			a=a*10;//마지막수는 10을 곱하지 않는다. 
		}
	}
	length=strlen(str1[2]); 
	
	for(i=0;i<length;i++){//a와 같이 문자를 정수로 바꾼다. 
		b+=str1[2][i]-'0';
		if(i!=length-1){
			b=b*10;
		}
	}

	if(str1[0][0]=='a'&&str1[0][1]=='d'&&str1[0][2]=='d')//연산이 add인경우 덧셈실행 
		{result=a+b;
		printf("%d",result);
		}
	else if(str1[0][0]=='m'&&str1[0][1]=='u'&&str1[0][2]=='l'){//연산이 mul 인경우 곱실행 
		result=a*b;
		printf("%d",result);
	}
	else if(str1[0][0]=='d'&&str1[0][1]=='i'&&str1[0][2]=='v')//연산이 div인경우 나눗셈 실행 
	{result=a/b;
	printf("%d",result);	}
	else if(str1[0][0]=='s'&&str1[0][1]=='u'&&str1[0][2]=='b'){//연산이 sub인 경우 뺄셈 실 
		result=a-b;
		printf("%d",result);
	}
	
	
	return 0;
}
