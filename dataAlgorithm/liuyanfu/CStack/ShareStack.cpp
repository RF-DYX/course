#include "ShareStack.h"
#include <string.h>
#define INITSTACKLEN 5

template<typename DATA>
ShareStack<DATA>::ShareStack(void)
{
	m_pStack = new DATA[INITSTACKLEN];
	m_nStackSize = INITSTACKLEN;
	m_nTop1 = -1;
	m_nTop2 = m_nStackSize;
	m_nStackLen = 0;
}


template<typename DATA>
ShareStack<DATA>::ShareStack(const UINT& nStackSize)
{
	m_pStack = new DATA[nStackSize];
	m_nStackSize = nStackSize;
	m_nTop1 = -1;
	m_nTop2 = nStackSize;
	m_nStackLen = 0;
}

template<typename DATA>
ShareStack<DATA>::~ShareStack(void)
{
	delete []m_pStack;
	m_pStack = NULL;
}



/****************************************!
*@brief  �жϹ���ջ�Ƿ�Ϊ��
*@author liuyanfu
*@date   2019��3��29��	21:05
*@param[out] 
*@return     bool  
****************************************/
template<typename DATA>
bool ShareStack<DATA>::Empty() const
{
	return m_nStackLen == 0;
}


/****************************************!
*@brief  ��չ���ջ
*@author liuyanfu
*@date   2019��3��29��	21:05
*@param[out] 
*@return     void  
****************************************/
template<typename DATA>
void ShareStack<DATA>::Clear()
{
	m_nStackLen = 0;
	m_nTop1 = -1;
	m_nTop2 = m_nStackSize;
}


/****************************************!
*@brief  ��ȡ���ջ��ջ��ָ��
*@author liuyanfu
*@date   2019��3��29��	21:18
*@param[out] 
*@return     const DATA*  
****************************************/
template<typename DATA>
const DATA* ShareStack<DATA>::GetLeftStackTop() const
{
	if(-1 == m_nTop1)
		return NULL;
	return &m_pStack[m_nTop1];
}


/****************************************!
*@brief  ��ȡջ����Ч����ռ�õĳ���
*@author liuyanfu
*@date   2019��3��29��	21:19
*@param[out] 
*@return     UINT  
****************************************/
template<typename DATA>
UINT ShareStack<DATA>::GetLength() const
{
	return m_nStackLen;
}


/****************************************!
*@brief  ���ջ��ջ
*@author liuyanfu
*@date   2019��3��29��	21:24
*@param[out] 
*@param[in]  const DATA & data  
*@return     void  
****************************************/
template<typename DATA>
void ShareStack<DATA>::LeftStackPush(const DATA&data)
{
	if(IsFull())
		Expand();
	m_pStack[++m_nTop1] = data;
	++m_nStackLen;
}


/****************************************!
*@brief  
*@author liuyanfu
*@date   2019��3��29��	21:32
*@param[out] 
*@return     void  
****************************************/
template<typename DATA> 
void ShareStack<DATA>::LeftStackPop()
{
	if(-1 != m_nTop1)
	{
		--m_nTop1;
		--m_nStackLen;
	}
}

template<typename DATA>
bool ShareStack<DATA>::IsFull()
{
	return m_nTop1 + 1 == m_nTop2;
}


template<typename DATA>
void ShareStack<DATA>::Expand()
{
	int *pTemp = new int[m_nStackSize * 2];
	memcpy(pTemp, m_pStack, sizeof(DATA)*(m_nTop1 + 1));
	memcpy(&pTemp[m_nStackSize*2 -1] - (m_nStackSize - m_nTop2 - 1), 
		&m_pStack[m_nTop2], sizeof(DATA)* (m_nStackSize - m_nTop2));
	delete []m_pStack;
	m_pStack = pTemp;
	m_nStackSize = m_nStackSize * 2;
	m_nTop2 += m_nStackSize/2;
	
}

/****************************************!
*@brief  ��ȡ�ұ�ջ��ջ��ָ��
*@author liuyanfu
*@date   2019��3��29��	21:55
*@param[out] 
*@return     const DATA*  
****************************************/
template<typename DATA>
const DATA* ShareStack<DATA>::GetRightStackTop() const
{
	if(m_nStackSize == m_nTop2)
		return NULL;
	return &m_pStack[m_nTop2];
}


/****************************************!
*@brief  �ұ�ջѹջ
*@author liuyanfu
*@date   2019��3��29��	21:55
*@param[out] 
*@param[in]  const DATA & data  
*@return     void  
****************************************/
template<typename DATA>
void ShareStack<DATA>::RightStackPush(const DATA& data)
{
	if(IsFull())
		Expand();
	m_pStack[--m_nTop2] = data;
	++m_nStackLen;
}



/****************************************!
*@brief  �ұ�ջ��ջ
*@author liuyanfu
*@date   2019��3��29��	21:57
*@param[out] 
*@return     void  
****************************************/
template<typename DATA>
void ShareStack<DATA>::RigthStackPop()
{
	if(m_nStackSize != m_nTop2)
	{
		++m_nTop2;
		--m_nStackLen;
	}
}

/****************************************!
*@brief  ��ӡջ�е�����
*@author liuyanfu
*@date   2019��3��29��	22:55
*@param[out] 
*@return     void  
****************************************/
template<typename DATA>
void ShareStack<DATA>::PrintStack() const
{
	if(-1 != m_nTop1)
	{
		std::cout << "LeftStack context " << std::endl;
		int index = m_nTop1;
		while(index >= 0)
		{
			std::cout << "the " << index << "th elem data is " << m_pStack[index] << std::endl;
			--index;
		}
	}
	if(m_nStackSize != m_nTop2)
	{
		std::cout << "RightStack context " << std::endl;
		int index = m_nTop2;
		while(index != m_nStackSize)
		{
			std::cout << "the " << index << "th elem data is " << m_pStack[index] << std::endl;
			++index;
		}
	}
	if(-1 == m_nTop1 && m_nStackSize == m_nTop2)
	{
		std::cout << "Current stack is Empty!" << std::endl;
	}
}
