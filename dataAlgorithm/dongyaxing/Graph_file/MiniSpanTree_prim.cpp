#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char VertexType;		// ��������
typedef int EdgeType;			// ���ϵ�Ȩֵ������
#define MAXVEX 9				// ������
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

void MiniSpanTree_prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		// ���涥���±�
	int lowcost[MAXVEX];	// ������ض���֮���Ȩֵ
	lowcost[0] = 0;			// ��ʼ����һ��ȨֵΪ0����v0������������lowcost��ֵΪ0��˵�����±�Ķ����Ѿ�����������
	adjvex[0] = 0;			// ��ʼ����һ�������±�Ϊ0
	for (i = 1; i < G.numVertexs; ++i)		// ѭ�����±�Ϊ0���ȫ������
	{
		lowcost[i] = G.arc[0][i];			// ��V0������֮�б��Ȩֵ��������
		adjvex[i] = 0;						// ��ʼ����Ϊv0���±�
	}
	for (i = 1; i < G.numVertexs; ++i)
	{
		min = INFINITY;		// ��ʼ����СȨֵΪ��
		j = 1;
		k = 0;
		while (j < G.numVertexs)	// ѭ��ȫ������
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				// ���Ȩֵ��Ϊ0����ȨֵС��min
				min = lowcost[j];		// ���õ�ǰȨֵ��Ϊ��Сֵ
				k  = j;					// ����ǰ��Сֵ���±����k
			}
			++j;
		}
		cout << "��ӡ��ǰ�������Ȩֵ��С�ߣ�" << adjvex[k] << " - " << k << endl;
		lowcost[k] = 0;		// ����ǰ�����Ȩֵ����Ϊ0�� ��ʾ�˶����Ѿ��������
		for (j = 1; j < G.numVertexs; ++j)
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				// ���±�Ϊk�������ȨֵС�ڴ�ǰ��Щ���㣬δ������������Ȩֵ
				lowcost[j] = G.arc[k][j];	// ����СȨֵ����lowcose
				adjvex[j] = k;				// ���±�Ϊk�Ķ������adjvex
			}
		}
	}
}

int main()
{
	// �ڽӾ���ͼ
	MGraph *G = new MGraph();
	CreateMGraph(G);
	print(G);
	MiniSpanTree_prim(*G);	// ������
	
//	system("pause");
	return 0;
}
