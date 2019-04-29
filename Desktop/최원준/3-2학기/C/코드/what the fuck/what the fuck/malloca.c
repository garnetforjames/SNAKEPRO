#include<stdio.h>
#include<stdlib.h>


typedef int element;
typedef struct treeNode{
	int key;
	struct treeNode * Lchild;
	struct treeNode *Rchild;
}treeNode;
treeNode *root =NULL;

treeNode* search(treeNode* root, int x){
	treeNode *p;
	p=root;

	while(p!=NULL){
		if(x<p->key) {p=p->Lchild;}
		else if(x>p->key){
			p=p->Rchild;}
		
			
		else {
			printf("%d\n",p->key);
			return p;}
	}
	printf("X\n");
	return p;
}

treeNode* insertNode(treeNode *p,int x){
	treeNode *newNode;
	if(p==NULL){
		newNode=(treeNode*)malloc(sizeof(treeNode));
		newNode->key=x;
		newNode->Lchild=NULL;
		newNode->Rchild=NULL;
		return newNode;
	}

	else if(x<p->key)p->Lchild=insertNode(p->Lchild,x);
	else if(x>p->key)p->Rchild=insertNode(p->Rchild,x);
	else printf("X\n");

	return p;
}

void deleteNode(treeNode *root,element key){

	treeNode *parent, *p,*succ,*succ_parent;
	treeNode *child;
	parent=NULL;
	p=root;
	while((p!=NULL)&&(p->key!=key))
	{
		parent=p;
		if(key<p->key)p=p->Lchild;
		else p=p->Rchild;
	}
	if(p==NULL){
		printf("X\n");
		return;
	}
	if((p->Lchild==NULL)&&(p->Rchild==NULL)){
		if(parent!=NULL){
			if(parent->Lchild==p)parent ->Lchild=NULL;
			else parent ->Rchild=NULL;
		}
		else root=NULL;
	}

	else if((p->Lchild==NULL)||(p->Rchild==NULL)){
		if(p->Lchild!=NULL)child=p->Lchild;
		else child=p->Rchild;

		if(parent!=NULL){
			if(parent->Lchild==p) parent ->Lchild=child;
			else parent ->Rchild=child;
		}
		else root=child;
	}

	else{
		succ_parent=p;
		succ=p->Rchild;
		while(succ->Rchild!=NULL){
			succ_parent=succ;
			succ=succ->Rchild;
		}
		if(succ_parent->Lchild==succ)succ_parent->Lchild=succ->Lchild;
		else succ_parent->Rchild=succ->Lchild;
		p->key=succ->key;
		p=succ;}
	free(p);
}


void preorder(treeNode*root){
	if(root){
		printf(" %d",root->key);
		preorder(root->Lchild);
		preorder(root->Rchild);
	}
}

int main(){


	treeNode* nope=NULL;



	char op;
	int data;
	root=insertNode(nope,'\0');

	while(1){

		scanf("%c",&op);
		switch(op){

		case 'i':
					scanf("%d",&data);
					insertNode(root,data);
					break;
		case 's':	scanf("%d",&data);
					search(root,data);
					break;
		case 'p': preorder(root);
					printf("\n");
					break;

		case  'd': scanf("%d",&data);
					deleteNode(root,data);
					break;	

		

		}

		if(op=='q'){
			break;
		}
	}





		


		

	return 0;


}