#include<stdio.h>
#include<string.h>



int main(){
	char str[101],op='+';


	char *p,*q;
	int i,j,k,len,flag=0;
	double N,num[10];

	gets(str);
	len=strlen(str);

	j=0;//j ���ڸ� ������ �ε��� j �ʱ�ȭ
	N=0;//���� ����� ���� �ʱ�ȭ

	for(i=0;i<=len;i++){
		if(str[i]>='0'&&str[i]<='9')//���ڰ� �����̸�
			{
			N=N*10+(str[i]-'0');//N�� ���� ����
			flag=1;//�÷��� 1��
			}
		else{
			if(flag==1){
				if(op=='+')
				{
					num[j]=N;//+�ϰ�� ���ڸ� ������ �ε�������
					j++;
				}

				else if(op=='-')
				{
					num[j]=-N;//-�� ��� ���ڸ� ���� �� �ε��� ����
					j++;
				}
				else if(op=='*')
				{
					num[j-1]*=N;//���ϱ� �� ��� ���� ���ڿ� ������ �ٽ� ����,�ε��� ������Ű������
				}
				else if(op=='/')
				{
					num[j-1]/=N;//������ �� ��� ���� ���ڸ� ������ �ٽ�����, �ε��� ���� ����
				}
				N=0;//���� �ʱ�ȭ
				flag=0;//�÷����ʱ�ȭ
			}
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){//operation ������ �Է�
				op=str[i];
			}
	}
}
N=0;
for(i=0;i<j;i++){
	N+=num[i];//*,/������ ���� ���������ڸ� ��� ����
}
printf("%lf\n",N);//���
return 0;
}
