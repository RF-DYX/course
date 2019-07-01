#include<iostream>
using namespace std;
/************************************************************************/
/** 
* ����tree
*/
/************************************************************************/

typedef char DATA;
struct SNode
{
	DATA data;
	SNode *pLeft;
	SNode *pRight;
	SNode(DATA d):data(d),pLeft(NULL), pRight(NULL){}
};

/****************************************************************
* @brief : 		ǰ�����
* @author : 	dyx
* @date : 		2019/7/1 9:28
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void PreOrder(SNode *pRoot)
{
	if (!pRoot)
	{
		return;
	}
	cout << pRoot->data << " ";
	PreOrder(pRoot->pLeft);
	PreOrder(pRoot->pRight);
}

/****************************************************************
* @brief : 		�������
* @author : 	dyx
* @date : 		2019/7/1 9:28
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void InnerOrder(SNode *pRoot)
{
	if (!pRoot)
	{
		return;
	}
	PreOrder(pRoot->pLeft);
	cout << pRoot->data << " ";
	PreOrder(pRoot->pRight);
}

/****************************************************************
* @brief : 		�������
* @author : 	dyx
* @date : 		2019/7/1 9:28
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void PostOrder(SNode *pRoot)
{
	if (!pRoot)
	{
		return;
	}
	PostOrder(pRoot->pLeft);
	PostOrder(pRoot->pRight);
	cout << pRoot->data << " ";
}

int main()
{
	SNode *p = new SNode('A');
	p->pLeft = new SNode('B');
	p->pRight = new SNode('C');

	SNode *pL = p->pLeft;
	pL->pLeft = new SNode('G');
	pL->pRight = new SNode('H');
	pL->pLeft->pRight = new SNode('D');

	SNode *pR = p->pRight;
	pR->pLeft = new SNode('E');
	pR->pLeft->pLeft = new SNode('I');
	pR->pLeft->pRight = new SNode('J');
	pR->pRight = new SNode('F');

	cout << "ǰ�������"<<endl;
	PreOrder(p);
	cout << endl;

	cout << "���������"<<endl;
	InnerOrder(p);
	cout << endl;

	cout <<"���������"<<endl;
	PostOrder(p);
	cout << endl;
//	system("pause");
	return 0;
}
