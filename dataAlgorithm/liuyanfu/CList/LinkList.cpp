#include "LinkList.h"

LinkList::LinkList(void)
{
	ListNode pNewNode = new SNode;
	pNewNode->pNext = NULL;
	m_pHead = pNewNode;
	m_pTail = pNewNode;
	m_ListLen = 0;
	m_pLoopPort = NULL;
	m_LoopPortPos = 0;
}


LinkList::~LinkList(void)
{
	Erase();
	delete m_pHead;
	m_pHead = m_pTail = NULL;
	//m_ListLen = 0;
	//m_pLoopPort = nullptr;
	//m_LoopPortPos = 0;
}

/****************************************!
*@brief  �������ͷ����������
*@author liuyanfu
*@date   2019��3��26��	21:43
*@param[out] 
*@param[in]  const int & data  
*@return     void  
****************************************/
void LinkList::AddHead(const int &data)
{
	ListNode pNewNode = new SNode;
	pNewNode->data= data;
	pNewNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNewNode;
	if(pNewNode->pNext == NULL)
		m_pTail = pNewNode;
	++m_ListLen;
	SetLoopPort();
}


/****************************************!
*@brief  �������β����������
*@author liuyanfu
*@date   2019��3��26��	22:35
*@param[out] 
*@param[in]  const int & data  
*@return     void  
****************************************/
void LinkList::AddTail(const int &data)
{
	ListNode pNewNode = new SNode;
	pNewNode->data = data;
	pNewNode->pNext = NULL;
	m_pTail->pNext = pNewNode;
	m_pTail = pNewNode;
	++m_ListLen;
	SetLoopPort();
}


/****************************************!
*@brief  �������ָ�����ǰ�����µ�����
*@author liuyanfu
*@date   2019��3��26��	23:10
*@param[out] 
*@param[in]  ListNode pos  
*@param[in]  const int & data  
*@return     bool 
****************************************/
bool LinkList::InsertAt(ListNode pos, const int &data)
{
	ListNode TempNode = m_pHead->pNext;
	ListNode prevNode = m_pHead;
	if(m_pLoopPort == NULL)
	{
		while(TempNode)
		{
			if(TempNode == pos)
			{
				ListNode pNewNode = new SNode;
				pNewNode->data = data;
				pNewNode->pNext = TempNode;
				prevNode->pNext = pNewNode;
				++m_ListLen;
				SetLoopPort();
				break;
			}
			prevNode = TempNode;
			TempNode = TempNode->pNext;
		}
		return TempNode == NULL ? false : true;
	}
	else
	{
		UINT nTimes = 1;
		UINT nFlag = 0;
		while(TempNode != m_pLoopPort || nTimes != 2)
		{
			if(TempNode == m_pLoopPort)
				nTimes = 2;
			if(TempNode == pos)
			{
				ListNode pNewNode = new SNode;
				pNewNode->data = data;
				pNewNode->pNext = TempNode;
				prevNode->pNext = pNewNode;
				++m_ListLen;
				SetLoopPort();
				nFlag = 1;
				break;
			}
			prevNode = TempNode;
			TempNode = TempNode->pNext;
		}
		return nFlag == 1 ? true : false;
	}
}

/****************************************!
*@brief  �޸�������ָ����������
*@author liuyanfu
*@date   2019��3��27��	21:16
*@param[out] 
*@param[in]  ListNode pos  
*@param[in]  const int & data  
*@return     bool  
****************************************/
bool LinkList::ModifyAt(ListNode pos, const int &data)
{
	ListNode TempNode = m_pHead->pNext;
	if(m_pLoopPort == NULL)
	{
		while(TempNode)
		{
			if(TempNode == pos)
			{
				TempNode->data = data;
				break;
			}
			TempNode = TempNode->pNext;
		}
		return TempNode == NULL ? false : true;
	}
	else
	{
		UINT nTimes = 1;
		UINT nFlag = 0;
		while(TempNode != m_pLoopPort || nTimes != 2)
		{
			if(TempNode == m_pLoopPort)
				nTimes = 2;
			if(TempNode == pos)
			{
				TempNode->data = data;
				nFlag = 1;
				break;
			}
			TempNode = TempNode->pNext;
		}
		return nFlag == 0 ? false :true;
	}
}



