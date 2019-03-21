#include<iostream>
#include "SingleList.h"

using namespace std;

int main()
{
	// ��������
	SingleList sl;
	// �ж��Ƿ�����
	if(sl.IsEmpty())
	{
		std::cout << "sl is empty!" << std::endl;
	}
	else
	{
		std::cout << "sl is not empty!" << std::endl;
	}
	// ͷ���룬
	sl.AddHead(20);
	sl.AddHead(10);
	sl.PrintList();		// �����10,20
	std::cout << sl.GetHeadNode()->data << std::endl;		// �������ͷ
	std::cout << sl.GetTailNode()->data << std::endl;		// �������β
	std::cout << sl.GetLength() << std::endl;				// ���������
	// β����
	sl.AddTail(30);
	sl.AddTail(40);
	sl.PrintList();		// �����10��20,30,40
	std::cout << sl.GetMidNode()->data << std::endl;		// ��������м䣬20
	sl.AddHead(5);
	sl.AddTail(50);
	sl.AddHead(2);
	sl.PrintList();		// �����2,5,10,20,30,40,50
	std::cout << sl.GetMidNode()->data << std::endl;		// ��������м䣬20

	ListNode pos;
	pos = sl.GetHeadNode()->pNext->pNext;					// ָ������ĵ�3���ڵ㣬data = 10

	sl.InsertAt(pos, 15);
	sl.PrintList();											// �����2,5,15,10,20,30,40,50������pos��λ�ã�Ϊ���ĸ��ڵ� pos->data = 10

	sl.InsertAt(pos, 18);
	sl.PrintList();											// �����2,5,15,18��10,20,30,40,50�����ԣ��˴�������18����10ǰ�棬pos->data = 10

	sl.ModifyAt(pos, 33);
	sl.PrintList();											// �����2,5,15,18,33��20,30,40,50����ʱ��pos->data = 33
	
	pos = sl.GetHeadNode()->pNext->pNext;
	sl.RemoveAt(pos);
	sl.PrintList();											// �����2,5,18,33��20,30,40,50����ʱ��pos->data = 18
	
	sl.RemoveAt(1);
	sl.PrintList();											// �����2��18,33,20,30��40,50

	pos = sl.Find(33);
	std::cout << pos->data << std::endl;					// ������ҵ����ֲ����б��У��򷵻��жϡ�

	sl.Reverse();											// ��תͨ��
	sl.PrintList();

 	system("pause");
	return 0; 
}