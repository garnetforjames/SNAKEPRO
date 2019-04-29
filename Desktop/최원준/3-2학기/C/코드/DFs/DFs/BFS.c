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


	void BFS_adjList(graphType*g,int v){
		graphNode*w;
		LQueueType*Q;
		Q=createLinkedQueue();
		g->visited[v]=TRUE;
		printf("%d\n",v);
		enQueue(Q,v);
		while(!isEmpty(Q)){
			v=deQueue(Q);
			for(w=g->adjList_H[v];w;w=w->link){
				if(!g->visited[w->vertex]){
					g->visited[w->vertex]=TRUE;
					printf("%d\n");
					enQueue(Q,w->vertex);
				}
			}
		}
	}


	int main(){



		int N,M,S;

		graphType *g=createGraph;