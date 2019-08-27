/*
* �������������
	ÿ�����㶼Ҫ����һ����У�ÿ����Ҳ���ᱻ����һ�Σ�����
	ʱ�临�Ӷ�O(V+E)
	��Ҫ�����ڴ����visited��prev���顢queue���У�����
	�ռ临�Ӷ�O(V)

* �������������
	ÿ�������ᱻ�������Σ�һ�α�����һ�λ��ˣ�����
	ʱ�临�Ӷ�O(E)��E��ʾ�ߵĸ���
	��Ҫ�����ڴ����visited��prev����͵ݹ����ջ��
	visited��prev����Ĵ�С���������V�йأ��ݹ���Ȳ��ᳬ���������V������
	�ռ临�Ӷ�O(V)
*/
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
	typedef std::vector<int>* pVector;	// �洢�õ�����������ӵĵ�
public:
	// ���캯��
	Graph(int nCount)
	{
		count = nCount;
		adj = new pVector[count];
		for (int i = 0; i < count; ++i)
		{
			adj[i] = new std::vector<int>();
		}
	}
	// ��������
	~Graph()
	{
		for (int i = 0; i < count; ++i)
		{
			delete adj[i];
			adj[i] = NULL;
		}
		delete []adj;
		adj = NULL;
	}

	// �����������
	void BFS(int start, int end)
	{
		if(start == end)
			return;
		bool *visited = new bool[count];		// false - δ���ʹ���true - ���ʹ�
		memset(visited, 0, sizeof(bool)*count);
		visited[start] = true;
		std::queue<int> que;
		que.push(start);
		int *prev = new int[count];			// ��¼ǰ�����
		for (int i = 0; i < count; ++i)
		{
			prev[i] = -1;
		}
		while(!que.empty())
		{
			int w = que.front();
			que.pop();
			for (int i = 0; i < adj[w]->size(); ++i)
			{
				int q = adj[w]->at(i);
				if (!visited[q])
				{
					prev[q] = w;
					if (q == end)
					{
						print(prev, start, end);
						return;
					}
					visited[q] = true;
					que.push(q);
				}
			}
		}
		delete []visited;
		delete []prev;
	}

	// �����������
	void DFS(int start, int end)
	{
		found = false;
		bool *visited = new bool[count];
		memset(visited, 0, sizeof(bool)*count);
		int *prev = new int[count];
		for (int i = 0; i < count; ++i)
		{
			prev[i] = -1;
		}
		recurDfs(start, end, visited, prev);
		print(prev, start, end);
	}

	// ���ӱߣ�����ͼ��
	void addEdge(int start, int end)
	{
		adj[start]->push_back(end);
		adj[end]->push_back(start);
	}

	// ��ӡ���ͼ
	void printGraph()
	{
		for (int i = 0; i < count; ++i)
		{
			cout << i << "->";
			for (int j = 0; j < adj[i]->size(); ++j)
			{
				cout << adj[i]->at(j) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

private:
	int count;		// ͼ�Ķ���
	pVector* adj;	// ͼ�ı�����
	bool found;
	// �ݹ��ӡ
	void print(int *arr, int start, int end)
	{
		if (arr[end] != -1 && end != start)
		{
			print(arr, start, arr[end]);
		}
		if (arr[end] != -1)
		{
			std::cout << arr[end] << "->";
		}
	}

	// DFS����
	void recurDfs(int w, int target, bool *visited, int *prev)
	{
		if (found == true)
		{
			return;
		}
		visited[w] = true;
		if(w == target)
		{
			found = true;
			return;
		}
		for (int i = 0; i < adj[w]->size(); ++i)
		{
			int q = adj[w]->at(i);
			if (!visited[q])
			{
				prev[q] = w;
				recurDfs(q, target, visited, prev);
			}
		}
	}
};

int main()
{
	Graph g(8);
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,5);
	g.addEdge(3,4); 
	g.addEdge(4,5);
	g.addEdge(4,6);
	g.addEdge(5,7);
	g.addEdge(6,7);
	g.printGraph();		// �鿴ͼ�������Ƿ���ȷ
	cout << "���Ҵ�0��6��·�����������" << endl;
	cout << "�������������" << endl;
	g.DFS(0,6);			// ���Ҵ�0��6��·���������
	cout << endl;
	cout << "�������������" << endl;
	g.BFS(0,6);
	cout << endl;
//	system("pause");
	return 0;
}
