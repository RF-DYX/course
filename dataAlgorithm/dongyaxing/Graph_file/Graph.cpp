#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char VertexType;		// ��������
typedef int EdgeType;			// ���ϵ�Ȩֵ������
#define MAXVEX 20				// ������
#define INFINITY 65535			// �������
/*
* �ڽӾ���ͼ
*/
typedef struct MGraph
{
	VertexType vexs[MAXVEX];			// �����
	EdgeType arc[MAXVEX][MAXVEX];		// �ڽӾ��󣬱�
	int numVertexs, numEdges;			// ;�е�ǰ�Ķ������ͱ���
}MGraph;


/****************************************************************
* @brief : 		����һ��ͼ������������ͼ���ڽӾ����ʾ
* @author : 	dyx
* @date : 		2019/7/3 15:12
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	cout << "please input vexs and edges: " << endl;// ���붥�����ͱ���
	cin >> G->numVertexs;
	cin >> G->numEdges;			// �� = ������^2
	cout << "please input vexs num: " << endl;
	for (i = 0; i < G->numVertexs; ++i)		// ���붥����Ϣ�����������
	{
		cin >> G->vexs[i];
	}
	for (i = 0; i < G->numVertexs; ++i)		// �ڽӾ����ʼ��
	{
		for (j = 0; j < G->numVertexs; ++j)
		{
			G->arc[i][j] = INFINITY;
		}
	}
	for (k = 0; k < G->numEdges; ++k)		// ����numEdges���ߡ�
	{
		cout << "please input the i,j of <vi, vj> , and w(begin at 0):" << endl;
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];		// ����ͼ���Գ�
	}
}


/****************************************************************
* @brief : 		��ӡ���ͼ�ڽӾ���
* @author : 	dyx
* @date : 		2019/7/3 15:23
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void print(MGraph *G)
{
	cout << "Vertexs : " << G->numVertexs << endl;
	for (int i = 0; i < G->numVertexs; ++i)
	{
		cout << G->vexs[i] << " ";
	}
	cout << endl;
	cout << "Edges : " << G->numEdges << endl;
	for (int i = 0; i < G->numVertexs; ++i)
	{
		for (int j = 0; j < G->numVertexs; ++j)
		{
			cout << G->arc[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


/************************************************************************/
/*���ڽӾ���
/************************************************************************/
// ��
typedef struct EdgeNode
{
	int adjvex;				// �ڽӵ��򣬴洢�ö����Ӧ���±�
	EdgeType weight;		// ���ڴ洢Ȩֵ�����Բ���Ҫ������Ҫ��Ĭ��Ϊ1��Ҳ����ɾ��
	struct EdgeNode *next;	// ����ָ����һ���ڽӵ�
	EdgeNode()
	{
		adjvex = -1;
		weight = 1;
		next = NULL;
	}
}EdgeNode;

// ����
typedef struct VertexNode
{
	VertexType data;			// �����򣬴洢������Ϣ
	EdgeNode *firstedge;		// �ߵı�ͷָ��
}VertexNode, AdgList[MAXVEX];

// ͼ��
typedef struct GraphAdjList
{
	AdgList adjList;
	int numVertexes, numEdges;		// ͼ�е�ǰ�������ͱ���
}GraphAdjList;


/****************************************************************
* @brief : 		���������ڽ�ͼ
* @author : 	dyx
* @date : 		2019/7/4 11:15
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	cout << "please input vexs and edges: "<< endl;
	cin >> G->numVertexes;
	cin >> G->numEdges;
	cout << "please input vexs num: " << endl;
	for (i = 0; i < G->numVertexes; ++i)		// ���붥����Ϣ
	{
		cin >> G->adjList[i].data;				// ���붥����Ϣ
		G->adjList[i].firstedge = NULL;			// ������Ϊ�ձ�
	}
	for (k = 0; k < G->numEdges; ++k)
	{
		cout << "please <vi,vj> weights(begin at 0 index) : "<< endl;
		cin >> i;
		cin >> j;
		
		e = (EdgeNode *)malloc(sizeof(EdgeNode));	// ���ڴ�����ռ䣬���ɱ߱���
		e->adjvex = j;								// �ڽ����Ϊj
		e->next = G->adjList[i].firstedge;			// ��eָ��ָ��ǰ����ָ��Ľ��
		G->adjList[i].firstedge = e;				// ����ǰ�����ָ��ָ��e

		e = (EdgeNode *)malloc(sizeof(EdgeNode));	// ���ڴ�����ռ䣬���ɱ߱���
		e->adjvex = i;								// �ڽ����Ϊi
		e->next = G->adjList[j].firstedge;			// ��eָ��ָ��ǰ����ָ��Ľ��
		G->adjList[j].firstedge = e;				// ����ǰ�����ָ��ָ��e
	}
}

/****************************************************************
* @brief : 		��Ҫ��ӡ�������ͳ�������
* @author : 	dyx
* @date : 		2019/7/4 11:16
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void PrintListGraph(GraphAdjList *G)
{
	cout << "vertexe nums: " << G->numVertexes << endl;
	for (int i = 0; i < G->numVertexes; ++i)
	{
		cout << G->adjList[i].data << endl;
	}
	cout << "edges nums: " << G->numEdges << endl;
	for (int i = 0; i < G->numEdges; ++i)
	{
		cout << G->adjList[i].data;
		cout << "uncomplete..."<< endl;
	}
}

int main()
{
	// �ڽӾ���ͼ
	MGraph *G = new MGraph();
	CreateMGraph(G);
	print(G);

	//��ͼ
	GraphAdjList *grlst = new GraphAdjList();
	CreateALGraph(grlst);
	//PrintListGraph(grlst);
	//system("pause");
	return 0;
}
