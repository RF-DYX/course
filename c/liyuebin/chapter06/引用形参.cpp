// �����β�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>											//C++���������string���ͱ���
using namespace std;



//�������ô���
int reset(string &MyString,char c,int &val)
{
	bool MyBool = true;										//�ֲ�����
	int FirstPosition =0;									//�ֲ����� �����һ��λ��

	for (int i = 0; i < MyString.size();i++)				
	{
		if (MyString[i] == c)
		{
			if (MyBool)
			{
				FirstPosition = i;
				MyBool = false;
			}
			
			val++;											//��˽����ָ���ַ����ֵĸ���
		}
		
	}
	return FirstPosition+1;									//����ָ���ַ���һ�γ��ֵ�λ��
	
}


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "�������ַ���";
	string MyString;
	cin >> MyString;

	cout << "������Ŀ���ַ�";
	char MyChar;
	cin >> MyChar;

	int MyVal=0;
	int Pos = reset(MyString,MyChar,MyVal);
	cout << "Ŀ���ַ���һ�γ��ֵ�λ����:"<<Pos << endl;
	cout << "Ŀ���ַ����ֵĴ���Ϊ:" << MyVal << endl;

	return 0;
}

