#include <stdio.h>
#include <stdlib.h>
#include<memory.h>
#define MAX(a,b)((a>b)?a:b)
typedef struct NodeStruct
{
    int data;
    struct NodeStruct* leftChild;
    struct NodeStruct* rightChild;
}Node;

Node* root = NULL;



Node *LL_rotate(Node *parent){
	Node *child=parent->leftChild;
	parent->leftChild=child->rightChild;
	child->rightChild=parent;
	return child;
}

Node *RR_rotate(Node *parent){

	Node* child=parent->rightChild;
	parent->rightChild=child->leftChild;
	child->leftChild=parent;
	return child;
	
}

Node *LR_rotate(Node * parent){

	Node *child=parent->leftChild;
	parent->leftChild=RR_rotate(child);
	return LL_rotate(parent);
}

Node * RL_rotate(Node * parent){

	Node * child= parent->rightChild;
	parent->rightChild=LL_rotate(child);
	return RR_rotate(parent);


}

int getHeight(Node *p){
	int height=0;
	if(p!=NULL)
		height=MAX(getHeight(p->leftChild),getHeight(p->rightChild))+1;
		return height;
}
int getBF(Node*p){
	if(p==NULL) return 0;
	return getHeight(p->leftChild)-getHeight(p->rightChild);
}

Node *rebalance(Node **p){
	int BF=getBF(*p);
	if(BF>1){
		if(getBF((*p)->leftChild)>0)
				*p=LL_rotate(*p);
		else *p=LR_rotate(*p);
	}
	else if(BF<-1){
		if(getBF((*p)->rightChild)<0)
				*p=RR_rotate(*p);
		else *p=RL_rotate(*p);
	}
	return *p;
}
Node* insert_AVL(Node**root,int x){
	if(*root==NULL){
		*root=(Node*)malloc(sizeof(Node));
		(*root)->data=x;
		(*root)->leftChild=NULL;
		(*root)->rightChild=NULL;
	}
	else if(x<(*root)->data){
		(*root)->leftChild=insert_AVL(&((*root)->leftChild),x);
		*root=rebalance(root);
	}
	else if(x>(*root)->data){
		(*root)->rightChild=insert_AVL(&((*root)->rightChild),x);
		*root=rebalance(root);
	}
	else
	{
		printf("X\n");
		exit(1);
	}
	return *root;

	}
Node* BST_insert(Node* root, int data)
{
    if(root == NULL)
    {
        root = (Node*)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->data = data;
		root=rebalance(&root);
        return root;
    }
    else
    {
        if(root->data > data){
            root->leftChild = BST_insert(root->leftChild, data);
			root=rebalance(&root);}
        else{
			root->rightChild = BST_insert(root->rightChild, data);
			root=rebalance(&root);	
			}
    }
    return root;
}


Node* search(Node *root,int x){

	Node *p;
	p=root;
	while(p!=NULL){
		if(x<p->data){
			p=p->leftChild;
		}
		else if(x>p->data){
			p=p->rightChild;

		}
		else 
		{printf("%d\n",p->data);
		return p;
		}
	}
	printf("X\n");
	return p;
}
Node* findMinNode(Node* root)
{
    Node* tmp = root;
    while(tmp->leftChild != NULL)
        tmp = tmp->leftChild;
    return tmp;
}
Node* delete(Node* root, int data)
{
    Node* tNode = NULL;
    if(root == NULL)
        return NULL;

    if(root->data > data)
        {root->leftChild = delete(root->leftChild, data);
		}	
    else if(root->data < data){
        root->rightChild =delete(root->rightChild, data);
			}
    else
    {
        // 자식 노드가 둘 다 있을 경우
        if(root->rightChild != NULL && root->leftChild != NULL)
        {
            tNode = findMinNode(root->rightChild);
            root->data = tNode->data;
            root->rightChild = delete(root->rightChild, tNode->data);
	
		}
        else
        {
            tNode = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
         
			free(root);
			
            return tNode;
        }
    }

    return root;
}
Node* BST_search(Node* root, int data)
{
    if(root == NULL)
        return NULL;

    if(root->data == data)
        return root;
    else if(root->data > data)
        return BST_search(root->leftChild, data);
    else
        return BST_search(root->rightChild, data);
}
void print(Node* root)
{
    if(root == NULL)
        return;

    printf(" %d", root->data);
    print(root->leftChild);
    print(root->rightChild);
}

int main()
{	char op; 
	int data;


	while(1){
		scanf("%c",&op);
		switch(op){
		case 'i':scanf("%d",&data);
			     root=insert_AVL(&root,data);
			     break;
		case 'p': print(root);
				  printf("\n");
				  break;
		case 'd':scanf("%d",&data);
				 search(root,data);
				 delete(root,data);
				root=rebalance(&root);	
				 break;
		case 's':scanf("%d",&data);
				 search(root,data);
				 break;
		}

		if(op=='q'){
			break;}
	}
free(root);
 return 0;
}
