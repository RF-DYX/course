/*
* Copyright: (c) 2019
*
* �ļ�����:  Graph.h	
* �ļ���ʶ��
* ժ	Ҫ�� ��ʵ���ǻ����ڽӱ�ķ�ʽ
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/6/13  16:18
*/
#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <queue>
#include <iostream>
class Graph
{
	typedef std::vector<int>* pVector;
public:
	//�Զ��幹�캯��
	Graph(int nCount)
	{
		count = nCount;
		adjacency = new pVector[count];
		for(int i = 0; i < count; ++i)
		{
			adjacency[i] = new std::vector<int>();
		}
	}

	//��������
	~Graph(void)
	{
		for(int i = 0; i < count; ++i)
		{
			delete adjacency[i];
		}
		delete []adjacency;

	}

	//�����������
	void BFS(int start, int end)
	{
		if(start == end)
			return;
		bool *visited = new bool[count];
		memset(visited, 0, sizeof(bool)*count);
		visited[start] = true;
		std::queue<int> que;
		que.push(start);
		int *prev = new int[count];
		for(int i = 0; i < count; ++i)
			prev[i] = -1;
		while(!que.empty())
		{
			int w = que.front();
			que.pop();
			for(int i = 0; i < adjacency[w]->size(); ++i)
			{
				int q = adjacency[w]->at(i);
				if(!visited[q])
				{
					prev[q] = w;
					if(q == end)
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

	//�����������
	void DFS(int start, int end)
	{
		found = false;
		bool* visited = new bool[count];
		memset(visited, 0, sizeof(bool)*count);
		int* prev = new int[count];
		for(int i = 0; i < count; ++i)
		{
			prev[i] = -1;
		}
		recurDfs(start, end, visited, prev);
		print(prev, start, end);
	}

	//���ӱ�
	void addEdge(int start, int end)
	{
		adjacency[start]->push_back(end);
		adjacency[end]->push_back(start);
	}

private:
	int count;
	pVector* adjacency;
	bool found;

	//�ݹ��ӡ
	void print(int* arr, int start, int end)
	{
		if(arr[end] != -1 && end != start)
		{
			print(arr, start, arr[end]);
		}
		if(arr[end] != -1)
			std::cout << arr[end] << "->";
	}
	
	void recurDfs(int w, int target, bool* visited, int* prev)
	{
		if(found == true)
			return;
		visited[w] = true;
		if(w == target)
		{
			found = true;
			return;
		}
		for(int i = 0; i < adjacency[w]->size(); ++i)
		{
			int q = adjacency[w]->at(i);
			if(!visited[q])
			{
				prev[q] = w;
				recurDfs(q, target, visited, prev);
			}
		}
	}
};

#endif // _GRAPH_H