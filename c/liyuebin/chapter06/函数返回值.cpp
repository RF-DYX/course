// ��������ֵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//�õ���̬�ֲ�������֪ʶ
int fact()
{
	static int i=0;
	return i++;
}


int _tmain(int argc, _TCHAR* argv[])
{
	cout << fact() << endl;					//��һ�η���0
	cout << fact() << endl;					//	�Ժ���ö���1
	return 0;
}

