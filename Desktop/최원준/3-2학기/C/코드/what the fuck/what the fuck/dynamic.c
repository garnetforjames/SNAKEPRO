#include<stdio.h>
#include<stdlib.h>



int main(){


	int n,i,cnt1=0,cnt2=0;
	char *str=NULL;
	char a,b;
	scanf("%d",&n);
	getchar();
	str=(char*)malloc((n+1)*sizeof(char));
	if(str==NULL){
		printf("Not enough memory");
		return -1;
	}

	//for(i=0;i<=n;i++){

	//	scanf("%c",&str[i]);
		
	//}
	gets(str);

	scanf("%c %c",&a,&b);

	for(i=0;i<=n;i++){
		
		if(str[i]==a){
			cnt1++;
		}
		else if(str[i]==b){
			cnt2++;
		}
	}
	printf("%d %d",cnt1,cnt2);

	free(str);

	return 0;}