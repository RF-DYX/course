// �β� �ֲ����� ��̬�ֲ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include <vector>
using namespace std;



int fact()									//������β�
{
	static int ctr = 0;						//�ֲ���̬���� ����������Ȼ���� ֻ��ʼ��һ��
	ctr++;
	return ctr;
}


int _tmain(int argc, _TCHAR* argv[])
{

	for (int i=1; i <=10;i++)				//i���Ǿֲ����� ����forѭ���Ľ�������
	{
		cout << fact() << endl;            
	}

	cout << fact() << endl;					//��̬�ֲ�����û�б����� �ᴩ�������� �����11
	return 0;

}

