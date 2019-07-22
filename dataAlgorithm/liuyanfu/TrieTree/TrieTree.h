/*
* Copyright: (c) 2019
*
* �ļ�����:  TrieTree.h	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/7/5  8:32
*/

#ifndef _TRIETREE_H
#define _TRIETREE_H
#include <string.h>

class TrieNode
{
public:
	TrieNode():nodeNum(0)
	{
		isEndingChar = false;
		memset(children, 0, sizeof(children));
	}
	~TrieNode()
	{
	}
	TrieNode(const char ch):nodeNum(0)
	{
		data = ch;
		isEndingChar = false;
		memset(children, 0, sizeof(children));
	}
	char data;
	bool isEndingChar;
	int nodeNum;
	TrieNode* children[26];	
};


class TrieTree
{
public:
	TrieTree(void);
	~TrieTree(void);
	template<typename Iterator>
	void insert(Iterator begin, Iterator end);
	template<typename Iterator>
	bool find(Iterator begin, iterator end);
	void insert(const char* text);
	bool find(const char* word);
	void clear();
private:
	void clear_node(TrieNode cur);
	TrieNode* root;
};

#endif // _TRIETREE_H