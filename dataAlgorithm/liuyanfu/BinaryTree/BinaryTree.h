/*
* Copyright: (c) 2019
*
* �ļ�����:  BinaryTree.h	
* �ļ���ʶ�� 
* ժ	Ҫ�� ˳��洢��,û��ʵ�ֶ�̬���ݣ����ֻ�ܴ�����޸���
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/5/20  15:56
*/

#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
template<typename T>
class BinaryTree
{
public:
	BinaryTree(void);
	BinaryTree(const int& length);
	~BinaryTree(void);

	void PreOrder(const int& index);
	void InOrder(const int& index);
	void PostOrder(const int& index);
	
	void Insert(const T& data);
	void Delete(const T& data);
	const T& find(const T& data);

	int Height();
	int Length();
private:
	T* pRoot;
	int nCount;
	int nLen;
};

#endif