/****************************************!
*@brief  ɾ��������ָ�����
*@author liuyanfu
*@date   2019��3��27��	21:17
*@param[out] 
*@param[in]  ListNode pos  
*@return     bool  
****************************************/
bool LinkList::RemoveAt(ListNode pos)
{
	ListNode TempNode = m_pHead->pNext;
	ListNode prevNode = m_pHead;
	UINT nFlag = 0;
	if(m_pLoopPort == NULL)
	{
		while(TempNode)
		{
			if(TempNode == pos)
			{
				prevNode->pNext = TempNode->pNext;
				delete TempNode;
				TempNode = NULL;
				--m_ListLen;
				if(pos == m_pTail)
					m_pTail = prevNode;
				SetLoopPort();
				nFlag = 1;
				break;
			}
			prevNode = TempNode;
			TempNode = TempNode->pNext;
		}
	}
	else
	{
		UINT nTimes = 1;
		while(TempNode != m_pLoopPort || nTimes != 2)
		{
			if(TempNode ==m_pLoopPort)
				nTimes = 2;
			if(TempNode == pos)
			{
				prevNode->pNext = TempNode->pNext;
				delete TempNode;
				TempNode = NULL;
				--m_ListLen;
				if(pos == m_pTail)
					m_pTail = prevNode;
				SetLoopPort();
				nFlag = 1;
				break;
			}
			prevNode =TempNode;
			TempNode = TempNode->pNext;
		}
	}
	return nFlag == 0 ? false : true; 
}

//bool LinkList::RemoveAt(UINT nCountBack)
//{
//	return false;
//}



/****************************************!
*@brief  �ҵ������е�һ��������������ͬ�Ľ��
*@author liuyanfu
*@date   2019��3��27��	21:18
*@param[out] 
*@param[in]  const int & data  
*@return     ListNode  
****************************************/
ListNode LinkList::Find(const int &data)
{
	ListNode TempNode = m_pHead->pNext;
	if(m_pLoopPort == NULL)
	{
		while(TempNode)
		{
			if(TempNode->data == data)
				break;
			TempNode = TempNode->pNext;
		}
	}
	else
	{
		UINT nTimes = 1;
		UINT nFlag = 0;
		while(TempNode != m_pLoopPort || nTimes != 2)
		{
			if(TempNode == m_pLoopPort)
				nTimes = 2;
			if(TempNode->data == data)
				break;
			TempNode =TempNode->pNext;
		}
		if(TempNode == m_pLoopPort && nTimes == 2)
			TempNode = NULL;
	}
	return TempNode;
}

/****************************************!
*@brief  �������
*@author liuyanfu
*@date   2019��3��27��	21:19
*@param[out] 
*@return     void  
****************************************/
void LinkList::Erase()
{
	ListNode TempNode = m_pHead->pNext;
	ListNode prevNode = m_pHead;
	if(m_pLoopPort == NULL)
	{
		while(TempNode)
		{
			prevNode->pNext = TempNode->pNext;
			delete TempNode;
			TempNode = NULL;
			TempNode = TempNode->pNext;
		}
	}
	else
	{
		UINT nTimes = 1;
		while(TempNode != m_pLoopPort || nTimes != 2)
		{
			if(TempNode == m_pLoopPort)
				nTimes = 2;
			prevNode->pNext = TempNode->pNext;
			delete TempNode;
			TempNode = NULL;
			TempNode = prevNode->pNext;
		}
	}
	m_pTail = m_pHead;
	m_pHead->pNext = NULL;
	m_pLoopPort = NULL;
	m_LoopPortPos = 0;
	m_ListLen = 0;
}


