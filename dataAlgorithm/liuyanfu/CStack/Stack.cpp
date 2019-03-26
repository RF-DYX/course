#include "Stack.h"
#include <iostream>

CStack::CStack(void)
{
	m_pTop = nullptr;
	m_nStackLen = 0;
}


CStack::~CStack(void)
{
	Clear();
	m_pTop = nullptr;
	m_nStackLen = 0;
}

/****************************************!
*@brief  �ж�ջ�Ƿ�Ϊ
*@author liuyanfu
*@date   2019��3��25��	22:33
*@param[out] 
*@return     bool  
****************************************/
bool CStack::Empty() const
{
	return m_pTop == nullptr;
}


/****************************************!
*@brief  ��ȡջ�����
*@author liuyanfu
*@date   2019��3��25��	22:34
*@param[out] 
*@return     StackNode  
****************************************/
StackNode CStack::GetTop() const
{
	return m_pTop;
}


/****************************************!
*@brief  ��ȡջ�����ݵĸ���
*@author liuyanfu
*@date   2019��3��25��	22:36
*@param[out] 
*@return     UINT  
****************************************/
UINT CStack::GetLength() const
{
	return m_nStackLen;
}


/****************************************!
*@brief  ѹջ
*@author liuyanfu
*@date   2019��3��25��	22:38
*@param[out] 
*@param[in]  int & data  
*@return     void  
****************************************/
void CStack::Push(const int &data)
{
	StackNode pNewNode = new SNode;
	pNewNode->data = data;
	if(m_pTop == nullptr)
	{
		pNewNode->pNext = nullptr;
	}
	else
	{
		pNewNode->pNext = m_pTop;
	}
	m_pTop = pNewNode;
	++m_nStackLen;
}



/****************************************!
*@brief  ��ջ
*@author liuyanfu
*@date   2019��3��25��	22:39
*@param[out] 
*@return     void  
****************************************/
void CStack::Pop()
{
	if(m_pTop != nullptr)
	{
		StackNode TempNode = m_pTop->pNext;
		delete m_pTop;
		m_pTop = nullptr;
		m_pTop = TempNode;
		--m_nStackLen;
	}
}


void CStack::Clear()
{
	if(m_pTop != nullptr)
	{
		StackNode TempNode = m_pTop;
		while(TempNode)
		{
			TempNode = TempNode->pNext;
			delete m_pTop;
			m_pTop = nullptr;
			m_pTop = TempNode;
			--m_nStackLen;
		}
	}
}


/****************************************!
*@brief  ��ӡջ������
*@author liuyanfu
*@date   2019��3��25��	22:51
*@param[out] 
*@return     void  
****************************************/
void CStack::Print() const
{
	UINT i = 1;
	StackNode TempNode = m_pTop;
	while(TempNode)
	{
		std::cout << "The " << i << "th stack node data is " << TempNode->data << std::endl;
		++i;
		TempNode = TempNode->pNext;
	}
}