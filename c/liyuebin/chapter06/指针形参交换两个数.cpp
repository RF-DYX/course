// ָ���βν���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void fact(int *a,int *b)                         //ָ���βο��Ըı�ʵ�ε�ֵ
{
	int c = *a;
	*a = *b;
	*b = c;

}


int _tmain(int argc, _TCHAR* argv[])
{
	int i = 5;
	int j = 9;
	fact(&i, &j);
	printf("i��%d,j��%d", i, j);                  //�����������෴
	
	return 0;
}

