/*
* Copyright: (c) 2019
*
* �ļ�����:  SkipList.h	
* �ļ���ʶ��
* ժ	Ҫ�� �����һ��ģ��ʵ�ַ����������д洢����ģ�����ͣ����Ҵ洢���ǲ��ظ���
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/5/14  8:51
*/

#ifndef _SKIPLIST_H
#define _SKIPLIST_H

#include <iostream>
#define MAX_LEVEL 16

template<typename T>
class SNode
{
	typedef SNode<T>* pSNode;
public:
	SNode()
	{
		maxLevel = 0;
		forward = new pSNode[MAX_LEVEL];
		for(int i = 0; i < MAX_LEVEL; ++i)
		{
			forward[i] = NULL;
		}
	}
	~SNode()
	{
		delete []forward;
		forward = NULL;
	}
	T data;
	int maxLevel;
	pSNode *forward;
};

template<typename T>
class SkipList
{
	typedef SNode<T>* pSNode;
public:
	SkipList(void);
	~SkipList(void);

	void Insert(const T value);
	void Delete(const T value);
	pSNode Find(const T value);
	void printAll();
private:
	int randomLevel();
	void InitArr(pSNode*, int);
	void clear();
	int getRandom();
private:
	int levelCount;
	pSNode head;
};
#endif //_SKIPLIST_H
