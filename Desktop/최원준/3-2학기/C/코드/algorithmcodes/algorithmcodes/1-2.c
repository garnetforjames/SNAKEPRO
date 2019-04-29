#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treeNode{
	int id;
	struct treeNode *leftChild;
	struct treeNode *rightChild;
}treeNode;

treeNode* makeNode(int id){
	treeNode* newNode=(treeNode*)malloc(sizeof(treeNode));
	newNode->id=id;
	newNode->leftChild=NULL;
	newNode->rightChild=NULL;
	return newNode;
}

treeNode* makeTree(){
	int nodeId,leftId,rightId;
	treeNode*node;
	scanf("%d %d %d",&nodeId,&leftId,&rightId);
	node=makeNode(nodeId);
	if(leftId!=0){
		node->leftChild=makeTree();
	}
	if(rightId!=0){
		node->rightChild=makeTree();
	}
	return node;
}

void printNode(treeNode* root, char cmd[]){
	int length=strlen(cmd);
	int i;
	printf(" %d",root->id);
	for(i=0;i<length;i++){
		if(cmd[i]=='R'){
			root=root->rightChild;
		}
		else if(cmd[i]=='L'){
			root=root->leftChild;
		}
		printf(" %d",root->id);
	}
	printf("\n");
}

int main(){
	int n,i;
	char searchList[101];
	treeNode*root;
	scanf("%d",&n);
	root=makeTree();
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",searchList);
		printNode(root,searchList);
	}
	return 0;
}