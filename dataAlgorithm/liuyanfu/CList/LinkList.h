#ifndef _LINKLIST_H
#define _LINKLIST_H


typedef struct SNode 
{
	int data;
	SNode *pNext;
}* ListNode;

typedef unsigned int UINT;

class LinkList
{
public:
	LinkList(void);
	~LinkList(void);

	bool Empty() const
	{
		return m_ListLen == 0;
	}

	UINT GetLength() const
	{
		return m_ListLen;
	}

	ListNode GetHeadNode() const
	{
		return m_pHead->pNext;
	}

	ListNode GetTailNode() const
	{
		return m_ListLen == 0 ? nullptr : m_pTail;
	}

	ListNode GetMidNode();

	void AddHead(const int &data);//�������ͷ�������µĽ��
	void AddTail(const int &data);//�������β�������µĽ��

	bool InsertAt(ListNode pos, const int &data);//��ָ�����ǰ�������ݣ��������½��ĵ�ַ
	bool ModifyAt(ListNode pos, const int &data);//�޸�ָ���������ݣ������ص�ǰ�ڵ�ĵ�ַ
	bool RemoveAt(ListNode pos);//ɾ��ָ����㣬�����ر�ɾ��������һ���ĵ�ַ
	//bool RemoveAt(UINT nCountBack);//ɾ��������n���ڵ㣬�����ر�ɾ��������һ���ĵ�ַ

	ListNode Find(const int &data);//�ڵ�ǰ�������ҵ���Ҫ����������ȵĵ�һ�����ĵ�ַ
	ListNode GetNode(const int &data) const;//��ȡĳһ�����������������Ľ���ַ
	void Erase();//ɾ����������н��

	void PrintList() const;//��ӡ�������н�������
	//void Reverse();//��ת����

	void SetLoopPortPos(const UINT &pos) //��pos = 0ʱ���������û�л�����ڣ���Ϊ��ͨ�ĵ�����
	{
		m_LoopPortPos = pos;
	}
private:
	void SetLoopPort();
	ListNode FindByPos(UINT nNum);

	UINT m_ListLen;
	UINT m_LoopPortPos;
	ListNode m_pHead;
	ListNode m_pTail;
	ListNode m_pLoopPort;
};

#endif