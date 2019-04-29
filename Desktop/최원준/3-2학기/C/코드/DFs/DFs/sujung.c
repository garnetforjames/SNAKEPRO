#include <stdio.h>
#include<stdlib.h>
#include<memory.h>

int N,M,S; 
int g[100][100];
int visited[1000]={0};
typedef struct stack{

	int stack[100];
}stack;

void bfs(int here){
	int next;
	int flag=0,temp=100;

	if(visited[here]){return;}
		printf("%d\n",here);
		visited[here]=1;
	for(next=1;next<=N;next++){
		if(here<next&&g[here][next]==1&&!visited[next]){
			printf("%d\n",g[here][next]);
			if(temp>next){
				temp=next;
			}
		}
	}


}
	


/*
void dfs(int here) {
	int next;
    //���� here�� �̹� �湮�� �����̶�� �ٽ� ����
	if (visited[here]){ return;}
 
    printf("%d\n", here);
    visited[here] = 1;  //���� here ������ �湮
 
    for ( next = 1; next <= N; next++) 
        //�׷����� �̾��������鼭, ���� ���� ������ �湮���� �ʾ����� ����
        if (g[here][next] == 1 && !visited[next]) dfs(next);

}*/
int main() {

	int i,j,row,col;

	scanf("%d %d %d",&N,&M,&S);

	for(i=1;i<=N;i++){
	
	for(j=1;j<=N;j++){
		g[i][j]=0;
	}
	}

	for(i=1;i<=M;i++){
		scanf("%d %d",&row,&col);
		g[row][col]=1;
		g[col][row]=1;

	}
	/*for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			printf(" %d",g[i][j]);
		}
		printf("\n");
	}*/

	bfs(S);
	return 0;
}