/*
* ������	ջ
* ���ߣ�	dongyaxing
* �汾��	1.0
* ����ʱ�䣺2019/3/25   20:47
* �޸��ߣ� liuyanfu
* �޸�ʱ�䣺 2019/3/25   21:14
*/

#ifndef _STACK_H
#define _STACK_H

struct SNode
{
	int data;
	SNode *pNext;
};
typedef SNode *StackNode;
typedef unsigned int UINT;

class CStack
{
public:
	CStack(void);
	~CStack(void);

	bool Empty() const;	
	void Clear();

	StackNode GetTop() const;
	UINT GetLength() const;	

	void Push(const int &data);
	void Pop();
	void Print() const;
private:
	StackNode m_pTop;
	UINT m_nStackLen;
};

#endif//_STACK_H
