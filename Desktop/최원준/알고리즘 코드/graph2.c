#include <stdio.h>

#include <stdlib.h>

#include <memory.h>

 

 typedef struct{//�׷��� ���� ����

     int vn; //���� ����

     int **matrix;//�׷��� ���� ���
	 int weight;

 }Graph;

 

 Graph *MakeGraph();//�׷��� �����

 void ViewNeighbors(Graph *g);//�̿� ���� �����ֱ�
  void AddEdge(Graph *graph, int start, int goal,int weight);//���� �߰�
 
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

 

 int main(void)

 {
	 
	 int num;    
	 int nodestart,nodeend,data;
	 char key;
     Graph *graph;

     graph = MakeGraph();//�׷��� �����    
	
	 while(1){
		 scanf("%c",&key);
		 switch(key){
		 case 'a': scanf("%d",&num);
					print(graph,num);
					printf("\n");
					break;
		 case 'm': scanf("%d %d %d",&nodestart,&nodeend,&data);
					if((nodestart>6||nodestart<=0)||(nodeend>6||nodeend<=0)){
						printf("-1\n");
						break;}
					else
					{
					AddEdge(graph, nodestart,nodeend,data);
					AddEdge(graph, nodeend, nodestart,data);}
					break;

		 }
		 if(key=='q'){
			 break;}
	 }




     DeleteGRaph(graph);//�׷��� �Ҹ�

     return 0;

 }

 

 Graph *NewGraph(int max_vertex);//�׷��� ���� ����



 Graph *MakeGraph()

 {

     Graph *graph;

     graph = NewGraph(14);//�׷��� ���� ����

     AddEdge(graph, 1, 2, 1);
     AddEdge(graph, 1, 3, 1);
     AddEdge(graph, 1, 4, 1);
     AddEdge(graph, 1, 6, 2);
     AddEdge(graph, 2, 1, 1);
     AddEdge(graph, 2, 3, 1);
	 AddEdge(graph, 3, 1, 1);
     AddEdge(graph, 3, 2, 1);
     AddEdge(graph, 3, 5, 4);
     AddEdge(graph, 4, 1, 1);
	 AddEdge(graph, 5, 3, 4);
	 AddEdge(graph, 5, 5, 4);
	 AddEdge(graph, 5, 6, 3);
	 AddEdge(graph, 6, 5, 3);
	 AddEdge(graph, 6, 1, 2);

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



 void AddEdge(Graph *graph, int start, int goal,int weight)

 {	

     graph->matrix[start][goal] = weight;//���� ����

     graph->matrix[goal][start] = weight;//���� ����

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


