#include <stdio.h>
#include<stdlib.h>
#include<memory.h>

int N,M,S; 
 
int g[100][100];
int visited[1000]={0};

void dfs(int here) {
	int next;
    //���� here�� �̹� �湮�� �����̶�� �ٽ� ����
	if (visited[here]){ return;}
 
    printf("%d\n", here);
    visited[here] = 1;  //���� here ������ �湮
 
    for ( next = 1; next <= N; next++) 
        //�׷����� �̾��������鼭, ���� ���� ������ �湮���� �ʾ����� ����
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