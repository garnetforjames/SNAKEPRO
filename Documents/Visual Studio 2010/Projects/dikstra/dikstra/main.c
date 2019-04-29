#include<stdio.h>
#include<stdlib.h>


int *shortestpathDijkstra(LinkedGraph* pGraph,int startVertexID);
int getMinDistance(int * distance, int *isSelected,int maxNodeCount);
int getEdgeWeight(LinkedGraph* pGraph,int fromVertexID,int toVertexID);








int *shortestpathDijkstra(LinkedGraph* pGraph,int startVertexID){
	int toVertexID
	int *pReturn = NULL;
	int *pSelected=NULL;
	int nodeCount=0,maxNodeCount=0;
	int i=0,j=0,weight=0;
	int vertexID=0,y_w=0,y_v=0;
	ListNode *pListNode=NULL;
	LinkedList *pEdgeList=NULL;
	if(pGraph==NULL){
		printf("Graph is NULL\n");
		return pReturn;
	}

	maxNodeCount=getMaxVertexContLG(pGraph);
	nodeCount=getVertexCountLG(pGraph);
	pReturn=(int*)malloc(sizeof(int)*maxNodeCount);
	pSelected=(int*)malloc(sizeof(int)*maxNodeCount);
	
	if(pReturn ==NULL||pSelected==NULL){
		if(pReturn !=NULL) 
			free(pReturn);
		printf("Not enough memory");
		return NULL;
	}
	for(i=0;i<maxNodeCount;i++){
		if(i==startVertexID){
			pReturn[i]=0;
		}
		else{
			if(pGraph->pVertex[i]==used){
				pSelected[i]=TRUE;
				pReturn[i]=getEdgeWeight(pGraph,startVertexID,i);
			}
			else{
				pSelected[i]=FALSE;
				pReturn[i]=MAX_INT;
			}

		}
	}
	for(i=0;i<nodeCount-1;i++){
		printf(" %d\n",i+1);

		vertexID=getMinDistance(pReturn,pSelected,maxNodeCount);
		pSelected[vertexId]=FALSE;

		pEdgeList=pGraph->ppAdjEdge[vertexId];

		pListNode=pEdgeList->headerNode.pLink;
		while(pList!=NULL){
			toVertexID=pListNode->data.vertexID;
			weight=pListNode->data.weight;

			y_v=pReturn[vertex[ID];
			y_w=pReturn[vertex[ID];
			if(y_v+weight<y_w){
				pReturn[toVertexID]=y_v+weight;
			}
			pListNode=pListNode->List;
		}

		for(j=0;j<maxNodeCoutn;j++){
			printf("\t %d %d-> %d\n",startVertexID,j,pReturn[j]);
		}
	}
	free(pSelected);
	return pReturn;
}

int main(int argc, char *argv[]){
	int i=0;
	LinkedGraph *pG=NULL;
	int *pResult=NULL;
	int **A=NULL;

	pG=createLinkedGraph(6);
	if(pG!=NULL){
		for(i=0;i<6;i++){
			addVertexLG(pG,i);
		}
		addEdgewithWeightLg(pG,0,1,1);

		addEdgewithWeightLG(pG,0,2,4);
		addEdge


	}


}
