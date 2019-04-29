#include <stdio.h>
#include <stdlib.h>


#define TRUE 1

#define FALSE 0



#define VERTICES 100

#define INF 1000L


int adj_mat[VERTICES][VERTICES];




int selected[VERTICES];

int dist[VERTICES];

int get_min_vertex(int n);

void prim(int s, int n);


void initmat(int size){

	int i,j;

	for(i=0;i<size;i++){


		for(j=0;j<size;j++){

			if(i==j)
				{
					adj_mat[i][j]=0;
			
				}
			else


				adj_mat[i][j]=INF;
			
		}
	}

}
void AddEdge(int start,int end,int weight){

	int i,j,k;
	start-=1;
	end-=1;

	adj_mat[start][end]=weight;
	adj_mat[end][start]=weight;



}


main()

{
	int n,m,i,j;
	int start,end,weight;

	scanf("%d %d",&n,&m);
	initmat(n);

	for(i=0;i<m;i++){


		scanf("%d %d %d",&start,&end,&weight);

		AddEdge(start,end,weight);


	}

	/*for(i=0;i<n;i++){

		for(j=0;j<n;j++){

			printf("%d ",adj_mat[i][j]);
		}
		printf("\n");
	}
	*/


    prim(0,n);


}



void prim(int s, int n)

{

        int i, u, v ,min=0;



        for(u=0;u<n;u++)

                dist[u]=INF;

        dist[s]=0;

        for(i=0;i<n;i++){

                u = get_min_vertex(n);

                selected[u]=TRUE;

                if( dist[u] == INF )

                        return;

                min+=dist[u];

                        printf(" %d",  u+1);

                for( v=0; v<n; v++)

                        if( adj_mat[u][v]!= INF)

                                if( !selected[v] && adj_mat[u][v]< dist[v] )

                                        dist[v] = adj_mat[u][v];

        }
		printf("\n%d",min);

        

}

int get_min_vertex(int n)

{

  int v,i;

  for (i = 0; i <n; i++)

    if (!selected[i]) {

      v = i;

          break;

    }

  for (i = 0; i < n; i++)

    if ( !selected[i] && (dist[i] < dist[v])) v = i;

  return (v);

}
