#include <iostream>
#include "ACMatch.cpp"
using namespace std;

int main()
{
	AC ac;
	// ����һЩģʽ��
	ac.insert("hello");
	ac.insert("world");
	ac.insert("browse");
	ac.insert("snake");
	ac.insert("he");
	ac.insert("her");
	ac.insert("wor");
	ac.insert("br");
	// ��Trie��
	ac.buildFailurePointer();

	// ����text���Ƿ���ģʽ��
	if (ac.find("hello"))
	{
		cout << "FIND IT" << endl;
	}
	else
	{
		cout << "NOT FIND IT" << endl;
	}
	// ����text���Ƿ���ģʽ��
	if (ac.find("brother"))
	{
		cout << "FIND IT" << endl;
	}
	else
	{
		cout << "NOT FIND IT" << endl;
	}

	// ��ӡ������Ҽ��������������к���ģʽ�������Ϊ***
	ac.print("hellowoldh");
	ac.print("breosiof");
	ac.print("hisd");
	ac.print("her");
//	system("pause");
	return 0;
}
