#ifndef _ASTACK_H
#define _ASTACK_H

typedef unsigned int UINT;
class AStack
{
public:
	AStack(void);// ��ʼ��ջ
	~AStack(void);// ����ջ	
	AStack(UINT &);

	bool Empty() const;		// �ж��Ƿ�Ϊ��
	void Clear();		// �����ջ

	const int* GetTop() const;	// �õ�ջ��Ԫ�� ���س���ָ��
	UINT GetLength() const;	// ����ջ�ĳ���

	void Push(const UINT &data);	//��ջ��ѹ������
	void Pop();		//��ջ�����ݵ���

	void PrintStack();//��ӡջ�е�����
private:
	void ExpandStack();
	bool isFull();

	int* m_pStack;	// ջ��Ԫ��
	UINT m_nStackLen;	// ջ����Ч���ݵĳ���
	UINT m_nStackSize;   //ջ������
	int m_nTop;	//��¼ջ����λ��
};


#endif // _ASTACK_H
