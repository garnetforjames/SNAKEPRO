#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int split(int n)

{

	if (n < 10) 
	{
		printf("%d\n", n);
	}
	else
	{
		split(n / 10);
		printf("%d\n", n % 10);
	}
}

int main() 

{

	
	int n;
	scanf("%d", &n);
	split(n);


	return 0;
}