#include <iostream>
#include <stdlib.h>
#include <list>
#include <queue>
#include <string.h>
using namespace std;

typedef int VertexType;		// ��������
typedef int EdgeType;			// ���ϵ�Ȩֵ������
#define MAXVEX 20				// ������
#define INFINITY 65535			// �������
/*
* �ڽ�����
*/

typedef struct Node
{
	VertexType data;
	//EdgeType weight;		// ���Ϊ����ͼ�������Ȩ�أ����������Ȩ��
}Node;

class NoGraph
{
public:
	typedef list<Node> *lst;
	lst *pHeadArr;
	int vexNum;
	int adjNum;
	NoGraph()
	{
		pHeadArr = new lst[MAXVEX];
		memset(pHeadArr, 0, MAXVEX * sizeof(Node));		// ��ʼ��Ϊ�����
	}
	~NoGraph()
	{
		for(int i = 0; i < MAXVEX; ++i)
		{
			delete pHeadArr[i];
			pHeadArr[i] = NULL;
		}
		delete [] pHeadArr;
		pHeadArr = NULL;
	}
	void creatGraph(const int &vexNum, const int &adjNum)
	{
		int index;
		Node node;
		// �����ж����������λ
		for(int i = 0; i < vexNum; ++i)
		{
			cout << "�����붥�������������ݣ�index = data��"<< endl;
			cin >> index;
			node.data = index;
			if(pHeadArr[index] == NULL)
			{
				pHeadArr[index] = new list<Node>();
			}
			pHeadArr[index]->push_back(node);
		}
		// ����ÿһ���������Ľ��
		for(int j = 0; j < adjNum; ++j)
		{
			cout <<"����ߵ��������㣬index1,index2�����裺index=data��" << endl;
			int index1, index2;
			cin >> index1 >> index2;
			Node node1, node2;
			node1.data = index1;
			node2.data = index2;
			pHeadArr[index1]->push_back(node2);
			pHeadArr[index2]->push_back(node1);
		}
		cout << "******* ������� *******" << endl;
	}

	// ��ӡ����
	void print(const int vexNum)
	{
		for(int index = 0; index < vexNum; ++index)
		{
			list<Node>::iterator it = pHeadArr[index]->begin();
			for(; it != pHeadArr[index]->end(); ++it)
				cout << it->data << " -- " ;
			cout << endl;
		}
	}
	// ���Ҷ��Ⱥ���
	void secondFriend(const int &index, const int vexNum)
	{
		int *arr = new int[vexNum];
		memset(arr, -1, vexNum);
		queue<int> sedfrd;
		if(&pHeadArr[index] != NULL)
		{
			list<Node>::iterator it1 = pHeadArr[index]->begin();
			for(; it1 != pHeadArr[index]->end(); ++it1)
			{
				arr[it1->data] = it1->data;		// �����������һ�Ⱥ��ѡ�
			}
			for(int i = 1; i < vexNum; ++i)
			{
				if(arr[i] == -1)
					continue;
				list<Node>::iterator it2 = pHeadArr[arr[i]]->begin();
				for(; it2 != pHeadArr[arr[i]]->end(); ++it2)
				{
					// ��ѭ�����ж϶��Ⱥ����Ƿ���һ�Ⱥ��ѡ�
					if(it2->data != arr[it2->data])
					{
						sedfrd.push(it2->data);
						arr[it2->data] = it2->data;
					}
				}
			}
			while(!sedfrd.empty())
			{
				cout << sedfrd.front() << endl;
				sedfrd.pop();
			}
		}
	}
};
/* ͼ�������£�
0-1-2--3
|   |  |
4----  |
--------
*/

/*
ֱ�Ӹ���������ֵ�����в��ԡ�
0 1 2 3 4 
0 1
1 2
2 3
2 4
3 4
4 0
*/

int main()
{
	NoGraph *G = new NoGraph();
	const int a = 5;		// ������
	const int b = 6;		// ����
	G->creatGraph(a, b);	// �����ڽ���ͼ
	cout << "��ӡ�ڽ���ͼ" << endl;
	G->print(a);
	cout << "��ӡ0�Ķ��Ⱥ���" << endl;
	G->secondFriend(0, a);		// ���Ҳ���ӡ0�Ķ��Ⱥ���
	cout << "��ӡ1�Ķ��Ⱥ���" << endl;
	G->secondFriend(1, a);		// ���Ҳ���ӡ0�Ķ��Ⱥ���
//	system("pause");
	return 0;
}


