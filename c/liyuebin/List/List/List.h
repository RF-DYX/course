
#ifndef LIST_H
#define  LIST_H

#include <iostream>
using namespace std;

namespace M
{
	//list ��
	class list
	{
	public:
		//�����ڵ�����
		typedef struct Node
		{
			int item;    //������
			Node* next;  //ָ����
		}Node, *PNode;
	private:
		//ͷ�ڵ�
		PNode Header = nullptr;

		//��ǰ������
		int length = 0;

		//��ȡĿ��λ�õ�ǰһ���ڵ�
		PNode getprenode(int Index);
	public:
		list();
		~list();

		//����Ԫ��
		bool insert(int Index, int Elem);

		//ɾ��Ԫ��
		bool erase(int Index);

		//��ȡ����
		int getlength(){ return length; };

		//��������
		void destory();

		//������������
		friend ostream &operator<<(ostream &o, list & l);
	};

}
#endif

