/**
* ժҪ��	˳��ջ��β��������ݣ�
*/

#ifndef _ARRQUEUE_H
#define _ARRQUEUE_H

#define MAX_SIZE 10
typedef unsigned int UINT;
template<typename T>
class ArrQueue
{
public:
	ArrQueue(void);		// ����
	~ArrQueue(void);	// ����
	ArrQueue(const UINT & InitSize);		// ���죨��ʼ�����ȣ�

	bool EnQueue(const T &data);
	bool DeQueue();

	UINT GetLength() const;

	bool Empty() const;
	void Print() const;
	void Erase();

private:
	T* m_pQueue;
	UINT m_nHead;
	UINT m_nTail;
	UINT m_nQueueLen; // ��Ч����
	UINT m_nQueueSize;	// ���ٿռ�
};





#endif //_ARRQUEUE_H
