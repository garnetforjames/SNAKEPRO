#include<stdio.h>
#include<string.h>

int main(){
	
	int result=0;
	int length,i,j=0,k,num=0,count1=0,count2=0,max1=0,max2=0,flag1,flag2;//�������� ī��Ʈ ������ �ƽ����� �ƽ����� ���� ��ġ�ε����� ������ flag���� 
	char str[100],str1[100][100];//�Է¹��� �迭�� �������� ���� 2���� �迭 ���� 
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

	
	for(i=0;i<=num;i++){//���� ��κ��� �ݺ� 
		
		for(j=0;;j++){//���κ��� �ݺ� 
			if(str1[i][j]=='\0'){//������ ���ڰ� ������ ��� ī��Ʈ ���� ���� �ƽ��� ���� 
				if(max1<count1){
					max1=count1;
					flag1=i;//�ƽ����� ���� �ܾ��� ���� �ε����� ��� 
				}
				if(max2<count2){//�ƽ�2 �� ->���� 
					max2=count2;
					flag2=i;//�ƽ����� ���� �ܾ��� ���� �ε����� ��� 
				}
				break;}
			else
				if(str1[i][j]=='a'||str1[i][j]=='e'||str1[i][j]=='i'||str1[i][j]=='o'||str1[i][j]=='u')
				{
					count2++;//�����ΰ�� count2 ���� 
				}
				else{
					count1++;//������ ��� count1 ���� 
				}
		}
		count1=0;
		count2=0;
	}
	if(max1==0){
		printf("0\n"); //max �ʱⰪ�� 0�̹Ƿ� �ƹ��� count�� �߻����� ���� ��� 0����� 
		}
	else{
		printf("%s %d\n",str1[flag1],max1);//�ƴ� ��� 2���� �迭�� ���� �ε����� �Է��Ͽ� ��ü�� ���, �ƽ��� ��� 
	}
	if(max2==0){//max2���� �ʱⰪ�� 0�̹Ƿ� �ƹ��� count�� �߻����� ���� ��� 0�� ��� 
		printf("0\n");
	}
	else{//�ƴҰ�� max2���� ���� �ε��� flag2�� �̿��� max2�� ���� ���� ���� ���ڿ��� ��� 
		printf("%s %d",str1[flag2],max2);
	}
		
	
	return 0;
}
