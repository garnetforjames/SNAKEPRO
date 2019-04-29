#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
/*
struct HashNode{
	int key;
	int count;
	struct Node*list;
};
*/
struct HashTable{
	int size;
	struct Node* next;
};
struct HashTable* CreateHashTable(int m);

int GetKey(int data, int m);
void Search(struct HashTable* hTable,int data);
void Insert(struct HashTable* hTable,int data);
void Delete(struct HashTable* hTable,int data);
void DeleteHashTable(struct HashTable* hTable);
void print(struct HashTable* hTable);
struct HashTable* ReHash(struct HashTable* hTable);


int main(void){

	int m;
	int data;
	char op;
	struct HashTable*hTable;

	scanf("%d",&m);

	hTable=CreateHashTable(m);
	while(1){
	scanf("%c",&op);
	switch(op){

	case'i':scanf("%d",&data);
			Insert(hTable,data);
			break;
	case's':scanf("%d",&data);
			Search(hTable,data);
			break;
	case'd':scanf("%d",&data);
			Delete(hTable,data);
			break;
	case'p':print(hTable);
			break;

	}
	if(op=='e'){
		break;}
}

	return 0;}

struct HashTable* CreateHashTable(int m){
	struct HashTable *hTable;
	int i;
	hTable=(struct HashTable*)malloc(sizeof(struct HashTable));
	hTable->size=m;
	hTable->num=0;
	hTable->table=(struct HashNode**)malloc(sizeof(struct HashNode*)*m);

	for(i=0;i<m;i++){
		hTable->table[i]=(struct HashNode*)malloc(sizeof(struct HashNode));

		hTable->table[i]->key=i;
		hTable->table[i]->count=0;
		hTable->table[i]->list=NULL;
	}
	return hTable;
}

int GetKey(int data, int m){
	return data%m;
}

void Search(struct HashTable*hTable,int data){
struct Node* temp=NULL;
temp=hTable->table[GetKey(data,hTable->size)]->list;
if(!temp){
	printf("0\n");
	return ;
}
while(temp){
	if(temp->data==data){
		printf("%d\n",GetKey(data,hTable->size));
		return;
	}
	temp=temp->next;
}
printf("0\n");
return;



}

void Insert(struct HashTable* hTable,int data){

	struct HashNode*first;
	struct Node*temp;
	struct Node*temp2;
	struct Node*node=(struct Node*)malloc(sizeof(struct Node));
	first=hTable->table[GetKey(data,hTable->size)];
	
	temp=first->list;
	if(!node){
		node->data=data;
		node->next=NULL;
	}
	if(!temp){
		first->list=node;
	}

	else{
		temp2=first->list;
		first->list=node;
		node->next=temp2;
	}
	first->count++;



}

void Delete(struct HashTable *hTable,int data){
	struct HashNode* first;
	struct Node*temp;
	struct Node*before;

	first=hTable->table[GetKey(data,hTable->size)];
	temp=first->list;
	before=temp;

	if(!temp){
		return;
	}
	while(temp){
		if(temp->data==data){
			if(before==temp){
				first->list=temp->next;
			}
			else{
				before->next=temp->next;
			}
			free(temp);
			break;
		}
		before=temp;
		temp=temp->next;
	}
	first->count--;
}


void print(struct HashTable *hTable){
	struct HashNode* first;
	struct Node* temp;
	int i;
	
	
	for(i=0;i<hTable->size;i++){
		first=hTable->table[i];
		temp=first->list;
		while(temp){
		printf(" %d",temp->data);

		temp=temp->next;
		}

	}



}
