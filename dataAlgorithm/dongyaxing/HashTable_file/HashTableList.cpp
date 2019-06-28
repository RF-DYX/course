#include "HashTableList.h"
#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/****************************************************************
* @brief : 		��ʼ��ɢ������
* @author : 	dyx
* @date : 		2019/6/28 14:03
* @version : 	ver 1.0
* @inparam :	����Ĭ��ȡ17���ҿ���17��������ָ������
* @outparam :	
*****************************************************************/
HashTableList::HashTableList(void)
{
	module = 17;
	nCount = 0;
	pHeadArr = new NodeType[module];
	memset((void *)pHeadArr, 0, module*sizeof(NodeType));
}

/****************************************************************
* @brief : 		�����ʼ��ָ�����鳤��
* @author : 	dyx
* @date : 		2019/6/28 14:23
* @version : 	ver 1.0
* @inparam :	
* @outparam :	
*****************************************************************/
HashTableList::HashTableList(int nLen):module(nLen)
{
	if (nLen <= 0)
	{
		return;
	}
	nCount = 0;
	pHeadArr = new NodeType[module];
	memset((void *)pHeadArr, 0, module*sizeof(NodeType));
}

HashTableList::~HashTableList(void)
{
	erase();
}

/****************************************************************
* @brief : 		��������
* @author : 	dyx
* @date : 		2019/6/28 14:25
* @version : 	ver 1.0
* @inparam :	��Ҫ�������
* @outparam :	�ɹ����򷵻�true
*****************************************************************/
bool HashTableList::Insert(const int &data)
{
	int index = Hash(data);		// get index
	if (pHeadArr[index] == NULL)
	{
		pHeadArr[index] = new list<HashItem>;
	}
	HashItem *pTemp = new HashItem(data);
	pHeadArr[index]->push_back(*pTemp);
	delete pTemp;
	++nCount;
	return true;
}

/****************************************************************
* @brief : 		ɾ�����ڵ�ĳ��Ԫ��
* @author : 	dyx
* @date : 		2019/6/28 14:26
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
bool HashTableList::Delete(const int &data)
{
	if (pHeadArr[Hash(data)] == NULL)
	{
		return false;
	}
	else
	{
		int index = Hash(data);
		list<HashItem>::iterator it = pHeadArr[index]->begin();
		for (; it != pHeadArr[index]->end(); ++it)
		{
			if (it->data == data)
			{
				pHeadArr[index]->erase(it);
				--nCount;
				return true;
			}
		}
		return false;
	}
}

/****************************************************************
* @brief : 		�Ƿ����ĳ��Ԫ��
* @author : 	dyx
* @date : 		2019/6/28 14:31
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
bool HashTableList::Contain(const int &data)
{
	if (pHeadArr[Hash(data)] == NULL)
	{
		return false;
	}
	else
	{
		int index = Hash(data);
		list<HashItem>::iterator it = pHeadArr[index]->begin();
		for (; it != pHeadArr[index]->end(); ++it)
		{
			if (it->data == data)
			{
				return true;
			}
		}
		return false;
	}
}

/****************************************************************
* @brief : 		Ŀǰ���ж���Ԫ��
* @author : 	dyx
* @date : 		2019/6/28 14:32
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
int HashTableList::Count()
{
	return nCount;
}

/****************************************************************
* @brief : 		�����������ȡģ
* @author : 	dyx
* @date : 		2019/6/28 14:32
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
int HashTableList::Hash(int key)
{	
	if (key < 0)
	{
		return -1;
	}
	return key%module;
}

/****************************************************************
* @brief : 		ɾ��ĳ��Ԫ��
* @author : 	dyx
* @date : 		2019/6/28 14:33
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void HashTableList::erase()
{
	for (int i = 0; i < module; ++i)
	{
		if (pHeadArr[i] != NULL)
		{
			delete pHeadArr[i];
			pHeadArr[i]= NULL;
		}
	}
	delete []pHeadArr;
	pHeadArr = NULL;
}

/****************************************************************
* @brief : 		��ӡ����
* @author : 	dyx
* @date : 		2019/6/28 14:33
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void HashTableList::print()
{
	for (int i = 0; i < module; ++i)
	{
		if (pHeadArr[i] != NULL)
		{
			list<HashItem>::iterator it = pHeadArr[i]->begin();
			for (; it != pHeadArr[i]->end(); ++it)
			{
				cout << it->data << "-" << it->info << "  ";
			}
			cout <<endl;
		}
		else
			cout << endl;
	}
}

/****************************************************************
* @brief : 		ƽ��ȡ�з��������ֻ�����λ��
* @author : 	dyx
* @date : 		2019/6/27 19:26
* @version : 	ver 1.0
* @inparam :  ����Ϊ4λ�������������������ƽ����Ȼ������м����λ���������8λ����ǰ3λ���м�3λ����2λ��ȡ�м�3λ��
* @outparam : 
*****************************************************************/
int HashTableList::hashFunc_1(int num)
{
	if (num < 1000 && num > 9999)
	{
		return -1;
	}
	int square = 0;
	int count = 0;
	square = num * num;
	while (square > 0)
	{
		square /= 10;
		++count;
	}
	int back = 0;
	back = (count - 3)/2;

	return num / back % 1000;
}

/****************************************************************
* @brief : 		����ȡģ
* @author : 	dyx
* @date : 		2019/6/27 19:47
* @version : 	ver 1.0
* @inparam :  ԭʼ���ݣ�ģ�� ͨ����ģȡС�ڵ���ԭʼ���ݵ�������
* @outparam : 
*****************************************************************/
int HashTableList::hashFunc_2(int num, int mod)
{
	if (num <0 || mod <= 0)
	{
		return -1;
	}
	return num % mod;
}

/****************************************************************
* @brief : 		���������
* @author : 	dyx
* @date : 		2019/6/27 19:51
* @version : 	ver 1.0
* @inparam :	��������ݣ���С��ȷ��ʱ��λ����ȷ��ʱ������ʹ�á�
* @outparam :	�������Ϊ4λ֮�ڵ���
*****************************************************************/
int HashTableList::hashFunc_3(int num)
{
	int result; 
	srand(num);
	result = rand();
	if (result > 9999)
	{
		result%=1000;
	}
	return result;
}
