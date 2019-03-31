#include "AStack.h"
#include <iostream>

template<typename T>
AStack<T>::AStack(void)
{
	m_nStackSize = 20;
	m_nStackLen = 0;
	m_pStack = new T[m_nStackSize];
	m_nTop = -1;
}

template<typename T>
AStack<T>::AStack(UINT &nSize):m_nStackSize(nSize)
{
	m_pStack = new T[m_nStackSize];
	m_nStackLen = 0;
	m_nTop = -1;
}

template<typename T>
AStack<T>::~AStack(void)
{
	delete [] m_pStack;
	m_pStack = NULL;
}

/****************************************!
*@brief  �ж�ջ�Ƿ�Ϊ��
*@author liuyanfu
*@date   2019��3��27��	23:25
*@param[out] 
*@return     bool  
****************************************/
template<typename T>
bool AStack<T>::Empty() const
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
template<typename T>
void AStack<T>::Clear()
{
	m_nStackLen = 0;
	m_nTop = -1;
}

/****************************************!
*@brief  ���ջ��������
*@author liuyanfu
*@date   2019��3��27��	23:29
*@param[out] 
*@return     const T* 
****************************************/
template<typename T>
const T* AStack<T>::GetTop() const
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
template<typename T>
UINT AStack<T>::GetLength() const
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
template<typename T>
void AStack<T>::Push(const T &data)
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
template<typename T>
void AStack<T>::Pop()
{
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
template<typename T>
void AStack<T>::ExpandStack()
{
	T *pTemp = new T[m_nStackSize * 2];
	memcpy(pTemp, m_pStack, sizeof(m_pStack));
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
template<typename T>
bool AStack<T>::isFull()
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
template<typename T>
void AStack<T>::PrintStack()
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