#ifndef _ACMATCH_H
#define _ACMATCH_H

#include<iostream>
#include <string.h>
#include <vector>

using namespace std;
// ���ڱ���������е�λ�ü�����
struct PosSet
{
	std::vector<int> vPos;
	std::vector<int> vLen;
};

// trie���ṹ
class ACNode
{
public:
	// �������ַ���ʼ������
	ACNode(const char ch):isEndingChar(false), length(-1), nodeNum(0), pFail(NULL)
	{
		data = ch;
		memset(child, 0, sizeof(child));
	}
	// Ĭ�Ϲ��캯������ʼ������
	ACNode():isEndingChar(false), length(-1), nodeNum(0), pFail(NULL)
	{
		memset(child, 0, sizeof(child));
	}

	bool operator == (const ACNode &b)
	{
		return data == b.data;
	}

	~ACNode(){};

	char data;
	ACNode* child[26];		// ��������洢����26��ACNode*
	bool isEndingChar;		// �Ƿ�Ϊ��β�ַ�
	int length;				// ��isEndingChar = true,��¼ģʽ���ĳ���
	int nodeNum;			// ��¼������
	ACNode* pFail;			// ʧЧ���
};

class AC
{
public:
	AC(void);
	~AC(void);
	template<typename Iterator>
	void insert(Iterator begin, Iterator end);

	template<typename Iterator>
	bool find(Iterator begin, Iterator end);

	template<typename Iterator>
	void match(Iterator begin, Iterator end, PosSet *ret);

	void insert(const char* text);

	bool find(const char* pattern);

	void buildFailurePointer();

	void match(const char* text, PosSet* ret);

	void print(const char* text);

	void clear();
private:
	ACNode *root;		// ģʽ���ĸ����
	void clear_node(ACNode cur);
};

#endif //_ACMATCH_H