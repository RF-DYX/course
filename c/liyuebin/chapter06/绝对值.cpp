// ����ֵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//�������ֵ

void absolute(int a)
{

	if (a<0)
	{
		printf("����ֵ��%d",-a);
	}
	else
	{
		printf("����ֵ��%d", a);
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	//���þ���ֵ����
	absolute(-5);
	return 0;
}

