#include<stdio.h>
#include<string.h>

int main(){
	
	int result=0,a=0,b=0;
	int length,i,j=0,k,num=0;
	char str[100],str1[100][100];//�Է¹��� �迭�� �������� ���� 2���� �迭 ����	 
	char str2[100];
	gets(str);
	length=strlen(str);

	for(i=0;i<length;i++){
		
		if(str[i]==' '){
			//���ڰ� ������ ��� �������� ���ڿ��� �̵� 
			num++;
			j=0;
			}
		
		else{
		
			str1[num][j]=str[i];//���ڿ��� �� �࿡ �Է¹޴´� 
	
			j++;}
			
	}
	
	

	
	length=strlen(str1[1]);//�ι�° ���� ���� ��� 

	for(i=0;i<length;i++){
		a=a+str1[1][i]-'0';//���� �ƽ�Ű�ڵ带 '0'���� ���� ������ ��ȯ 

		if(i!=length-1){
			a=a*10;//���������� 10�� ������ �ʴ´�. 
		}
	}
	length=strlen(str1[2]); 
	
	for(i=0;i<length;i++){//a�� ���� ���ڸ� ������ �ٲ۴�. 
		b+=str1[2][i]-'0';
		if(i!=length-1){
			b=b*10;
		}
	}

	if(str1[0][0]=='a'&&str1[0][1]=='d'&&str1[0][2]=='d')//������ add�ΰ�� �������� 
		{result=a+b;
		printf("%d",result);
		}
	else if(str1[0][0]=='m'&&str1[0][1]=='u'&&str1[0][2]=='l'){//������ mul �ΰ�� ������ 
		result=a*b;
		printf("%d",result);
	}
	else if(str1[0][0]=='d'&&str1[0][1]=='i'&&str1[0][2]=='v')//������ div�ΰ�� ������ ���� 
	{result=a/b;
	printf("%d",result);	}
	else if(str1[0][0]=='s'&&str1[0][1]=='u'&&str1[0][2]=='b'){//������ sub�� ��� ���� �� 
		result=a-b;
		printf("%d",result);
	}
	
	
	return 0;
}
