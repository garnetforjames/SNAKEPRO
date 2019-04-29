#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct queueNode{
	int vertex;
	struct queueNode*link;
}listNode;

typedef struct {
	int length;
	listNode *front;
	listNode *rear;
}linkedQ;

typedef struct{
	int indegree;
	linkedQ*link;
}DAG;

linkedQ*createQ(){
	linkedQ*q;
	q=(linkedQ*)malloc(sizeof(linkedQ));
	q->length=0;
	q->front=NULL;

	q->rear=NULL;
	return q;
}
void initializeDAG(DAG g[],int n){
	int i;
	for(i=0;i<n;i++){
		g[i].indegree=0;
		g[i].link=createQ();
	}
}
void enqueue(linkedQ*q,int w){
	listNode* newNode;
	newNode=(listNode*)malloc(sizeof(listNode));
	newNode->vertex=w;
	newNode->link=NULL;

	if(q->length==0){
		q->front=q->rear=newNode;
	}
	else{
		q->rear->link=newNode;
		q->rear=newNode;
	}
	q->length++;
}
int dequeue(linkedQ*q){
	listNode* temp;
	int v;
	if(q->length==0){
		printf("empty queue\n");
		exit(1);
	}
	else{
		v=q->front->vertex;
		temp= q->front;
		q->front=q->front->link;
		if(q->front==NULL)q->rear=NULL;
		q->length--;
		free(temp);
		return v;
	}
}

void insertArc(DAG g[],int v,int w){
	linkedQ *q;
	q=g[v].link;

	enqueue(q,w);
	g[w].indegree++;
}
void topologicalSort(DAG g[],int n){
	int i,v,w;
	listNode *temp;
	linkedQ *zeroPredQ;
	linkedQ *topSort;
	zeroPredQ=createQ();
	topSort=createQ();

	for(i=0;i<n;i++){
		if(g[i].indegree==0){
			enqueue(zeroPredQ,i);
		}
	}
	if(zeroPredQ->length==0){
		printf("0\n");
		exit(1);
	}
	while(zeroPredQ->length>0){
		v=dequeue(zeroPredQ);
		enqueue(topSort,v);
		if(g[v].link->length==0){ continue;}
		
		else {w=dequeue(g[v].link);}

		while(1){
			g[w].indegree--;
			if(g[w].indegree==0){
				enqueue(zeroPredQ,w);}
			if(g[v].link->length!=0) {w=dequeue(g[v].link);}
			else {break;}
		}
	}
	while(topSort->length>0){
		v=dequeue(topSort);
		printf(" %c",v+97);
	}
	free(zeroPredQ);
	free(topSort);
}

int main(){
	int n,i,n2;
	char key[100];
	char start,end;
	char END;
	DAG *g;
	
	scanf("%d",&n);
	
	g=(DAG*)malloc((n)*sizeof(DAG));
		
	initializeDAG(g,n);
	getchar();
		if(g==NULL){
			printf("not enough memory");
			return -1;
		}

	for(i=0;i<n;i++){
		
		scanf("%c",&key[i]);
		getchar();
		//printf("%c ",key[i]);
		
	}
	//printf("\n");
	scanf("%d",&n2);
	getchar();
	
	for(i=0;i<n2;i++)
		{
		//getchar();
		scanf("%c %c",&start,&end);
		getchar();
		//printf("%c %c\n",start,end);

		insertArc(g,start-'a',end-'a');
		
		}

	
	topologicalSort(g,n);
	free(g);
	return 0;
}


