#include "stdafx.h"
#include <iostream>

//�ֲ���̬����

size_t count_calls()
{
	static size_t ctr = 0;       //�ֲ���̬���� ֻ��ʼ��һ��
	return ++ctr;
}

int main()
{

	for (size_t i = 0; i != 10;i++)
	{
		int j = count_calls();
		printf("%d", j);
	}
	return 0;
}

