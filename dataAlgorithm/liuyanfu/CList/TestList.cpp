#include <iostream>
#include "SingleList.h"
#include "SingleList.cpp"
using namespace std;

int main()
{
	SingleList<int> lst;
	lst.AddHead(20);
	lst.AddHead(23);
	lst.AddHead(21);
	lst.AddHead(28);
	lst.AddHead(12);
	lst.AddTail(66);
	lst.AddTail(89);
	lst.AddTail(45);
	lst.AddTail(80);

	lst.PrintList();

	cout << "ͷ��������Ϊ�� " << lst.GetHeadNode()->data << endl;
	cout << "β�ڵ������Ϊ�� " << lst.GetTailNode()->data << endl;
	cout << "����ĳ���Ϊ�� "   << lst.GetSize() << endl;

	int a = 0;
	cout << "��������Ҫ���ҵ����ݣ� ";
	cin >> a;
	if(!lst.Find(a))
		cout << "�����ҵ����ݲ����ڣ�" << endl;
	else
		cout << "�ҵ��ˣ������ҵ�����Ϊ�� " << lst.Find(a)->data << endl;

	cout << endl;
	cout << "ɾ��ָ�������ݽڵ�" << endl;
	lst.RemoveAt(lst.GetNode(21));
	lst.PrintList();
	cout << "����ĳ���Ϊ�� "   << lst.GetSize() << endl;

	cout << endl;
	cout << "��ָ�����ݽڵ�λ�ò�������" << endl;
	lst.InsertAt(lst.GetNode(28), 88);
	lst.PrintList();
	cout << "����ĳ���Ϊ�� "   << lst.GetSize() << endl;

	cout << endl;
	cout << "�޸�ָ�����ݽڵ������" << endl;
	lst.ModifyAt(lst.GetNode(89), 99);
	lst.PrintList();
	cout << "����ĳ���Ϊ�� "   << lst.GetSize() << endl;
	
	lst.Erase();
	return 0;
}