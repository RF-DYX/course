#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <memory.h>
#define N 6
typedef unsigned int UINT;
using namespace std;

typedef struct HFMnode
{
	char data;
	char code;
	UINT weight;
	HFMnode *parent, *lp, *rp;
	HFMnode()
	{
		data = '/';
		code = '0';
		weight = 0;
		parent = lp = rp = NULL;
	}
}HFMnode;

class comp
{
public:
	bool operator()(HFMnode* &a, HFMnode* &b)const
	{
		if (a->weight == b->weight)
		{
			return a->data > b->data;
		}
		return a->weight > b->weight;
	}
};

class HuffmanTree
{
public:
	HFMnode *root;		// �����ָ��
	HFMnode *node[2*N-1];	// N���ַ�����������������2*n-1
	priority_queue<HFMnode*, vector<HFMnode*>, comp> pri_queue;	// �����ͬʱ���������򡣰���Ȩ�شӴ�С
	// ���ȶ����д����ָ��ʱ������������Ӧ����дһ��comp�࣬����дoperator()
	void creatTree_outputCode(int *w)
	{
		char ch = 'a';
		HFMnode *left, *right;
		for (int i = 0; i < N; ++i, ++ch)		// ��abcdef���룬��Ȩ��Ϊ����������顣
		{
			// ����ǮN���ַ��ڵ㣬����Ȩ�غ��ַ���Ϣ
			node[i] = new HFMnode();
			node[i]->weight = w[i];
			node[i]->data = ch;
			pri_queue.push(node[i]);
		}

		for (int i = N; i < 2*N-1; ++i)
		{
			// ���������ɵ�N-1���ڵ�
			node[i] = new HFMnode();
			if (pri_queue.top()->data != '/')
			{
				//���׽ڵ㲻�������ɵģ����׷��ұ�
				right = pri_queue.top();
				right->code = '1';
				pri_queue.pop();
				left = pri_queue.top();
				left->code = '0';
				pri_queue.pop();
			}
			else
			{
				//���׽ڵ��������ɵģ����׷����
				left = pri_queue.top();
				left->code = '0';
				pri_queue.pop();
				right = pri_queue.top();
				right->code = '1';
				pri_queue.pop();
			}
			// �½ڵ�Ȩֵ����������ָ��Խ�
			node[i]->weight = left->weight + right->weight;
			node[i]->lp = left;
			node[i]->rp = right;
			left->parent = node[i];
			right->parent = node[i];
			pri_queue.push(node[i]);	// �����ɵĽ��cherub����
		}
		root = pri_queue.top();		// ���ʣһ����㣬�Ǹ��ڵ�
		creatHuffCode();
		for (int i = 0; i < 2*N-1; ++i)
		{
			delete node[i];
		}
	}

	void creatHuffCode()
	{
		HFMnode* parent;
		string huffCode;	// ����������
		int codelen = 0;	// ������ַ����������ܳ���bits
		for (int i = 0; i < N; ++i)
		{
			huffCode = "";
			parent = node[i];	// ���Լ���Ҷ�ӽڵ㣩��ʼ�����Ҹ���㣬ֱ��root
			cout << i + 1 << " " << node[i]->data << " The Huffman encoding is : ";
			while(parent != root)
			{
				//huffCode.push_back(parent->code);	// ��·���еı������ַ���
				huffCode+=parent->code;
				parent = parent->parent;
			}
			reverse(huffCode.begin(), huffCode.end());	// �����յı��뷭תһ��
			cout << huffCode << endl;
			codelen += huffCode.size()*node[i]->weight;		// ���ֽ�code��*���ֵĴ���
		}
		cout << "The Huffman encoding length of the string is " << codelen << " bits." << endl;
	}
};

int main()
{
	HuffmanTree huff;
	cout << "Please enter the weight of the character , total " << N << " character: " << endl;
	int w[N];
	for (int i = 0; i < N; ++i)
	{
		cout << "No. " << i+1 << " ";
		cin >> w[i];
	}
	huff.creatTree_outputCode(w);
//	system("pause");
	return 0;
}
