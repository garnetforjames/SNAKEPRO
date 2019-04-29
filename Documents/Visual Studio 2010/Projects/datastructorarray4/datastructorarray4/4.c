#include<stdio.h>
#include<stdlib.h>


#define STACK_SIZE 100

typedef int element;
element stack[STACK_SIZE];

int top=-1;

int isEmpty(){
	
	if(top==-1)
	{
		printf(" Stack is Empty!!\n");
		return 1;
	}
	
	else 
	{
		return 0;
	}
}

int isFull(){
	
	if(top==STACK_SIZE-1)
	{
		printf("Stack is Full\n");
		return 1;
		
	}
	else
	{
		return 0;
		
	}
}

void push(element item){
	if(isFull()){
		
		return;
	}
	else{
		top++;
		stack[top]=item;
	}
	
	return ;
}


element pop(){
	if(isEmpty()){
		return 0;
	}
	else
	{
		stack[top--];
	}
}

element peek(){
	
	if(isEmpty())
	{
		exit(1);
	}
	else{
		return stack[top];
	}
}

void printStack(){
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d ",stack[i]);
		
	}
	printf("\n");
}


void main(){
	
	element item;
	printStack();
	push(1);
	printStack();
	
	push(2);
	printStack();
	
	push(3);
	printStack();
	
	
	
}