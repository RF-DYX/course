#ifndef _ASTACK_H
#define _ASTACK_H

typedef unsigned int UINT;
template<typename T>
class AStack
{
public:
	AStack(void);// ��ʼ��ջ
	~AStack(void);// ����ջ	
	AStack(UINT &);

	bool Empty() const;		// �ж��Ƿ�Ϊ��
	void Clear();		// �����ջ

	const T* GetTop() const;	// �õ�ջ��Ԫ�� ���س���ָ��
	UINT GetLength() const;	// ����ջ�ĳ���

	void Push(const T &data);	//��ջ��ѹ������
	void Pop();		//��ջ�����ݵ���

	void PrintStack();//��ӡջ�е�����
private:
	void ExpandStack();
	bool isFull();

	T* m_pStack;	// ջ��Ԫ��
	UINT m_nStackLen;	// ջ����Ч���ݵĳ���
	UINT m_nStackSize;   //ջ������
	int m_nTop;	//��¼ջ����λ��
};


#endif // _ASTACK_H
