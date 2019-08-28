/*
* �������򡪡�DFS
*/
#include <iostream>
#include<vector>
#include<list>
using namespace std;

// ͼ�ṹ
class Graph
{
public:
	int v;					// �������
	typedef vector<int>* node;
	node *adj;		// �ڽӱ�
	Graph(int data):v(data)
	{
		adj = new node[v];
		for (int i = 0; i < v; ++i)
		{
			adj[i] = new vector<int>();		// ÿ������������һ����
		}
	}
	void addEdge(int s, int t)
	{
		adj[s]->push_back(t);		// s->t, ���ڽӱ�Ļ��������ʱ��ע��˳�򣬶����0��ʼ
	}
	~Graph()
	{
		for (int i = 0; i < v; ++i)
		{
			delete adj[i];
		}
		delete []adj;
	}

	void print()
	{
		for (int i = 0; i < v; ++i)
		{
			cout << i << " ����ȣ� " ;
			for (int j = 0; j < adj[i]->size(); ++j)
			{
				cout << adj[i]->at(j) << " ";
			}
			std::cout << endl;
		}
	}

	void topoSortByDFS();
	void dfs(int v, vector<int> **adj, bool *visited);
};

void Graph::topoSortByDFS()
{
	bool *visited;
	visited = new bool[6]();		// ֻ��6������
	for (int i = 0; i < v; ++i)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			dfs(i, adj, visited);
		}
	}
}

/****************************************************************
* @brief : 		dfs�����������
* @author : 	dyx
* @date : 		2019/8/28 10:34
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void Graph::dfs(int v, vector<int> **adj, bool *visited)
{
	for (int i = 0; i < adj[v]->size(); ++i)
	{
		int w = adj[v]->at(i);
		if (visited[w] == true)
		{
			continue;
		}
		visited[w] = true;
		dfs(w, adj, visited);
	}
	cout << " -> " << v ;
}

int main()
{
	// ��ʼ��һ��ӵ��6�����������ͼ
	const int n = 6;
	Graph G(n);	
	// (num1, num2);��ʾ: num1 <- num2,2����1ִ��
	G.addEdge(1,0);
	G.addEdge(2,0);
	G.addEdge(4,1);
	G.addEdge(3,1);
	G.addEdge(4,2);
	G.addEdge(5,3);
	G.addEdge(5,4);

	cout << "��������ݣ�" << endl;
	G.print();
	cout << "���topoDFS���� " << endl;
	G.topoSortByDFS();
//	system("pause");
	return 0;
}
