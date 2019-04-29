#include<stdio.h>
#include<string.h>

int main(){
	
	int result=0;
	int length,i,j=0,k,num=0,count1=0,count2=0,max1=0,max2=0,flag1,flag2;//변수선언 카운트 변수와 맥스값과 맥스값을 가진 위치인덱스를 저장할 flag선언 
	char str[100],str1[100][100];//입력받을 배열과 단위별로 나눌 2차원 배열 선언 
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

	
	for(i=0;i<=num;i++){//각각 행부분을 반복 
		
		for(j=0;;j++){//열부분을 반복 
			if(str1[i][j]=='\0'){//마지막 문자가 공백일 경우 카운트 값을 비교해 맥스를 변경 
				if(max1<count1){
					max1=count1;
					flag1=i;//맥스값을 가진 단어의 행의 인덱스를 기억 
				}
				if(max2<count2){//맥스2 비교 ->모음 
					max2=count2;
					flag2=i;//맥스값을 가진 단어의 행의 인덱스를 기억 
				}
				break;}
			else
				if(str1[i][j]=='a'||str1[i][j]=='e'||str1[i][j]=='i'||str1[i][j]=='o'||str1[i][j]=='u')
				{
					count2++;//모음인경우 count2 증가 
				}
				else{
					count1++;//자음인 경우 count1 증가 
				}
		}
		count1=0;
		count2=0;
	}
	if(max1==0){
		printf("0\n"); //max 초기값이 0이므로 아무런 count가 발생하지 않은 경우 0만출력 
		}
	else{
		printf("%s %d\n",str1[flag1],max1);//아닐 경우 2차원 배열의 행의 인덱스만 입력하여 전체를 출력, 맥스값 출력 
	}
	if(max2==0){//max2역시 초기값이 0이므로 아무런 count가 발생하지 않은 경우 0만 출력 
		printf("0\n");
	}
	else{//아닐경우 max2값이 기억된 인덱스 flag2을 이용해 max2의 값을 가진 행의 문자열을 출력 
		printf("%s %d",str1[flag2],max2);
	}
		
	
	return 0;
}
