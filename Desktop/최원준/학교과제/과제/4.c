#include<stdio.h>

int is_pallindrome(int x);

void main(){
	int n,i,k,sum=0;
	scanf("%d",&n);
	k=n;
	is_pallindrome(n);
	while(1){
		sum+=n%10;
		n=n/10;
		if(n==0){break;}
			}
	if(is_pallindrome(k)==1){
		printf("%d\nYes",sum);
		}
	else if(is_pallindrome(k)==0){
		printf("%d\nNo",sum);}
	}
int is_pallindrome(int n){
	int i,j,num=0,cnt=0,flag=0;
	int arr[100];
	while(1){
		arr[num]=n%10;
		n=n/10;
		if(n==0){break;}
		num++;
			}
	if(num%2==0){cnt=(num+2)/2;}
			
	else {cnt=(num+1)/2;}
	
	for(i=0,j=num;i<=j;i++,j--){
	if(arr[i]==arr[j]){
	flag++;}
	 }
	if(flag==cnt){
		return 1;}
	else return 0;
	}