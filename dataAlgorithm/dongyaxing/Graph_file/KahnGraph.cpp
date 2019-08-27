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
			adj[i] = new vector<int>;		// ÿ������������һ����
		}
	}
	void addEdge(int s, int t)
	{
		adj[s-1]->push_back(t);		// ��sΪ���㣬t����s����
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
			cout << i+1 << " ����ȣ� " ;
			for (int j = 0; j < adj[i]->size(); ++j)
			{
				cout << adj[i]->at(j) << " ";
			}
			std::cout << endl;
		}
	}
};

// ����һ�����Ϊ0�ĵ㡣��ӡ���
// �ҰѴ˵�ɾ������ǣ�
// ѭ��������е�
void topoSortByKahn(int v, vector<int>* *adj)
{
	int *inDegree = new int[v]();		// ͳ��ÿ����������,��ʼ��Ϊ0
	for (int i = 0;  i < v; ++i)
	{
		for (int j = 0; j < adj[i]->size(); ++j)
		{
			int w = adj[i]->at(j);		// i->w
			if (w != 0)
			{
				inDegree[(w-1)]++;			// wΪ�����ֵ�����Ե�����ʹ��ʱ����Ҫ-1
			}
		}
	}

	std::list<int> queue;
	for (int i = 0; i < v; ++i)
	{
		if (inDegree[i] == 0)
		{
			queue.push_back(i);		// ��¼���Ϊ0�Ķ��������
		}
	}

	while (!queue.empty())		// ���Ϊ0�Ķ��㣬�ǿ�
	{
		int i = queue.front();	// ȡ����һ�����Ϊ0����
		cout << " <- " << i+1 << endl;		// ���ֵ
		queue.remove(i);	// ɾ����һ�����Ϊ0������
		for (int j = 0; j < adj[i]->size(); ++j)	// ����i�����ָ��i�Ķ���
		{
			int k = adj[i]->at(j);		// kΪֵ
			inDegree[(k-1)]--;
			if (inDegree[(k-1)] == 0)
			{
				queue.push_back(k-1);		// ѹ��ȥ����Ȼ������
			}
		}
		cout << endl;
	}
}


int main()
{
	// ��ʼ��һ��ӵ��6�����������ͼ
	const int n = 6;
	Graph G(n);	
	// (num1, num2);��ʾ: num1 <- num2, 
	G.addEdge(1,0);
	G.addEdge(2,1);
	G.addEdge(5,2);
	G.addEdge(3,1);
	G.addEdge(4,2);
	G.addEdge(5,3);
	G.addEdge(6,5);
	G.addEdge(6,4);
	cout << "��������ݣ�" << endl;
	G.print();
	cout << "���topo���� " << endl;
	topoSortByKahn(G.v, G.adj);
//	system("pause");
	return 0;
}
