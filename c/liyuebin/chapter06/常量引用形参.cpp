// ���������β�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

//�ж��Ƿ��д�д��ĸ
bool faction1(string const &MyString)		//����Ҫ�ı�ʵ��
{
	for (int i = 0; i < MyString.size();i++)
	{
		if (MyString[i] >= 'A' && MyString[i] <= 'Z')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}





int _tmain(int argc, _TCHAR* argv[])
{
	cout << "�������ַ���" << endl;
	string MyString;
	cin >> MyString;

	if (faction1(MyString))
	{
		cout << "���д�д�ַ�" << endl;
	}
	else
	{
		cout << "�����д�д�ַ���" << endl;
	}


	return 0;
}

