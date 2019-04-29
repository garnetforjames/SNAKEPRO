#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *stack;
int flag = 0;
int top = -1;
int N=1001;

int isFull() {
	if(top==N)
	{
		return 1;
	}
	else
	{
		return 0;

	}
}
int isEmpty() {
	if(top==-1)
	{
		return 1;

	}
	else 
	{
		return 0;
	}
}
void PUSH(char data)
{
	if (isFull())
	{
		printf("Stack is Full\n");
		return;
	}
	else {
		top++;
		stack[top] = data;
	}
}
char POP() 
{
	char temp;
	if(isEmpty())
	{
		//printf("Stack is empTy!!\n");
		return NULL;
	}
	else 
	{
		temp = stack[top];
		stack[top] = NULL;
		return temp;
		

	}
}
void peek() {
	if (isEmpty())
	{
		//printf("stackis empty!!\n");
		return;
	}
	else {
		printf("%d\n\n", stack[top]);

	}
}

void check_stack(char data) {
	
		char c;
	
		c = POP();
		if (c != NULL)
		{
			switch (c)
			{
			case'(': if (data == ')') {
				return;
				break;
			}
					 else {
						 flag = 1;
						 break;
					 }
			case'{': if (data == '}')
			{
				return;
			}
					 else {
						 flag = 1;
						 break;
					 }
			case'[':if (data == ']')
			{
				return;

			}
					else
					{
						flag = 1;
						break;
					}
			default: flag = 1;
				break;
			}
		}
		else
		{
			flag == 1;
			return;
		}
}

	

void print() {
	int i;
	for (i = 0; i <= top; i++) {
		printf("%c", stack[i]);

	}
	printf("\n");
}


int main() 
{
	

	int i, opn, count = 0;;
	char c;
	
	stack = (char*)malloc(1001* sizeof(char));

	while (1)
	{
		scanf("%c", &c);
		if (c == '\n') 
		{
			break;
		}

		if (c == '(' || c == '{' || c == '[')
		{
			PUSH(c);
			count++;
		}
		else if (c == ')' || c == '}' || c == ']')
		{
			check_stack(c);
			count++;
		}
	

	}

	if (flag == 0 && count % 2 == 0)
	{
		printf("OK_%d", count);
	}
	else
		printf("Wrong_%d", count);


	return 0;


}