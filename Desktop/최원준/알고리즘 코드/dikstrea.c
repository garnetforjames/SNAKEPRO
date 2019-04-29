#include <stdio.h>
#include <stdlib.h>

#define	INFINITE 9999	// �Ÿ��� �ʱⰪ
#define	NUM_VERTICES 101	// ������ ����

// ��������Ʈ ����ü
typedef struct Adjacency
{
	struct Adjacency *link;		// ����
	int vertex;					// ����
	int weight;					// ����
}Adjacency;

// ���� ����Ʈ
Adjacency *Graph_list[NUM_VERTICES];

void insertEdge(int, int, int);
void DijkstraShortestPathsSingleTargetCount(int, int);

void main()
{	int N,M,S;
	int i;
	int a,b,c;
	char start, end;

	// �׷��� ����.
	//initGraph();	

	// ����, ���� �Է�
	scanf("%d %d %d",&N,&M,&S);
	for(i=0;i<M;i++){
		scanf("%d %d %d",&a,&b,&c);
		insertEdge(a,b,c);
	}
	
	for(i=0;i<=N;i++){
		if(i==S||i==0){
			continue;}
	DijkstraShortestPathsSingleTargetCount(S, i); // ���ͽ�Ʈ�� �˰��� ����

	}
}

// �׷����� �ʱ�ȭ���ִ� �Լ� - ���� ����ŭ ��������� �Ѵ�.

void insertEdge(int start, int end, int weight)
{
	Adjacency *node;	// ������ ���� ���

	// ��������� ������ ����� �Ѵ�.
	node = (Adjacency *)malloc(sizeof(Adjacency));
	node->vertex = end;
	node->weight = weight;
	node->link = Graph_list[start];
	Graph_list[start] = node;

	// �ݴ��ʿ����� ����
	node = (Adjacency*)malloc(sizeof(Adjacency));
	node->vertex = start;
	node->weight = weight;
	node->link = Graph_list[end];
	Graph_list[end] = node;
}

void DijkstraShortestPathsSingleTargetCount(int start, int end)
{
	int distance[NUM_VERTICES];		// �Ÿ�
	int	pathcnt[NUM_VERTICES];		// ��� ��
	int check[NUM_VERTICES];		// ���� �ȿ� �ִ��� ����
	Adjacency *tmp;					// �ֱٿ� ���� ������ �����ϱ� ���� ����ü ������
	int cycle, min, now, i;			// cycle : �۾� Ƚ��, 
									// min = �ִܰŸ��� ���� �񱳰�, 
									// now : �ֱٿ� ���� ����

	// �ʱ�ȭ ����
	for (i = 0; i < NUM_VERTICES; i++)
	{
		distance[i] = INFINITE;		// �Ÿ��� �������� �ʱ�ȭ
		pathcnt[i] = 0;				// ��μ��� 0���� �ʱ�ȭ
		check[i] = 0;				// PQ�� �ִ��� ������ ���� ( PQ�� ����ִٸ� 0 )
	}
	distance[start] = 0;			// �ʱ� start ���� - �ڽű����� �Ÿ��� 0
	cycle = 0;

	while (cycle < NUM_VERTICES - 1)		// ��� ������ ���� �ϱ� ���ؼ�
	{
		min = INFINITE;		// �ּҰ� �������� �ʱ�ȭ
		for (i = 0; i < NUM_VERTICES; i++)
			if (distance[i] < min && !check[i])		// ���� ���� ���� �� �Ÿ��� �ּ��� �������κ��� ����
			{
				min = distance[i];
				now = i;	// ���濡 ���� ���� ��ġ
			}

		check[now] = 1;			// ���� �ȿ� �ֱ�
		tmp = Graph_list[now];	// ���濡 ���� ���� ������ ����ü ������

		while(tmp != NULL)
		{	
			if (!check[tmp->vertex])	// ���� ���� �����̶��
			{
				// ������ �Ÿ� = ���� �ִܰŸ� -- �ٸ� ��θ� ���� ���� �ִܰŸ�
				if (min + tmp->weight == distance[tmp->vertex])	
					pathcnt[tmp->vertex] += pathcnt[now];		// �ִܰ�� ���� ����
				
				//  ������ �Ÿ� < ���� �ִܰŸ� --> ���� ��ȭ
				if (min + tmp->weight < distance[tmp->vertex])	
				{
					distance[tmp->vertex] = min + tmp->weight;	// �ִܰŸ� ����
					if(now==start ) pathcnt[tmp->vertex] = 1;				// ���� ������������ �������̶�� ��μ� 1
					else			pathcnt[tmp->vertex] = pathcnt[now];	// �� �̿ܿ��� �θ���ġ�� ��μ�
				}
			}	// if
		tmp = tmp->link;	// ���� ���� ����, ���� �˻�
		}	// while

		cycle++;
		if (now == end) break;		// ���� ������ ���� ������ ���ٸ� ����
	}	// while
	if(distance[end]!=9999){
	printf("%d %d\n",  end , distance[end]); // ����� ���
	}
	}

