#ifndef _TEMPLET_STACK_H
#define _TEMPLET_STACK_H

template<typename DATA>
struct SNode
{
	DATA data;
	SNode* pNext;
};

typedef unsigned int UINT;

template<typename DATA>
class TmpStack
{
public:
	typedef SNode<DATA>* StackNode;
public:
	TmpStack(void);
	~TmpStack(void);

	bool Empty() const;		// �ж��Ƿ�Ϊ��
	void Clear();		// �����ջ

	const SNode<DATA>* GetTop() const;	// �õ�ջ��Ԫ��
	UINT GetLength() const;	// ����ջ�ĳ���
	void Push(const DATA& data);	//��ջ��ѹ������
	void Pop();		//��ջ�����ݵ���
	void PrintStack();
private:
	StackNode m_pTop;	// ջ��Ԫ��
	UINT m_nStackLen;
};

#endif //_TEMPLET_STACK_H