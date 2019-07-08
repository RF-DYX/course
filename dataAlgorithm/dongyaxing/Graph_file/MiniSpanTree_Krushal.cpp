#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int VertexType;		// ��������
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
	cout << "Vertex : " << G->numVertexs << endl;
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

/* �ߵĽṹ�� */
typedef struct Edge
{
	int begin;
	int end;
	int weight;
}Edge;


/****************************************************************
* @brief : 		����Ȩ��������С����
* @author : 	dyx
* @date : 		2019/7/8 15:09
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void sortByWeight(Edge * edges, int len)
{
	int preIndex;
	Edge current;
	for (int i = 1; i < len; ++i)
	{
		preIndex = i -1;
		current = edges[i];
		while(preIndex >= 0 && edges[preIndex].weight > current.weight)
		{
			edges[preIndex + 1] = edges[preIndex];
			--preIndex;
		}
		edges[preIndex + 1] = current;
	}
}

//bool comp(Edge &a, Edge &b)
//{
//	return a.weight > b.weight ? true:false;
//}

/****************************************************************
* @brief : 		�������߶����β���±�
* @author : 	dyx
* @date : 		2019/7/8 15:08
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
int Find(int *parent, int f)
{
	while(parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/****************************************************************
* @brief : 		Kruskal--��С������
* @author : 	dyx
* @date : 		2019/7/8 15:20
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXVEX];		// ����߼�����
	int parent[MAXVEX];		// ����һ���������жϱ�����Ƿ��γɻ�·
	// ���ڽӾ���Gת��Ϊ�߼����� edges
	int k = 0;
	for (i = 1; i < G.numVertexs; ++i)
	{
		for (int j = 0; j < i; ++j, ++k)
		{ 
			edges[k].begin = G.vexs[i];
			edges[k].end = G.vexs[j];
			edges[k].weight = G.arc[i][j];
		}
	}
	// ����Ȩ��С��������
	sortByWeight(edges, G.numVertexs * (G.numVertexs - 1) / 2);
	for (i = 0; i < G.numVertexs; ++i)
	{
		parent[i] = 0;		// ��ʼ������ֵΪ0
	}
	for (i = 0; i < G.numVertexs; ++i)		// ѭ��ÿһ����
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)		//	����n��m���ȣ�˵���˱�û���������������γɻ�·
		{
			parent[n] = m;	// ���˱ߵĽ�β��������±�Ϊ����parent�У���ʾ�˶����Ѿ���������������
			cout << "(" << edges[i].begin << ", " << edges[i].end << ")" << " " << edges[i].weight << endl;
		}
	}
}

/*
���룺
6 10
0 1 2 3 4 5 
1 0 6
2 0 1
2 1 5
3 0 5
3 2 5
4 1 3
4 2 6
5 2 4
5 3 2
5 4 6
���룺
(2, 0) 1
(5, 3) 2
(4, 1) 3
(5, 2) 4
(2, 1) 5
(3, 0) 5 //���һ��������
*/
int main()
{
	// �ڽӾ���ͼ
	MGraph *G = new MGraph();
	CreateMGraph(G);
	print(G);
	MiniSpanTree_Kruskal(*G);	// ������

//	system("pause");
	return 0;
}
