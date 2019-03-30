/**
* ������	ջ
* ���ߣ�	dongyaxing
* �汾��	1.0
* ����ʱ�䣺2019/3/25   20:47
* �޸��ߣ�	liuyanfu
* �޸�ʱ�䣺2019/3/25   21:14
*/

#ifndef _STACK_H
#define _STACK_H
#include <iostream>
using namespace std;

struct SNode
{
	int data;
	SNode *pNext;
};
typedef SNode *StackNode;
typedef unsigned int UINT;

class Stack
{
public:
	Stack(void);				// ��ʼ��ջ
	~Stack(void);				// ����ջ

	bool Empty() const;			// �ж��Ƿ�Ϊ��
	void Clear();				// ���ջ

	StackNode GetTop() const;	// �õ�ջ��Ԫ��
	UINT GetLength() const;		// ����ջ�ĳ���

	void Push(int &data);		// ��ջ��ѹ������
	void Pop();					// ��ջ�����ݵ���

	void PrintStack();			// ��ӡջ����
private:
	StackNode m_pTop;			// ջ��Ԫ��
	UINT m_nStackLen;			// ջ����
};

#endif	\\_STACK_H