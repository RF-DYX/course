#include <stdio.h>
#include <queue>
#include <stack>

#define MAXVEX 100
#define INFINITY 65535
typedef char VertexType;/*�����������û��Զ���*/
typedef int EdgeType;	/*���ϵ�Ȩֵ�������û��Զ���*/
typedef int Boolean;
Boolean visited[MAXVEX];

/*�߱�ڵ�*/
typedef struct EdgeNode
{
	int adjvex;			/*�ڽӵ��򣬴洢�ö����Ӧ���±�*/
	EdgeType weight;	/*���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ*/
	EdgeNode *next;		/*����ָ����һ���ڽӵ�*/
};

/*�����ڵ�*/
typedef struct VertexNode
{
	VertexType data;		/*�����򣬴洢������Ϣ*/
	EdgeNode *firstedge;	/*�߱�ͷָ��*/

}VertexNode, AdjList[MAXVEX];

typedef struct  
{
	AdjList adjList;
	int numVertexes, numEdges;	/*ͼ�е�ǰ�������ͱ���*/
}GraphAdjList;

void CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("���붥�����ͱ���:\n");
	scanf("%d%d", &G->numVertexes, &G->numEdges);
	for(i = 0; i < G->numVertexes; ++i)	/*���������*/
	{
		scanf("%s", &G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}
	for(k = 0;k < G->numEdges; ++k)	/*�����߱�*/
	{
		printf("�����(vi,vj)�ϵĶ������:\n");
		scanf("%d%d", &i, &j);
		e = new EdgeNode;
		e->adjvex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;

		e = new EdgeNode;
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}


/*�ڽӱ��������ȵݹ��㷨*/
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
	visited[i] = 1;
	printf("%c", GL.adjList[i].data);
	p = GL.adjList[i].firstedge;
	while(p)
	{
		if(!visited[p->adjvex])
			DFS(GL, p->adjvex);
		p = p->next;
	}
}

/*�ڽӱ����ȱ�������*/
void DFSTraverse(GraphAdjList GL)
{
	int i;
	for(i = 0; i < GL.numVertexes; ++i)
		visited[i] = 0;
	for(i = 0; i < GL.numVertexes; ++i)
		if(!visited[i])
			DFS(GL, i);
}

/*�ڽӱ�Ĺ�ȱ����㷨*/
void BFSTraverse(GraphAdjList GL)
{
	int i;
	EdgeNode *p;
	std::queue<VertexType> que;
	for(i = 0; i < GL.numVertexes; ++i)
	{
		visited[i] = 0;
	}
	for(i = 0; i < GL.numVertexes; ++i)
	{
		if(!visited[i])
		{
			visited[i] = 1;
			printf("%c", GL.adjList[i].data);
			que.push(i);
			while(!que.empty())
			{
				i = que.front();
				que.pop();
				p = GL.adjList[i].firstedge;
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex] = 1;
						printf("%c", GL.adjList[p->adjvex].data);
						que.push(p->adjvex);
					}
					p = p->next;
				}
			}
		}
	}
}
/************************************************************************/
/*                                                                      */
/************************************************************************/
typedef struct  
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("���붥�����ͱ���:\n");
	scanf("%d%d", &G->numVertexes, &G->numEdges);
	for(i = 0; i<G->numVertexes; ++i)
	{
		scanf("%c", &G->vexs[i]);
	}
	for(i = 0;i<G->numVertexes;++i)
		for(j = 0;j<G->numVertexes;++j)
			G->arc[i][j] = INFINITY;
	for(k = 0;k < G->numEdges; ++k)
	{
		printf("�����(vi,vj)�ϵ��±�i,�±�Ϊj��Ȩw:\n");
		scanf("%d%d%d", &i,&j,&w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}

/*�ڽӾ����������ȵݹ��㷨*/
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = 1;
	printf("%c", G.vexs[i]);
	for(j = 0; j < G.numVertexes; ++j)
	{
		if(!visited[j] && G.arc[i][j] == 1)
		{
			DFS(G, j);
		}
	}
}

/*�ڽӾ������ȱ�������*/
void DFSTraverse(MGraph G)
{
	int i;
	for(i = 0; i < G.numVertexes; ++i)
		visited[i] = 0;
	for(i = 0; i <G.numVertexes; ++i)
	{
		if(!visited[i])
			DFS(G, i);
	}
}

/*�ڽӾ������ȱ����㷨�ǵݹ�*/
void DFS_Nr(MGraph G, int i)
{
	for(int j = 0; j < G.numVertexes; ++j)
		visited[j] = 0;
	visited[i] = 1;
	printf("%c\n", G.vexs[i]);
	std::stack<int> st;
	st.push(i);
	bool is_push;
	while(!st.empty())
	{
		int k = st.top();
		is_push = 0;
		for(int j = 0; j < G.numVertexes; ++j)
		{
			if(!visited[j] && G.arc[k][j] == 1)
			{
				visited[j] = 1;
				printf("%c\n", G.vexs[j]);
				st.push(j);
				is_push = 1;
				break;
			}
		}
		if(!is_push)
		{
			st.pop();
		}
	}

}


/*�ڽӾ���Ĺ�ȱ����㷨*/
void BFSTraverse(MGraph G)
{
	int i,j;
	std::queue<VertexType> que;
	for(i = 0; i < G.numVertexes; ++i)
		visited[i] = 0;
	for(i = 0; i < G.numVertexes; ++i)
	{
		if(!visited[i])
		{
			visited[i] = 1;
			printf("%c", G.vexs[i]);
			que.push(i);
			while(!que.empty())
			{
				i = que.front();
				que.pop();
				for(j = 0; j < G.numVertexes; ++j)
				{
					if(G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = 1;
						printf("%c", G.vexs[j]);
						que.push(j);
					}
				}

			}
		}
	}
}


int main()
{
	GraphAdjList Graph;
	CreateALGraph(&Graph);
	DFS(Graph, 0);
	BFSTraverse(Graph);
	return 0;
}