/*
* Copyright: (c) 2019
*
* �ļ�����:  Solve_SquareRoot.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/18  14:48
*/
#include <stdio.h>
/*
��1������С��1����������ƽ�����Ǵ��ڱ�������������0.04��ƽ������0.2��������n < 1,����ƽ�����ķ�Χ��(n,1)
��2�����ڴ���1����������ƽ�����Ǻ�С�ڱ��������ģ�����4��ƽ������2��������n >= 1������ƽ�����ķ�Χ��[1,n)
*/
double SolveSqroot(double n)
{
	double precision = 0.0000001;
	double square = 0.0;
	double mid = 0;
	double low = 0.0;
	double high = 0.0;
	if(n < 1)
	{
		low = n;
		high = 1;
	}
	else
	{
		low = 1;
		high = n;
	}
	while(high - low >= precision)
	{
		mid = low + (high - low)/2;
		if(mid * mid == n)
			return mid;
		else if(mid * mid < n)
			low = mid;
		else
			high = mid;
	}
	return low;
}

int main()
{
	double InputNum = 0;
	while(scanf_s("%lf", &InputNum) && InputNum)
	{
		printf("%lf%s%lf\n", InputNum, "��ƽ����Ϊ��", SolveSqroot(InputNum));
	}
	return 0;
}