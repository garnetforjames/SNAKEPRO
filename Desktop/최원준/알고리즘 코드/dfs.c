#include <stdio.h>
#include<stdlib.h>
#include<memory.h>

int N,M,S; 
 
int g[100][100];
int visited[1000]={0};

void dfs(int here) {
	int next;
    //지금 here이 이미 방문된 정점이라면 다시 빠꾸
	if (visited[here]){ return;}
 
    printf("%d\n", here);
    visited[here] = 1;  //지금 here 정점은 방문
 
    for ( next = 1; next <= N; next++) 
        //그래프가 이어져있으면서, 아직 다음 정점이 방문되지 않았으면 ㄱㄱ
        if (g[here][next] == 1 && !visited[next]) dfs(next);

}
int main() {

	int i,j,row,col;

	scanf("%d %d %d",&N,&M,&S);

	for(i=0;i<N;i++){
	
	for(j=0;j<N;j++){
		g[i][j]=0;
	}
	}

	for(i=1;i<=M;i++){
		scanf("%d %d",&row,&col);
		g[row][col]=1;
		g[col][row]=1;
	}

	dfs(S);
	return 0;
}