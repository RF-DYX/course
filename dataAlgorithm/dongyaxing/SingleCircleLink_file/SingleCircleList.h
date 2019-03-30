#ifndef _SINGLECIRCLELIST_H
#define _SINGLECIRCLELIST_H
#include<Windows.h>
#include<iostream>

struct SCNode
{
	int data;
	SCNode *pNext;
};
typedef SCNode * SCLNode;
typedef unsigned int UINT;
class SingleCircleList
{
public:
	SingleCircleList(void);
	~SingleCircleList(void);
	bool IsEmpty() const;//�ж������Ƿ�Ϊ��

	UINT GetLength() const;//��ȡ��ǰ����ĳ���

	SCLNode GetHeadNode() const;//��ȡ�����ͷ���

	SCLNode GetTailNode() const;//��ȡ�����β���

	SCLNode GetMidNode();//���������м���

	void AddHead(const int &data);//�������ͷ�������µĽ��

	void AddTail(const int &data);//�������β�������µĽ��

	SCLNode InsertAt(SCLNode pos, const int &data);//��ָ�����ǰ�������ݣ��������½��ĵ�ַ

	SCLNode ModifyAt(SCLNode pos, const int &data);//�޸�ָ���������ݣ������ص�ǰ�ڵ�ĵ�ַ

	SCLNode RemoveAt(SCLNode pos);//ɾ��ָ����㣬�����ر�ɾ��������һ���ĵ�ַ

	SCLNode RemoveAt(UINT nCountBack);//ɾ��������n���ڵ㣬�����ر�ɾ��������һ���ĵ�ַ

	SCLNode Find(const int &data);//�ڵ�ǰ�������ҵ���Ҫ����������ȵĵ�һ�����ĵ�ַ

	void Erase();//ɾ����������н��

	//ListNode GetNode(const int &data) const;//��ȡĳһ�����������������Ľ���ַ

	void PrintList() const;//��ӡ�������н�������
	void Reverse();//��ת����

private:
	SCLNode m_pHead;
	SCLNode m_pTail;
	UINT m_nSCListLen;
};


#endif