#include "List.h"

int main()
{
	M::list list;

	//����10��Ԫ��
	for (int i = 0; i < 10; i++)
	{
		list.insert(0, i);
	}
	cout << list;

	//��ͷ������Ԫ��
	list.insert(0, 111);
	cout << list;

	//��β������Ԫ��
	list.insert(list.getlength(), 111);
	cout << list;

	//��ͷ��ɾ��Ԫ��
	list.erase(0);
	cout << list;

	//��β��ɾ��Ԫ��
	list.erase(list.getlength()-1);
	cout << list;

	//���м�ɾ��Ԫ��
	list.erase(1);
	cout << list;

	return 0;
}