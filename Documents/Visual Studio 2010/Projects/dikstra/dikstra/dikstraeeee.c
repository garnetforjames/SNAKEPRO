#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define INF 9999
struct Edge
{
    
    int source;
	int destination;
	int weight;
};
 

struct Graph
{
    int V, E;
   
 
    struct Edge* edge;
  
};
 
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));

	//printf("V=%d E=%d\n",V,E);
    graph->V = V;   
 
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
   
 
    return graph;
}
 
void FinalSolution(int dist[], int n,int source)
{	int i;
	
    for (i =0; i <= n; i++){
		//if(i==source)
		//	{
		//		continue;
		//	}

		if(dist[i]!=INF)
			{
				printf("%d %d\n", i, dist[i]);
			}
	
	}
}
 
void BellmanFord(struct Graph* graph, int source)
{
    int V = graph->V;
 
    int E = graph->E;
 
    int *StoreDistance;
	int S;
    int i,j;
	S=source;
	StoreDistance=(int*)malloc(V*sizeof(int));
   
    for (i = 0; i <= V; i++)
        StoreDistance[i] = INF;
 
    StoreDistance[source] = 0;
 
   
    for (i = 0; i <=V; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
 
            int v = graph->edge[j].destination;
 
            int weight = graph->edge[j].weight;
 
            if (StoreDistance[u] + weight <= StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }
    }
 
   
    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
 
        int v = graph->edge[i].destination;
 
        int weight = graph->edge[i].weight;
 
	}  
	
    FinalSolution(StoreDistance, V,S);
	
    return;

}
 
int main()
{
    int V,E,S;  
 
    int i;
	struct Graph* graph;
   
    scanf("%d %d %d",&V,&E,&S);
 
    
    graph = createGraph(V, E);   
 
    for(i=0;i<E;i++){
     
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }
	
    BellmanFord(graph, S);
	free(graph);
    return 0;
	
}