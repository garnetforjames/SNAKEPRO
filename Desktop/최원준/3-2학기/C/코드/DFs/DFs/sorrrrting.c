#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
int key;
struct node *next;
}NODE;

NODE *start=NULL;

void insert (int input);
void print();

void main(){
int num,input;
while(1){
puts("MENU");
puts("1. 삽입");
puts("2. 출력");
puts("0. 종료");
printf("숫자를 입력해주세요 : ");
scanf("%d",&num);
switch(num){
case 1:
printf("입력하실 숫자를 써주세요: ");
scanf("%d",&input);
insert(input); break;
case 2:
print(); break;
case 0:
return;
}
}
}
void insert (int input){
NODE *newnode,*cur;
newnode =(NODE *)malloc(sizeof(NODE));
newnode->next=NULL;
newnode->key=input;
cur=start;
if(start==NULL){
start=newnode;
return;
}
else if(start->key>newnode->key){
newnode->next=start;
start=newnode;
return;
}
else
{
while(cur->next!=NULL){
if(cur->next->key>newnode->key){
newnode->next=cur->next;
cur->next=newnode;
return;
}
cur=cur->next;
}
}
cur->next=newnode;
}
void print(){
NODE *cur;
cur=start;
while(cur->next!=NULL){
printf("%d -> ",cur->key);
cur=cur->next;
}
printf("%d \n",cur->key);
}