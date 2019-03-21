#ifndef _SINGLELIST_H
#define _SINGLELIST_H
#include<Windows.h>
#include<iostream>

struct SNode		//���Ļ�����������
{
	int data;
	SNode* pNext;
};

typedef unsigned int UINT;
typedef SNode* ListNode;		// ��ʾһ�����

class SingleList
{

public:
 	SingleList(void);
 	~SingleList(void);

	bool IsEmpty() const;//�ж������Ƿ�Ϊ��

	UINT GetLength() const;//��ȡ��ǰ����ĳ���

	ListNode GetHeadNode() const;//��ȡ�����ͷ���

	ListNode GetTailNode() const;//��ȡ�����β���

	ListNode GetMidNode();//���������м���

	void AddHead(const int &data);//�������ͷ�������µĽ��

	void AddTail(const int &data);//�������β�������µĽ��

	ListNode InsertAt(ListNode pos, const int &data);//��ָ�����ǰ�������ݣ��������½��ĵ�ַ

	ListNode ModifyAt(ListNode pos, const int &data);//�޸�ָ���������ݣ������ص�ǰ�ڵ�ĵ�ַ

	ListNode RemoveAt(ListNode pos);//ɾ��ָ����㣬�����ر�ɾ��������һ���ĵ�ַ

	ListNode RemoveAt(UINT nCountBack);//ɾ��������n���ڵ㣬�����ر�ɾ��������һ���ĵ�ַ

	ListNode Find(const int &data);//�ڵ�ǰ�������ҵ���Ҫ����������ȵĵ�һ�����ĵ�ַ

	void Erase();//ɾ����������н��

	//ListNode GetNode(const int &data) const;//��ȡĳһ�����������������Ľ���ַ

	void PrintList() const;//��ӡ�������н�������
	void Reverse();//��ת����
	
private:
	ListNode m_pHead;
	ListNode m_pTail;
	UINT m_nListLen;
};


#endif

