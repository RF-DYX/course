#include "ArrStack.h"
#include<iostream>
using namespace std;

AStack::AStack(void)
{
	//m_pTop.top = -1;	// -1��ʾδ�����ݣ�top = 0�����ʾ��һ�����ݣ���Ӧ��������±�
}

AStack::~AStack(void)
{
	Clear();
}

// �ж��Ƿ�Ϊ��
bool AStack::Empty() const
{
	if(-1 == m_pTop.top)
		return true;
	else
		return false;
}

// ���ջ��ֻҪ��Ϊ�գ���һֱ��ջ
void AStack::Clear()
{
	while(!Empty())
	{
		Pop();
	}
}

int AStack::GetTop() const
{
	if(IsFull())		// ��ջ
	{
		return 0;
	}
	else
	{
		return m_pTop.arr_stack[m_pTop.top];
	}
}

UINT AStack::GetLength() const
{
	return m_pTop.top + 1;
}

bool AStack::Push(int &data)
{
	if(IsFull())		// ��ջ
	{
		return false;
	}
	else				// ����ջ
	{
		++m_pTop.top;
		m_pTop.arr_stack[m_pTop.top] = data;
		return true;
	}
}

bool AStack::Pop()
{
	if(Empty())
	{
		return false;
	}
	else
	{
		int temp;
		temp = m_pTop.arr_stack[m_pTop.top];
		--m_pTop.top;
		return true;
	}
}

void AStack::PrintStack()
{
	int index = m_pTop.top + 1;
	while(index)
	{
		std::cout << "�� " << index << " ��Ԫ���ǣ�" << m_pTop.arr_stack[index - 1] << std::endl;
		--index;
	}
}

bool AStack::IsFull() const
{
	return ((MAX_SIZE - 1) == m_pTop.top);
}
// ���¿���һ��2�������飬��ԭ���ݵ����µ����顣
//bool AStack::ExpendStack()
//{
//	return false;
//}
