/*
* ������	��ʽ����
* ���ߣ�	lyf
* �汾��	1.0
* ����ʱ�䣺2019/4/1   20:56
* �޸ģ�	dyx
* �޸����ݣ��淶�������ͱ�����
* �޸�ʱ�䣺2019/4/3	20:00
****** �ӿ�ǧ�������淶��һ��
****** �ӿڲ��淶��ũ��������
*/
#ifndef _QUEUE_H
#define _QUEUE_H

template<typename T>
struct SNode
{
	T data;
	SNode* pNext;
};

typedef unsigned int UINT;
template<typename T>
class ListQueue
{
public:
	typedef SNode<T> *QNode;
public:
	ListQueue(void);
	~ListQueue(void);
	bool enqueue(const T& data);	//���    �Ӷ��е�β����������
	bool dequeue();					//����   �Ӷ��е�ͷ����������
	UINT getlength() const;			//��ö��еĳ���
	bool empty() const;				//�ж϶����Ƿ�Ϊ��
	void erase();					//��ն���
	void print() const;
private:	
	QNode m_pHead;			// ͷ
	QNode m_pTail;			// β
	UINT m_nQueueLen;		// ��Ч����
};
#endif //_QUEUE_H