#include"screen.h"
#include<iostream>
using namespace std;
int main()
{
	Screen myscreen(5,6,"aaaaa\naaaaa\naaaaa\naaaaa\naaaaa\n");
	//����Screen�����myscreen����ʼ��Ϊ5��6�е��ַ�
	myscreen.move(4,0).set('#').display(cout);
	//moveʹ����ƶ���ָ���ĵ�5�У���1�У����ص��Ƕ����Լ�*this
	//setʹ��괦�ַ����#
	//display��cout��������ַ�
	cout << "��굱ǰ����λ�ú��ַ�Ϊ�� " << myscreen.get_cursor() << " " << myscreen.get() << endl;
	string::size_type r=1, c=1;
	cout << "������Ҫ��ȡ��λ���������֣���1��ʼ����" << endl;
	cin >> r >> c;
	cout << myscreen.get(r,c) << endl;
	return 0;
}