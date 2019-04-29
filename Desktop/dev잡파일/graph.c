#include<stdio.h>
#include<stdlib.h>



typedef struct queueNode{

	char vertex;
	struct queueNode* link;
}listNode;

typedef struct{
	int length;
	listNode *front;
	listNode *rear;
}linkedQ;

typedef struct{
	char indegree;
	linkedQ * link;
}DAG;

linkedQ*createQ(){
	linkedQ* q;
	q=(linkedQ*)malloc(sizeof(linkedQ));
	q->length=0;
	q->front =NULL;
	q->rear=NULL;
	return q;
}
void initializeDAG(DAG g[],int n){
	int i;
	for(i=0;i<n;i++){
		g[i].indegree='A';
		g[i].link=createQ();
	}
}

void enqueue(linkedQ*q,char w){
	listNode* newNode=NULL;

	newNode ->vertex=w;
	newNode->link=NULL;

	if(q->length==0)
	{
		q->front=q->rear=newNode;
	}
	else
	{
		q->rear->link=newNode;
		q->rear=newNode;
	}
	q->length++;
}
int dequeue(linkedQ*q){
	listNode *temp;
	int v;
	if(q->length==0){
		printf("emptyQueue\n");
		exit(1);
	}
	else{
		v=q->front->vertex;
		temp=q->front;
		q->front=q->front->link;
		if(q->front==NULL){
			q->rear =NULL;
		}
		q->length--;
		free(temp);
		return v;
	}
}
void insertArc(DAG g[],char v,char w){
	linkedQ*q;
	q=g[v].link;
	enqueue(q,w);
	g[w].indegree++;
}

void topologicalSort(DAG g[],int n){
	int i,v,w;
	listNode *temp;
	linkedQ*zeroPredQ;
	linkedQ*topSort;
	zeroPredQ=createQ();
	topSort=createQ();
	for(i=0;i<n;i++){
		if(g[i].indegree==0){
			enqueue(zeroPredQ,i);
		}
	}
	if(zeroPredQ->length==0){
		printf("network has a cycle");
		exit(1);
	}
	while(zeroPredQ->length>0){
		v=dequeue(zeroPredQ);
		enqueue(topSort,v);
		if(g[v].link->length==0){
			continue;
		}
		else{w=dequeue(g[v].link);}

		while(1){
			g[w].indegree--;
			if(g[w].indegree==0)
			{enqueue(zeroPredQ,w);}
			if(g[v].link->length!=0){
				w=dequeue(g[v].link);
			}
			else{break;}
		}
	}
	while(topSort->length>0){
		v=dequeue(topSort);
		printf(" %c",v);
	}
	
	free(zeroPredQ);
	free(topSort);
	}

int main(){

	char key;
	char start,end;
	int i;
	int n,num;
	DAG *g;
	scanf("%d",&n);

	//DAG *g;
	g=(DAG*)malloc(n*sizeof(DAG));
	initializeDAG(g,n);

	//for(i=0;i<n;i++){
	//	scanf("%c",&key);
	//}

	scanf("%d",&num);

	for(i=0;i<num;i++)
	
	{

		scanf("%c %c",&start,&end);

		insertArc(g,start,end);
		
	
	}


	topologicalSort(g,n);
	return 0;
}
