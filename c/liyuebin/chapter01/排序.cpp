// ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	int a, b, c;
	printf("������������\n");
	scanf_s("%d %d %d", &a, &b, &c);
	if (a>b)
	{
		if (b>c)
		{
			printf("%d %d %d",c, b, a);
		}
		else
		{
			if (a>c)
			{
				printf("%d %d %d", b, c, a);
			}
			else
			{
				printf("%d %d %d", c, a, b);
			}
		}
	}
	else
	{
		if (a > c)
		{
			printf("%d %d %d", c, a, b);

		}
		else
		{
			if (c > b)
			{
				printf("%d %d %d", a, b, c);
			}
			else
			{
				printf("%d %d %d", a, c, b);
			}
		}
	}
	return 0;
}

