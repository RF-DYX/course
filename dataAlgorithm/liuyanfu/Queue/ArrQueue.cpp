#include "ArrQueue.h"
#include <string.h>
#define INITQUEUELEN 5


template<typename T>
ArrQueue<T>::ArrQueue(void)
{
	m_nQueueSize = INITQUEUELEN;
	m_pQueue = new T[m_nQueueSize];
	m_nHead =  -1;
	m_nTail = 0;
	m_nQueueLen = 0;
	
}


template<typename T>
ArrQueue<T>::ArrQueue(const UINT& InitSize):m_nQueueSize(InitSize)
{
	m_pQueue = new T[m_nQueueSize];
	m_nHead  = -1;
	m_nTail = 0;
	m_nQueueLen = 0;
}

template<typename T>
ArrQueue<T>::~ArrQueue(void)
{
	delete [] m_pQueue;
	m_pQueue = NULL;
}



/****************************************!
*@brief  ���
*@author liuyanfu
*@date   2019��4��1��	21:12
*@param[out] 
*@param[in]  const T & data  
*@return     bool  
****************************************/
template<typename T>
bool ArrQueue<T>::enqueue(const T& data)
{
	if(!m_pQueue || (m_nTail == m_nQueueSize && m_nHead == 0)) //����������˻��߿ռ�ĵ�ַ��Ч
		return false;
	else if(m_nTail <  m_nQueueSize)
	{
		m_pQueue[m_nTail++] = data;
		if(++m_nQueueLen == 1)
		{
			m_nHead = 0;
		}
		return true;
	}
	else
	{
		//memcpy(m_pQueue, &m_pQueue[m_nHead], sizeof(T) * m_nQueueLen);//Ŀ��λ����Դλ�ô����ص�
		for(UINT i = 0; i < m_nQueueLen; ++i)
		{
			m_pQueue[i] = m_pQueue[m_nHead++];
		}
		m_nHead = 0;
		m_pQueue[m_nQueueLen++] = data;
		m_nTail = m_nQueueLen;
		return true;
	}
}


/****************************************!
*@brief  ����
*@author liuyanfu
*@date   2019��4��1��	21:17
*@param[out] 
*@return     bool  
****************************************/
template<typename T>
bool ArrQueue<T>::dequeue()
{
	if(m_nQueueLen == 0) //����Ϊ��ʱ
		return false;
	else
	{
		m_nHead += 1;
		--m_nQueueLen;
		return true;
	}
}


/****************************************!
*@brief  ��ȡ������Ч����
*@author liuyanfu
*@date   2019��4��1��	21:31
*@param[out] 
*@return     UINT  
****************************************/
template<typename T>
UINT ArrQueue<T>::getlength() const
{
	return m_nQueueLen;
}


/****************************************!
*@brief  �ж϶����Ƿ�Ϊ��
*@author liuyanfu
*@date   2019��4��1��	21:32
*@param[out] 
*@return     bool  
****************************************/
template<typename T>
bool ArrQueue<T>::empty() const
{
	return m_nQueueLen == 0;
}



/****************************************!
*@brief  ��ն���
*@author liuyanfu
*@date   2019��4��1��	21:32
*@param[out] 
*@return     void  
****************************************/
template<typename T>
void ArrQueue<T>::erase()
{
	m_nHead = -1;
	m_nTail = 0;
	m_nQueueLen = 0;
}


/****************************************!
*@brief  ��ӡ�����е�����
*@author liuyanfu
*@date   2019��4��1��	21:48
*@param[out] 
*@return     void  
****************************************/
template<typename T>
void ArrQueue<T>::print() const
{
	if(empty())
		std::cout << "Current queue is empty!" << std::endl;
	else
	{
		int index = m_nHead;
		int i = 1;
		while(index != m_nTail)
		{
			std::cout << "The " << i << "th element data is " << m_pQueue[index++] << std::endl;
		}

		std::cout << "All elements are printed." << std::endl;
	}
}