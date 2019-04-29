#pragma warning (disable : 4996)


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element;

typedef struct stackNode {
	element data;
	struct stackNode *link;

}stackNode;

stackNode*top;
int flag = 0;
int isEmpty() {

	if (top == NULL)
	{
		printf("Stack is empty!\n");
		return 1;

	}
	else {
		return 0;
	}
}

void push(element item)
{

	stackNode *temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = item;
	temp->link = top;
	top = temp;


}

element pop() {
	element item;
	stackNode*temp = top;

	if (top == NULL) {
		//printf("Stack is Empty!!\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;

	}
}
element peek() {
	if (top == NULL) {
		printf("stack is empty!!\n");
		return 0;
	}
	else {
		return (top->data);
	}
}
void check_error(char value)
{
	char P;
	P = pop();
	if (P == NULL) {
		return;
	}
	//printf("%c\n\n", P);
	switch (P)

	{
	case '(':
		if (value == ')') {
			return;
		}

		else {
			flag = 1;
			return;

		}
	case '{':
		if (value == '}') {
			return;

		}
		else {
			flag = 1;
			return;

		}
	case '[':
		if (value == ']') {
			return;

		}
		else {
			flag = 1;
			return;

		}
	default:break;
	}

	return;
}

void printStack() {
	stackNode*p = top;

	while (p != NULL) {
		printf("%c  ", p->data);
		p = p->link;
	}
	printf("\n");
}
void printStackresult(count) {

	if (count % 2 == 0 && flag == 0)
	{
		printf("OK_%d", count);
	}
	else
	{

		printf("Wrong_%d", count);
	}
}


void main() {

	char str[1000], temp;


	int i = 0, count = 0;
	top = NULL;

	while (1) {

		scanf("%c", &temp);


		if (temp == '\n')

		{
			break;
		}

		else if (temp == '(' || temp == '{' || temp == '[')
		{
			push(temp);
			count++;

		}
		else if (temp == ')' || temp == '}' || temp == ']')
		{
			count++;
			//	printStack();
			check_error(temp);

		}
	}
	//printStack();
	printStackresult(count);
	//getchar();

}