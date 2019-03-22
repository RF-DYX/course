#include "DulNode.h"
DulList::DulList(void)
{
	m_pHead = m_pTail = NULL;
	m_nDulListLen = 0;
}
DulList::~DulList(void)
{
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
		return;

	DNode p;
	while(m_pHead)
	{
		p = m_pHead->pNext;
		delete m_pHead;
		m_pHead = p;
	}
	m_nDulListLen = 0;
	return;
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
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
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
	}	
}
// �������ͷ�������µĽ��
void DulList::AddHead(const int &data)
{
	DNode newNode = new DulNode;
	newNode->data = data;
	newNode->pNext = NULL;
	newNode->pPrev = NULL;
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
	{
		m_pHead = newNode;
		m_pTail = newNode;
		++m_nDulListLen;
		return;
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
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
	{
		m_pHead = newNode;
		m_pTail = newNode;
		++m_nDulListLen;
		return;
	}
	else
	{
		m_pTail->pNext = newNode;
		newNode->pPrev = m_pTail;
		m_pTail = newNode;
		++m_nDulListLen;
		return;
	}
}
// ��ָ�����ǰ�������ݣ��������½��ĵ�ַ
DNode DulList::InsertAt(DNode pos, const int &data)
{
	if(pos == NULL)
		return NULL;
	DNode newNode = new DulNode;
	newNode->data = data;
	newNode->pNext = NULL;
	newNode->pPrev = NULL;
	DNode p;
	p = m_pHead;
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
	{
		m_pTail = newNode;
		m_pHead = newNode;
		++m_nDulListLen;
		return m_pHead;
	}
	else
	{
		while(p)
		{
			if(p->pNext == pos)
			{
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
	if(pos == NULL)
		return NULL;
	DNode p;
	p = m_pHead;
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
	{
		return m_pHead;
	}
	else
	{
		while(p)
		{
			if(p->pNext == pos)
			{
				pos->data = data;
				return pos;
			}
			p = p->pNext;
		}
	}
	return NULL;
}
// ɾ��ָ����㣬�����ر�ɾ��������һ���ĵ�ַ
DNode DulList::RemoveAt(DNode pos)
{
	if(pos == NULL)
		return NULL;
	if(m_pHead == NULL ||m_pTail == NULL || m_nDulListLen == 0)
		return NULL;
	if(m_pHead == m_pTail && m_pHead != NULL)
	{
		if(pos == m_pTail)
		{
			m_pHead = NULL;
			m_pTail = NULL;
			return NULL;
		}
		else
		{
			return NULL;
		}
	}
	DNode p;
	p = m_pHead;
	while(p)
	{
		if(p->pNext == pos)
		{
			p->pNext = pos->pNext;
			pos->pPrev->pPrev = p;
			p = p->pNext;
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}
// ɾ��������n���ڵ㣬�����ر�ɾ��������һ���ĵ�ַ
DNode DulList::RemoveAt(UINT nCountBack)
{
	if(nCountBack > m_nDulListLen )
		return NULL;
	if(m_pHead == NULL ||m_pTail == NULL || m_nDulListLen == 0)
		return NULL;
	if(m_pHead == m_pTail && m_pHead != NULL)
	{
		m_pHead = NULL;
		m_pTail = NULL;
		--m_nDulListLen;
		return NULL;
	}
	UINT n = m_nDulListLen - nCountBack;
	DNode p;
	p = m_pHead;
	DNode q;
	if(n == 0)
	{
		p = p->pNext;
		p->pPrev = NULL;
		delete m_pHead;
		m_pHead = p;
		return m_pHead;
	}
	else
	{
		while(n)
		{
			p = p->pNext;
			--n;
		}
		q = p;
		p->pNext->pPrev = q->pPrev;
		p->pPrev->pNext = q->pNext;
		--m_nDulListLen;
		q = q->pNext;
		delete p;
		return q;		
	}
	return NULL;
}
// �ڵ�ǰ�������ҵ���Ҫ����������ȵĵ�һ�����ĵ�ַ
DNode DulList::Find(const int &data)
{
	if(m_nDulListLen == 0)
		return NULL;
	
	DNode p;
	p = m_pHead;
	while(p)
	{
		if(p->data == data)
			return p;
		p = p->pNext;
	}
	return NULL;
}
// ɾ����������н��
void DulList::Erase()
{
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
		return;

	DNode p;
	while(m_pHead)
	{
		p = m_pHead->pNext;
		delete m_pHead;
		m_pHead = p;
	}
	m_nDulListLen = 0;
	return;
}
// ��ӡ�������н�������
void DulList::PrintList() const
{
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
		return;
	DNode p;
	p = m_pHead;
	while(p)
	{
		std::cout << p->data << std::endl;
		p = p->pNext;
	}
	std::cout << "DulList's length is " << m_nDulListLen << std::endl;
	return;
}
// ��ת����
void DulList::Reverse()
{
	if(m_nDulListLen == 0)
		return;
	if(m_nDulListLen == 1)
		return;
	if(m_nDulListLen == 2)
	{
		DNode p;
		p = m_pHead;
		m_pHead = m_pTail;
		m_pTail = p;
		return;
	}
	else
	{	
		DNode q = NULL;
		DNode p = NULL;
		DNode r = m_pHead;
		while(m_pHead)
		{
			p = m_pHead->pNext;
			
			m_pHead->pNext = q;
			m_pHead->pPrev = p;
			q = m_pHead;
			if(p == NULL)		// ������Ӵ���䣬�������NULL��������
				break;
			m_pHead = p;
		}
		m_pTail = r;
		return;
	}
}