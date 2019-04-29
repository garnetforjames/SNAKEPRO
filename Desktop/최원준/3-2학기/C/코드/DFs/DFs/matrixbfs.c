#include <stdio.h>

#include <stdlib.h>

#include <memory.h>

 int N,M,S;

 typedef struct{//�׷��� ���� ����

     int vn; //���� ����

     int **matrix;//�׷��� ���� ���
	 int weight;

 }Graph;

 

 Graph *MakeGraph();//�׷��� �����

 void ViewNeighbors(Graph *g);//�̿� ���� �����ֱ�
  void AddEdge(Graph *graph, int start, int goal);//���� �߰�
 
 void print(Graph *g,int vt);
  void DeleteGraph(Graph *graph);//�׷��� �Ҹ�
 
 //void print(Graph *g,int vt);
  void DeleteGRaph(Graph *graph)

 {

     int i = 0;

    

     for (i = 0; i < graph->vn; i++)//�ִ� ���� ������ŭ

     {

         free(graph->matrix[i]);//��Ʈ���� [i-row]  �޸� �Ҹ�

     }

     free(graph->matrix);//��Ʈ���� �޸� ����

     free(graph);//�׷��� �޸� ����

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

     graph = MakeGraph();//�׷��� �����    
	
	 scanf("%d %d %d",&N,&M,&S);

	 for(i=0;i<M;i++){
		 scanf("%d %d",&nodestart,&nodeend);
		 AddEdge(graph,nodestart,nodeend);
		 AddEdge(graph,nodeend,nodestart);
	 }

	 BFS_graph(graph);
	 




     DeleteGRaph(graph);//�׷��� �Ҹ�

     return 0;

 }

 

 Graph *NewGraph(int max_vertex);//�׷��� ���� ����



 Graph *MakeGraph()

 {

     Graph *graph;

     graph = NewGraph(N);//�׷��� ���� ����

     

     return graph;

 }

 Graph *NewGraph(int max_vertex)

 {

     int i = 0;

     Graph *graph = (Graph *)malloc(sizeof(Graph));//�׷��� �޸� ���� �Ҵ�

     graph->vn = max_vertex;//�ִ� ���� ���� ����

     graph->matrix = (int **)malloc(sizeof(int *)*max_vertex);//��Ʈ���� �޸� �Ҵ�

     for (i = 0; i < max_vertex; i++)

     {

         graph->matrix[i] = (int *)malloc(sizeof(int)*max_vertex);//��ũ���� [i-row] �޸� �Ҵ�

         memset(graph->matrix[i], 0, sizeof(int)*max_vertex);//�޸� 0���� �ʱ�ȭ

     }

     return graph;

 }



 void AddEdge(Graph *graph, int start, int goal)

 {	

     graph->matrix[start][goal] = 1;//���� ����

     graph->matrix[goal][start] =	1;//���� ����

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