/****************************************!
*@brief  ��ȡ������ָ���������ڵĽ��
*@author liuyanfu
*@date   2019��3��27��	21:19
*@param[out] 
*@param[in]  const int & data  
*@return     ListNode  
****************************************/
ListNode LinkList::GetNode(const int &data) const
{
	ListNode TempNode = m_pHead->pNext;
	if(m_pLoopPort == NULL)
	{
		while(TempNode)
		{
			if(TempNode->data == data)
				break;
			TempNode = TempNode->pNext;
		}
		return TempNode;
	}
	else
	{
		UINT nTimes = 1;
		UINT nFlag = 0;
		while(TempNode != m_pLoopPort || nTimes != 2)
		{
			if(TempNode == m_pLoopPort)
				nTimes = 2;
			if(TempNode->data == data)
			{
				nFlag = 1;
				break;
			}
			TempNode = TempNode->pNext;
		}
		if(TempNode == m_pLoopPort && nTimes == 2)
			TempNode = NULL;
	}
	return TempNode;

}

/****************************************!
*@brief  ��ӡ�����е���������
*@author liuyanfu
*@date   2019��3��27��	21:19
*@param[out] 
*@return     void  
****************************************/
void LinkList::PrintList() const
{
	ListNode TempNode =	m_pHead->pNext;
	UINT i = 1;
	if(m_pLoopPort == NULL)
	{
		while(TempNode)
		{
			std::cout << "The " << i << "th list node data is : " << TempNode->data << std::endl;
			++i;
			TempNode = TempNode->pNext;
		}
	}
	else
	{
		UINT nTimes = 1;
		while(TempNode != m_pLoopPort || nTimes != 2)
		{
			if(TempNode == m_pLoopPort)
				nTimes = 2;
			std::cout << "The " << i << "th list node data is : " << TempNode->data << std::endl;
			TempNode = TempNode->pNext;
		}
	}
}


//void LinkList::Reverse()
//{
//
//}


/****************************************!
*@brief  ���û�����������
*@author liuyanfu
*@date   2019��3��27��	21:20
*@param[out] 
*@return     void  
****************************************/
void LinkList::SetLoopPort()
{
	/*if(m_ListLen == m_LoopPortPos)
	{
		m_LoopPort = m_pTail;
		m_pTail->pNext = m_pTail;
	}
	else if(m_ListLen > m_LoopPortPos)
	{
		ListNode TempNode = FindByPos(m_LoopPortPos);
		m_pTail->pNext = TempNode;
	}
	else
		m_pTail->pNext = nullptr;*/
	ListNode TempNode = FindByPos(m_LoopPortPos);
	m_pLoopPort = TempNode;
	m_pTail->pNext = m_pLoopPort;
}


/****************************************!
*@brief  ͨ����Ų�����������Ӧλ�õĽ��
*@author liuyanfu
*@date   2019��3��27��	21:21
*@param[out] 
*@param[in]  UINT nNum  
*@return     ListNode  
****************************************/
ListNode LinkList::FindByPos(UINT nNum)
{
	if(nNum > m_ListLen || nNum == 0)
		return NULL;
	else
	{
		ListNode TempNode = m_pHead;
		UINT nCount = 0;
		while(nCount != nNum)
		{
			TempNode = TempNode->pNext;
			++nCount;
		}
		return TempNode;
	}
}

/****************************************!
*@brief  ���������м���
*@author liuyanfu
*@date   2019��3��27��	21:21
*@param[out] 
*@return     ListNode  
****************************************/
ListNode LinkList::GetMidNode()
{
	if(!m_ListLen)
		return NULL;
	ListNode fast = m_pHead;
	ListNode slow = m_pHead;
	if(m_pLoopPort == NULL)
	{
		while(fast && fast->pNext)
		{
			fast = fast->pNext->pNext;
			slow = slow->pNext;
		}
	}
	else
	{
		UINT nTimes = 1;
		while((fast != m_pLoopPort && fast->pNext != m_pLoopPort) || nTimes != 2)
		{
			if(fast == m_pLoopPort || fast->pNext == m_pLoopPort)
				nTimes = 2;
			fast = fast->pNext->pNext;
			slow = slow->pNext;
		}
	}
	return slow;
}
