/**
* ������	����-ջ
* ���ߣ�	dongyaxing
* �汾��	1.0
* ����ʱ�䣺2019/3/27   10:30
*/

#ifndef _ARRSTACK_H
#define _ARRSTACK_H

#define MAX_SIZE 20
#define INIT_VALUE -1
#include <iostream>
using namespace std;

struct ArrStack
{
	int arr_stack[MAX_SIZE];		// ջ�Ĵ�С
	int top;						// ջ��ָ��
	ArrStack()
	{
		memset(arr_stack, 0, sizeof(arr_stack));
		top = -1;
	}
};
typedef ArrStack *stack;
typedef unsigned int UINT;
class AStack
{
public:
	AStack(void);
	~AStack(void);
	bool Empty() const;			// �ж��Ƿ�Ϊ��
	void Clear();				// ���ջ

	int GetTop() const;		// �õ�ջ��Ԫ��
	UINT GetLength() const;		// ����ջ�ĳ��ȣ���ЧԪ�ظ���

	bool Push(int &data);		// ��ջ��ѹ������
	bool Pop();					// ��ջ�����ݵ���

	void PrintStack();			// ��ӡջ����
private :
	bool IsFull() const;		// �ж��Ƿ���
	bool Transfer() const;		// ջ������ת������

private:
	stack m_pTop;				// ջ��Ԫ��
	//UINT m_nStackLen;			// ջ����
};



#endif \\_ARRSTACK_H