#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct treeNode {

	struct treeNode*left;
	struct treeNode*right;
	int data;

}tree;

tree* makeNode(int data) {

	tree* t = (tree*)malloc(sizeof(tree));

	t->data = data;
	t->left = NULL;
	t->right = NULL;
	return t;
}


tree* maketree() {
	int nodeid, left, right;
	tree*node;
	scanf("%d %d %d", &nodeid, &left, &right);

	node = makeNode(nodeid);
	if (left != 0)
	{
		node->left = maketree();

	}
	if (right != 0)
	{
		node->right = maketree();
	}
	return node;

}
void printNode(tree* root, char op[])
{
	int i;
	int length = strlen(op);
	printf(" %d", root->data);

	for (i = 0; i < length; i++)
	{
		if (op[i] == 'R')
		{
			root = root->right;

		}
		if (op[i] == 'L')
		{
			root = root->left;
		}
		printf(" %d", root->data);
	}
	printf("\n");
}

int main() {
	int n, i;
	char searchList[101];
	tree*root;
	scanf("%d", &n);
	root = maketree();
	scanf("%d", &n);
	for (i = 0; i<n; i++) {
		scanf("%s", searchList);
		printNode(root, searchList);
	}
	return 0;
}


