
#include "List.h"

namespace M
{
	//��ʼ��ͷ�ڵ�
	list::list()
	{
		length = 0;
		Header = new Node{ 0, nullptr };
	}

	//����ͷ�ڵ�
	list::~list()
	{
		destory();
	}
	// ��ȡĿ��λ�õ�ǰһ���ڵ�
	list::PNode list::getprenode(int Index)
	{
		// -> 0 1 2 3 4 5 6 7 ��

		// ��ȡͷ�ڵ�
		PNode node = Header;

		// ���ݴ����ֵ��ȡ��һ���ڵ�
		for (int i = 0; i < Index; ++i)
			node = node->next;

		// �����ҵ��Ľڵ�
		return node;
	}
	//����Ԫ��
	bool list::insert(int Index, int Elem)
	{
		//1.���λ���Ƿ���Ч
		if (Index<0 || Index> length)
			return false;

		//2.��ȡǰһ��λ�õĽڵ�
		PNode PreNode = getprenode(Index);

		//3.�����µĽڵ� �����޸�ָ��
		PNode NewNode = new Node{ Elem, PreNode->next };
		PreNode->next = NewNode; 

		//�ı��С ����true
		++length;
		return true;
	}

	//ɾ��Ԫ��
	bool list::erase(int Index)
	{
		//1.���λ���Ƿ���Ч
		if (Index<0 || Index> length-1)
			return false;

		//2.��ȡǰһ��λ�õĽڵ�
		PNode PreNode = getprenode(Index);

		//3.ɾ��ָ��
		PNode TemNode = PreNode->next;
		PreNode->next = PreNode->next->next;
		delete[] TemNode;

		//�ı��С ����true
		--length;
		return true;
	}
	//��������
	void list::destory()
	{
		PNode node = Header;

		while (node)
		{
			PNode Temp = node->next;
			delete node;
			node = Temp;
		}
	}

	//������������
	ostream &operator<<(ostream& o, list & l)
	{

		//��ȡͷ�ڵ�
		list::PNode node = l.Header->next;


		//��ǰ�ڵ㲻Ϊnullptrʱ ���������
		while (node)
		{
			o << node->item << " ";
			node = node->next;
		}
		cout << endl;
		return o;
	}
	
}