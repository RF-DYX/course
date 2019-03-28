#include "AStack.h"
#include <iostream>
#include <string.h>

AStack::AStack(void)
{
	m_nStackSize = 20;
	m_nStackLen = 0;
	m_pStack = new int[m_nStackSize];
	memset(m_pStack, 0, sizeof(int)* m_nStackSize);
	m_nTop = -1;
}

AStack::AStack(UINT &nSize):m_nStackSize(nSize)
{
	m_pStack = new int[m_nStackSize];
	m_nStackLen = 0;
	memset(m_pStack, 0, sizeof(int)* m_nStackSize);
	m_nTop = -1;
}

AStack::~AStack(void)
{
	delete [] m_pStack;
	m_pStack = NULL;
	m_nStackSize = 0;
	m_nStackLen = 0;
	m_nTop = 0;
}

/****************************************!
*@brief  �ж�ջ�Ƿ�Ϊ��
*@author liuyanfu
*@date   2019��3��27��	23:25
*@param[out] 
*@return     bool  
****************************************/
bool AStack::Empty() const
{
	return m_nStackLen == 0;
}


/****************************************!
*@brief  ���ջ
*@author liuyanfu
*@date   2019��3��27��	23:26
*@param[out] 
*@return     void  
****************************************/
void AStack::Clear()
{
	memset(m_pStack, 0, sizeof(int) * m_nStackLen);
	m_nStackLen = 0;
	m_nTop = -1;
}

/****************************************!
*@brief  ���ջ��������
*@author liuyanfu
*@date   2019��3��27��	23:29
*@param[out] 
*@return     const int*  
****************************************/
const int* AStack::GetTop() const
{
	if(-1 == m_nTop)
		return NULL;
	return &m_pStack[m_nTop];
}


/****************************************!
*@brief  ����ջ����Ч������ռ�õĳ���
*@author liuyanfu
*@date   2019��3��27��	23:42
*@param[out] 
*@return     UINT  
****************************************/
UINT AStack::GetLength() const
{
	return m_nStackLen;
}


/****************************************!
*@brief  ѹջ
*@author liuyanfu
*@date   2019��3��27��	23:43
*@param[out] 
*@param[in]  const UINT &data  
*@return     void  
****************************************/
void AStack::Push(const UINT &data)
{
	if(isFull())
		ExpandStack();
	m_pStack[++m_nTop] = data;
	++m_nStackLen;
}


/****************************************!
*@brief  ��ջ
*@author liuyanfu
*@date   2019��3��27��	23:47
*@param[out] 
*@return     void  
****************************************/
void AStack::Pop()
{
	memset(&m_pStack[m_nTop], 0, sizeof(int));
	--m_nTop;
	--m_nStackLen;
}


/****************************************!
*@brief  ջ�Ķ�̬����
*@author liuyanfu
*@date   2019��3��27��	23:51
*@param[out] 
*@return     void  
****************************************/
void AStack::ExpandStack()
{
	int *pTemp = new int[m_nStackSize * 2];
	memcpy(pTemp, m_pStack, m_nStackLen * sizeof(int));
	delete []m_pStack;
	m_pStack = pTemp;
	m_nStackSize = m_nStackSize * 2;
}


/****************************************!
*@brief  �жϵ�ǰջ�Ƿ�����
*@author liuyanfu
*@date   2019��3��27��	23:56
*@param[out] 
*@return     bool  
****************************************/
bool AStack::isFull()
{
	return m_nStackLen == m_nStackSize;
}


/****************************************!
*@brief  ��ӡջ�е�����
*@author liuyanfu
*@date   2019��3��28��	0:00
*@param[out] 
*@return     void  
****************************************/
void AStack::PrintStack()
{
	if(Empty())
	{
		std::cout << "Current Stack is Empty!" << std::endl;
		return;
	}
	UINT i = 1;
	std::cout << "The data from stack top to stack buttom is :" << std::endl;
	int index = m_nTop;
	while(index != -1)
	{
		std::cout << "The " << i << "th node data is : " << m_pStack[index--] << std::endl;
		++i;
	}
	std::cout << "----------------Print Stack data is over-------------" << std::endl;
}
