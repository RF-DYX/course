/*
* �����ߣ�	dongyaxing
* ����ʱ�䣺2019/3/26   20:22
*/


#include<iostream>
#include"stack.h"
using namespace std;
int main()
{
	Stack stk;
	// ��ջ����
	stk.GetLength();
	stk.GetTop();
	stk.Clear();
	stk.Empty();
	stk.Pop();
	
	// �ǿ�ջ����
	int arr[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for(int i = 0; i < 10; ++i)
	{
		stk.Push(arr[i]);
	}
	stk.PrintStack();
	std::cout << "�����ǣ�" << stk.GetLength() << std::endl;
	stk.GetTop();
	//std::cout << "ջ��Ԫ���ǣ� " << stk.GetTop()->data << std::endl;		// �������ܿ���һ��Ԫ��
	stk.Pop();

	stk.Clear();
	stk.GetLength();

	system("pause");
	return 0;
}