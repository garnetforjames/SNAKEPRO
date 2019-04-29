#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct stack{
	int top;
	char list[10];
}stack;

int IsEmpty(stack*s){
	if(s->top==-1){return -1;}
	return 0;
}
char peek(stack*s){
	if(IsEmpty(s)){
		printf("stack underflow\n");
		exit(1);
	}
	return s->list[s->top];
}
char pop(stack*s){
	char temp;
	if(IsEmpty(s)){
		printf("stack underflow\n");
		exit(1);
	}
	 temp=peek(s);
	s->top--;
	return temp;
}
void push(stack*s, char ch){
	s->top++;
	s->list[s->top]=ch;
}

int priority(char op){
	switch(op){
	case'!': case'$': case'#':
		return 6;
	case'*': case'/':
		return 5;
	case'+':case'-':
		return 4;
	case'>': case'<':
		return 3;
	case'&':
		return 2;
	case '|':
		return 1;
	default:
		return 0;
	}
}

void convertOp(char op){
	switch(op){
	case'#':
		printf("-");
		break;
	case'$':
		printf("||");
		break;
	case'|':
		printf("||");
		break;
	case'&':
		printf("&&");
		break;
	}
}

void infixToPostfix(char exp[]){
	int length=strlen(exp);
	int i;
	char stackOp;
	stack st;
	st.top=-1;
	for(i=0;i<length;i++){
		switch(exp[i]){

		case'!':case'$':case'#':
		case'*':case'/':case'+':
		case'-':case'>':case'<':
		case'&':case'|':
			while(!IsEmpty(&st)&&priority(exp[i])<=priority(peek(&st))){
				stackOp=pop(&st);
				switch(stackOp)
				{
				case'#':case'$':case'|':case'&':
					convertOp(stackOp);
					break;
				default:
					printf("%c",stackOp);
					break;
				}
			}
			push(&st,exp[i]);
			break;
		case'(':
			push(&st,exp[i]);
			break;
		case')':
			stackOp=pop(&st);
			while(stackOp!='('){
				switch(stackOp){
				case'#':case'$':case'|':case'&':
					convertOp(stackOp);
						break;
				default:
					printf("%c",stackOp);
					break;
				}
				stackOp=pop(&st);
			}
			break;
		default:
			printf("%c",exp[i]);
			break;
		}
	}

	while(!IsEmpty(&st)){
		stackOp=pop(&st);
		switch(stackOp)
		{
		case'#':case'$':case'|':case'&':
			convertOp(stackOp);
			break;
		default:
			printf("%c",stackOp);
			break;
		}
	}
	printf("\n");
}

int main(){
	int numOfExp,convertedExp_idx,expLength,i;
	char exp[101],convertedExp[101];
	scanf("%d",&numOfExp);
	while(numOfExp--){
		memset(exp,0,sizeof(exp));
		memset(convertedExp,0,sizeof(convertedExp));
		scanf("%s",exp);
		convertedExp_idx=0;
		expLength=strlen(exp);
		for(i=0;i<expLength;i++){
			switch(exp[i]){
			case'+':
				if(i==0||(i>0&&(exp[i-1]=='-'||
					exp[i-1]=='+'||
					exp[i-1]=='*'||
					exp[i-1]=='/')))
				{
				convertedExp[convertedExp_idx++]='$';
				}
				else{
					convertedExp[convertedExp_idx++]=exp[i];
			}
				break;
			case'-':
				if(i==0||(i>0&&(exp[i-1]=='-'||
					exp[i-1]=='+'||
					exp[i-1]=='*'||
					exp[i-1]=='/')))
				{convertedExp[convertedExp_idx++]='#';
				}
				else{
					convertedExp[convertedExp_idx++]=exp[i];
				}
				break;
			case'&': case'|':
				convertedExp[convertedExp_idx++]=exp[i];
				i++;
				break;
			default:
				convertedExp[convertedExp_idx++]=exp[i];
				break;
			}
		}
		convertedExp[convertedExp_idx]='\0';
		infixToPostfix(convertedExp);
	}
}









