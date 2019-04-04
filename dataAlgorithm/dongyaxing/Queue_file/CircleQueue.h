/**
* ժҪ��	ѭ�����У�β���������
* ����ʱ�䣺2019/4/4    17��00
*/

#ifndef _CIRCLE_QUEUE_H
#define _CIRCLE_QUEUE_H

#define MAX_SIZE 10
typedef unsigned int UINT;
template <typename T>
class CircleQueue
{
public:
	CircleQueue(void);
	CircleQueue(const UINT &InitSize);
	~CircleQueue(void);

	UINT GetLength() const;
	bool Empty() const;
	bool EnQueue(const T &data);
	bool DeQueue();
	void Erase();
	void Print() const;
private:
	T *CQueue;
	UINT m_nHead;
	UINT m_nTail;
	UINT m_nCQueueLen;		// ��Ч����
	UINT m_nCQueueSize;		// ѭ�����еĴ�С
};

#endif //_CIRCLE_QUEUE_H