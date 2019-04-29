#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

#define MAX_VERTEX 100
#define FALSE 0
#define TRUE 1

typedef struct graphNode{
	int vertex;
	struct graphNode*link;
}graphNode;

graphNode *start=NULL;
typedef struct graphType{
	int n;
	graphNode*adjList_H[MAX_VERTEX];
	int visited[MAX_VERTEX];
}graphType;

typedef int element;

typedef struct stackNode{
	int data;
	struct stackNode *link;
}stackNode;

stackNode*top;

int isEmpty(){
	if(top==NULL)return 1;
	else return 0;
}

void push(int item){
	stackNode* temp= (stackNode*)malloc(sizeof(stackNode));
	temp->data=item;
	temp->link=top;
	top=temp;
}


int pop(){
	int item;
	stackNode*temp=top;

	
	if(isEmpty()){
		return 0;
	}
	else{
		item=temp->data;
		top=temp->link;
		free(temp);
		return item;
	}
}

void createGraph(graphType*g){
	int v;
	g->n=0;
	for(v=0;v<MAX_VERTEX;v++){
		g->visited[v]=FALSE;
		g->adjList_H[v]=NULL;
	}
}


void insertVertex(graphType*g,int v){
	if(((g->n)+1)>MAX_VERTEX){
		printf("Over flow");
		return ;
	}
	g->n++;
}


void insertEdge(graphType*g,int u,int v){
	graphNode* node,*cur;
	if(u>g->n||v>g->n){
		printf("no vertex!");
		return ;
	}
	node=(graphNode*)malloc(sizeof(graphNode));
	node->vertex=v;
	
	//node->link=NULL;
	
	cur=start;
	if(start==NULL){
		start=node;
		node->link=g->adjList_H[u];
		g->adjList_H[u]=node;
		
			
		return;
	}
	else if(start->vertex>node->vertex){
		node->link=start;
		start=node;
		node->link=g->adjList_H[u];
		g->adjList_H[u]=node;
		return ;
	}
	else{
	while(cur->link!=NULL){
		if(cur->link->vertex>node->vertex){
			node->link=cur->link;
			cur->link=node;
			node->link=g->adjList_H[u];
			g->adjList_H[u]=node;
			//node->link=cur->link;
			return;}
		cur=cur->link;
	}
	}
	cur->link=node;
}
	//node->link=g->adjList_H[u];
	//g->adjList_H[u]=node;


void print_adjList(graphType*g){
	int i;
	graphNode *p;
	for(i=1;i<=g->n;i++){
		p=g->adjList_H[i];
		while(p){
			printf(" %d",p->vertex);
			p=p->link;
		}
		printf("\n");
	}
}

void DFS_adjList(graphType  *g,int v){
	graphNode *w;
	top=NULL;
	push(v);
	g->visited[v]=TRUE;
	printf("%d\n",v);
	while(!isEmpty()){
		v=pop();
		w=g->adjList_H[v];
	while(w){
		if(!g->visited[w->vertex]){
			if(isEmpty()) push(v);
			push(w->vertex);
			g->visited[w->vertex]=TRUE;
			printf("%d\n",w->vertex);
			v=w->vertex;
			w=g->adjList_H[v];
		}
		else{
			w=w->link;}
		}
	}
}
void main(){
	int i;
	int N,M,S;
	int edges,edgee;
	graphType *G;


	scanf("%d %d %d",&N,&M,&S);

	G=(graphType*)malloc(sizeof(graphType));
	createGraph(G);

	for(i=0;i<N;i++){
		insertVertex(G,i);
	}
	for(i=0;i<M;i++){

		scanf("%d %d",&edges,&edgee);
		insertEdge(G,edges,edgee);
		insertEdge(G,edgee,edges);
		
	}

	print_adjList(G);
	printf("\n");
	DFS_adjList(G,S);
	getchar();

}
