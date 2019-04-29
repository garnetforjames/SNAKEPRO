#include <stdio.h>

#include <stdlib.h>

#include <memory.h>

 int N,M,S;

 typedef struct{//그래프 형식 정의

     int vn; //정점 개수

     int **matrix;//그래프 인접 행렬
	 int weight;

 }Graph;

 

 Graph *MakeGraph();//그래프 만들기

 void ViewNeighbors(Graph *g);//이웃 정점 보여주기
  void AddEdge(Graph *graph, int start, int goal);//간선 추가
 
 void print(Graph *g,int vt);
  void DeleteGraph(Graph *graph);//그래프 소멸
 
 //void print(Graph *g,int vt);
  void DeleteGRaph(Graph *graph)

 {

     int i = 0;

    

     for (i = 0; i < graph->vn; i++)//최대 정점 개수만큼

     {

         free(graph->matrix[i]);//매트릭스 [i-row]  메모리 소멸

     }

     free(graph->matrix);//매트릭스 메모리 해제

     free(graph);//그래프 메모리 해제

 }
  void BFS_graph(Graph*graph){
	  int i,j,k;

	  for(i=0;i<n;i++){


	  


  }

 

 int main(void)

 {
	 
	 int num,i;    
	 int nodestart,nodeend,data;
	 char key;
     Graph *graph;

     graph = MakeGraph();//그래프 만들기    
	
	 scanf("%d %d %d",&N,&M,&S);

	 for(i=0;i<M;i++){
		 scanf("%d %d",&nodestart,&nodeend);
		 AddEdge(graph,nodestart,nodeend);
		 AddEdge(graph,nodeend,nodestart);
	 }

	 BFS_graph(graph);
	 




     DeleteGRaph(graph);//그래프 소멸

     return 0;

 }

 

 Graph *NewGraph(int max_vertex);//그래프 동적 생성



 Graph *MakeGraph()

 {

     Graph *graph;

     graph = NewGraph(N);//그래프 동적 생성

     

     return graph;

 }

 Graph *NewGraph(int max_vertex)

 {

     int i = 0;

     Graph *graph = (Graph *)malloc(sizeof(Graph));//그래프 메모리 동적 할당

     graph->vn = max_vertex;//최대 정점 개수 설정

     graph->matrix = (int **)malloc(sizeof(int *)*max_vertex);//매트릭스 메모리 할당

     for (i = 0; i < max_vertex; i++)

     {

         graph->matrix[i] = (int *)malloc(sizeof(int)*max_vertex);//매크릭스 [i-row] 메모리 할당

         memset(graph->matrix[i], 0, sizeof(int)*max_vertex);//메모리 0으로 초기화

     }

     return graph;

 }



 void AddEdge(Graph *graph, int start, int goal)

 {	

     graph->matrix[start][goal] = 1;//간선 설정

     graph->matrix[goal][start] =	1;//간선 설정

 }

 void print(Graph *g,int vt);



 void print(Graph *g,int vt)

 {

     int i;
	 if(vt<=6){

     for (i = 0; i < g->vn; i++)

     {

         if(g->matrix[vt][i])

         {

             printf(" %d %d",i,g->matrix[vt][i]);

         }

     }
	 }
	 else
		 printf("-1");
 }


