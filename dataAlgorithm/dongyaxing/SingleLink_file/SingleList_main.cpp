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
	// ** ���������ͨ��
	/*sl.Erase();
	int n = 5;
	sl.Find(n);
	sl.GetHeadNode();
	sl.GetLength();
	sl.GetMidNode();
	sl.GetTailNode();
	ListNode p;
	p = sl.GetHeadNode();
	sl.InsertAt_2(p, 10);
	sl.InsertAt_2(p, 20);
	sl.ModifyAt_2(p, 15);
	sl.RemoveAt_2(p);
	sl.RemoveAt_2(1);*/

	// ** ֻ��ͷ������ͨ��
	sl.PrintList();
	sl.AddHead(20);
	//sl.AddTail(30);
	sl.PrintList();
	sl.GetHeadNode();
	sl.GetLength();
	sl.GetMidNode();
	sl.GetTailNode();
	std::cout << endl;
	ListNode p2;
	p2 = sl.GetHeadNode();
	sl.InsertAt_2(p2, 10);
	sl.InsertAt_2(p2, 20);
	sl.ModifyAt_2(p2, 15);
	sl.RemoveAt_2(p2);
	sl.RemoveAt_2(1);

	sl.AddHead(10);
	sl.PrintList();		
	sl.GetHeadNode();		
	sl.GetTailNode();		
	sl.GetLength();				
	std::cout << endl;			

	sl.Reverse();											
	sl.PrintList();

 	system("pause");
	return 0; 
}