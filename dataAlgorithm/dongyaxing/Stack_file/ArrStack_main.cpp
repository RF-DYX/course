#include<iostream>
#include"ArrStack.h"
//#include"ArrStack.cpp"		// Linux����Ҫ���ļ�
using namespace std;
int main()
{
	AStack stk;
	stk.Empty();
	stk.GetLength();
	stk.GetTop();
	stk.Pop();
	stk.PrintStack();
	int n = 10;
	stk.Push(n);
	int length;
	for(int i = 0; i < 30; ++i)
	{
		int temp = 2;
		stk.Push(temp);
		if(stk.GetLength() == MAX_SIZE)
			break;
	}
	length = stk.GetLength();
	stk.PrintStack();

	system("pause");		// Linux�²���Ҫ���ļ�
	return 0;
}