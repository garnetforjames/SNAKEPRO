#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

#define MAX_VERTEX 100
#define FALSE 0
#define TRUE 1
typedef struct graphNode{
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType{
	int n;
	graphNode* adjList_H[MAX_VERTEX];
	int visited[MAX_VERTEX];
}graphType;

typedef struct QNode{
	int data;
	struct QNode*link;
}QNode;

typedef struct{
	QNode *front,*rear;
}LQueueType;
LQueueType *createLinkedQueue(){
	LQueueType *LQ;
	LQ=(LQueueType*)malloc(sizeof(LQueueType));
	LQ->front=NULL;
	LQ->rear=NULL;
	return LQ;

}
int isEmpty(LQueueType*LQ){
	if(LQ->front==NULL){
		return 1;
	}
	else
		return 0;
}
void enQueue(LQueueType*LQ,int item){
	QNode*newNode=(QNode*)malloc(sizeof(QNode));
	newNode->data=item;
	newNode->link=NULL;
	if(LQ->front==NULL){
		LQ->front=newNode;
		LQ->rear=newNode;
	}
	else{
		LQ->rear->link=newNode;
		LQ->rear=newNode;
	}
}
int deQueue(LQueueType*LQ){
	QNode*old=LQ->front;
	int item;
	if(isEmpty(LQ)){
		return 0;
	}
	else
	{
		item=old->data;
		LQ->front=LQ->front->link;
		if(LQ->front==NULL){
			LQ->rear=NULL;
		}
		free(old);
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
	graphNode* node;
	if(u>g->n||v>g->n){
		printf("no vertex!");
		return ;
	}
	node=(graphNode*)malloc(sizeof(graphNode));
	node->vertex=v;
	node->link=g->adjList_H[u];
	g->adjList_H[u]=node;
}

void print_adjList(graphType*g){
	int i;
	graphNode *p;
	for(i=1;i<g->n;i++){
		p=g->adjList_H[i];
		while(p){
			printf(" %d",p->vertex);
			p=p->link;
		}
	}
}


void BFS_adjList(graphType*g,int v){
		graphNode*w;
		LQueueType*Q;
		Q=createLinkedQueue();
		g->visited[v]=TRUE;
		printf("%d\n",v);
		enQueue(Q,v);
		while(!isEmpty(Q)){
			v=deQueue(Q);
			for(w=g->adjList_H[v];w;w=w->link)
				if(!g->visited[w->vertex]){
					g->visited[w->vertex]=TRUE;
					printf("%d\n");
					enQueue(Q,w->vertex);
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

	
	
	BFS_adjList(G,S);
	getchar();

}
