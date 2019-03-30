/**
* ժҪ��	����-ջ��ֱ�����װ��û������ṹ
* �޸ģ�	��mingming�Ļ����ϣ��޸ģ����һ����ǰ���ȣ���õ�ǰλ��
* ���ߣ�	dongyaxing
* ���ڣ�	2019/3/30
*/
#ifndef _ARRSTACK_2_H
#define _ARRSTACK_2_H

#define MAX_SIZE 20
typedef unsigned int UINT;
template <class T>

class arrStack
{
public:
	arrStack(void);				// ���캯��������ָ����С
	arrStack(UINT max_size);	// ����ָ����С
	~arrStack(void);			// ��������

	bool IsEmpty() const;			// �ж��Ƿ�Ϊ��
	bool IsFull() const;			// �ж��Ƿ���ջ
	void Clear();					// ���ջ

	T GetTop() const;				// �õ�ջ��Ԫ��
	UINT GetLength() const;			// ����ջ�ĳ���
	UINT GetCurrLength() const;		// ���ص�ǰջ�ĳ���

	void Push(T &data);				// ѹջ
	void Pop();						// ��ջ
	void Print();					// ���ջ������

//private:
	void Expand();					// ����

private:
	int m_nTop;			// ջ������
	UINT m_nStackLen;	// ջ����
	T* arr;				// ����arr
};





#endif
