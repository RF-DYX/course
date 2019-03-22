#ifndef _DULNODE_H
#define _DULNODE_H
#include<Windows.h>
#include<iostream>

struct DulNode
{
	int data;
	DulNode *pNext;
	DulNode *pPrev;
};
typedef unsigned int UINT;
typedef DulNode* DNode;		// ��ʾһ�����


class DulList
{
private:
	DNode m_pHead;
	DNode m_pTail;
	UINT m_nDulListLen;
public:
	DulList(void);
	~DulList(void);

	bool IsEmpty() const;	// �ж��Ƿ�Ϊ��

	UINT GetLength() const;	// ��ȡ��ǰ����ĳ���

	DNode GetHeadNode() const;	// ��ȡ�����ͷ���

	DNode GetTailNode() const;	// ��������β��� 

	DNode GetMidNode() const;		// ���������м���

	void AddHead(const int &data);	// �������ͷ�������µĽ��

	void AddTail(const int &data);	// �������β�������µĽ��

	DNode InsertAt(DNode pos, const int &data);	// ��ָ�����ǰ�������ݣ��������½��ĵ�ַ

	DNode ModifyAt(DNode pos, const int &data);	// �޸�ָ���������ݣ������ص�ǰ�ڵ�ĵ�ַ

	DNode RemoveAt(DNode pos);					// ɾ��ָ����㣬�����ر�ɾ��������һ���ĵ�ַ

	DNode RemoveAt(UINT nCountBack);				// ɾ��������n���ڵ㣬�����ر�ɾ��������һ���ĵ�ַ

	DNode Find(const int &data);	// �ڵ�ǰ�������ҵ���Ҫ����������ȵĵ�һ�����ĵ�ַ

	void Erase();					// ɾ����������н��

	void PrintList() const;			// ��ӡ�������н�������

	void Reverse();					// ��ת����
};

#endif
