// ��д��Сд.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

//��д��ĸ�ı�Сд��ĸ
void faction1(string  &MyString)		//��Ҫ�ı�ʵ��
{
	for (int i = 0; i < MyString.size(); i++)
	{
		if (MyString[i] >= 'A' && MyString[i] <= 'Z')
		{
			MyString[i] = MyString[i] + 32;
			
		}

	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "�������ַ���" << endl;
	string MyString;
	cin >> MyString;
	faction1(MyString);
		
	cout << "�ı�֮����" << MyString<<endl;
	

	return 0;
}

