#include "DulNode.h"
DulList::DulList(void):m_pHead(nullptr), m_pTail(nullptr), m_nDulListLen(0)
{
	m_pHead = m_pTail;
}
DulList::~DulList(void)
{
	Erase();
}
// �ж��Ƿ�Ϊ��
bool DulList::IsEmpty() const
{
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
		return true;
	else
		return false;
}
// ��ȡ��ǰ����ĳ���
UINT DulList::GetLength() const
{
	return m_nDulListLen;
}
// ��ȡ�����ͷ���
DNode DulList::GetHeadNode() const
{
	return m_pHead;
}
// ��������β���
DNode DulList::GetTailNode() const
{
	return m_pTail;
}
// ���������м���
DNode DulList::GetMidNode() const
{
	/*if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
		return NULL;
	int mid = m_nDulListLen / 2;
	int remainder = m_nDulListLen % 2;
	DNode temp;
	temp = m_pHead;
	if(remainder == 1)
	{
		while(mid)
		{
			temp = temp->pNext;
			--mid;
		}
		return temp;
	}
	else
	{
		--mid;
		while(mid)
		{
			temp = temp->pNext;
			--mid;
		}
		return temp;
	}	*/
	
	DNode fast = m_pHead;
	DNode slow = m_pHead;
	while(fast)
	{
		fast = fast->pNext;
		if(fast != NULL)
		{
			fast = fast->pNext->pNext;
			slow = slow->pNext;
		}
		return slow;
	}
	return NULL;
}
// �������ͷ�������µĽ��
void DulList::AddHead(const int &data)
{
	DNode newNode = new DulNode;
	newNode->data = data;
	newNode->pNext = NULL;
	newNode->pPrev = NULL;
	if(m_pHead == NULL)
	{
		m_pHead = newNode;
		m_pTail = newNode;
		++m_nDulListLen;
	}
	else
	{
		newNode->pNext = m_pHead;
		m_pHead->pPrev = newNode;
		m_pHead = newNode;
		++m_nDulListLen;
		return;
	}
}
// �������β�������µĽ��
void DulList::AddTail(const int &data)
{
	DNode newNode = new DulNode;
	newNode->data = data;
	newNode->pNext = NULL;
	newNode->pPrev = NULL;
	if(NULL == m_pHead)
	{
		m_pHead = newNode;
		m_pTail = newNode;
		++m_nDulListLen;
	}
	else
	{
		newNode->pPrev = m_pTail;
		m_pTail->pNext = newNode;
		m_pTail = newNode;
		++m_nDulListLen;
	}
}
// ��ָ�����ǰ�������ݣ��������½��ĵ�ַ
DNode DulList::InsertAt(DNode pos, const int &data)
{
	DNode p = m_pHead;
	if(NULL == pos)
	{
		return NULL;
	}
	else if(p == pos)
	{
		AddHead(data);
		return m_pHead;
	}
	else
	{
		while(p)
		{
			if(p->pNext == pos)
			{
				DNode newNode = new DulNode;
				newNode->data = data;
				newNode->pNext = NULL;
				newNode->pPrev = NULL;
				newNode->pNext = p->pNext;
				newNode->pPrev = p;
				pos->pPrev = newNode;
				p->pNext = newNode;
				++m_nDulListLen;
				return newNode;
			}
			p = p->pNext;
		}
	}
	return NULL;
}
// �޸�ָ���������ݣ������ص�ǰ�ڵ�ĵ�ַ
DNode DulList::ModifyAt(DNode pos, const int &data)
{
	DNode p;
	p = m_pHead;
	if(pos == NULL || m_pHead == NULL)
	{
		return NULL;
	}
	else
	{
		while(p)
		{
			if(p == pos)
			{
				p->data = data;
				return p;
			}
			p = p->pNext;
		}
	}
	return NULL;
}
// ɾ��ָ����㣬�����ر�ɾ��������һ���ĵ�ַ
DNode DulList::RemoveAt(DNode pos)
{
	if(pos == NULL || m_pHead == NULL)
	{	
		return NULL;
	}
	else
	{
		DNode p;
		p = m_pHead;
		while(p)
		{
			if(p == pos)
			{
				p->pPrev->pNext = pos->pNext;
				p->pNext->pPrev = pos->pPrev;
				p = p->pNext;
				return p;
				p = nullptr;
				--m_nDulListLen;
				return p;
			}
			p = p->pNext;
		}
	}
	
	return NULL;
}
// ɾ��������n���ڵ㣬�����ر�ɾ��������һ���ĵ�ַ
DNode DulList::RemoveAt(UINT nCountBack)
{
	if(nCountBack > m_nDulListLen || m_pHead == NULL || m_nDulListLen <= 0)
	{	
		return NULL;
	}
	else
	{
		UINT n = m_nDulListLen - nCountBack;
		DNode p, q;
		p = m_pHead;
		q = m_pHead->pNext;
		while(n)
		{
			p = p->pNext;
			q = q->pNext;
			--n;
		}
		q->pPrev = p->pPrev;
		p->pPrev->pNext = q;
		delete p;
		p = nullptr;
		--m_nDulListLen;
		return q;		
	}	
	return NULL;
}
// �ڵ�ǰ�������ҵ���Ҫ����������ȵĵ�һ�����ĵ�ַ
DNode DulList::Find(const int &data) const
{
	if(m_nDulListLen == 0)
	{	
		return NULL;
	}
	else
	{
		DNode p;
		p = m_pHead;
		while(p)
		{
			if(p->data == data)
				return p;
			p = p->pNext;
		}
	}
	return NULL;
}
// ɾ����������н��
void DulList::Erase()
{
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
	{	
		return;
	}
	else
	{
		DNode p;
		while(m_pHead)
		{
			p = m_pHead->pNext;
			delete m_pHead;
			m_pHead = nullptr;
			m_pHead = p;
		}
		m_nDulListLen = 0;
	}
	return;
}
// ��ӡ�������н�������
void DulList::PrintList() const
{
	if(m_pHead == NULL)
		return;
	else
	{
		DNode p;
		p = m_pHead;
		int index = 1;
		while(p)
		{
			std::cout <<"�� " << index << " ����㣺" << p->data << std::endl;
			p = p->pNext;
			++index;
		}
		std::cout << "DulList's length is: " << m_nDulListLen << std::endl;
	}
	return;
}
// ��ת����
void DulList::Reverse()
{
	if(m_nDulListLen == 0 || m_nDulListLen == 1)
	{	
		return;
	}
	else if(m_nDulListLen == 2)
	{
		DNode p;
		p = m_pHead;
		m_pHead = m_pTail;
		m_pTail = p;
		return;
	}
	else
	{	
		DNode p = NULL;
		DNode q = NULL;
		DNode r = m_pHead;
		while(m_pHead)
		{
			p = m_pHead->pNext;
			m_pHead->pNext = q;
			m_pHead->pPrev = p;
			q = m_pHead;
			if(NULL == p)		// ������Ӵ���䣬�������NULL��������
				break;
			m_pHead = p;
		}
		m_pTail = r;
		return;
	}
}