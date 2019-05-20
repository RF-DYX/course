/*
* Copyright: (c) 2019
*
* �ļ�����:  ACM2785.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/5/16  8:00
*/
#include <stdio.h>
#include <algorithm>
int A[4001];
int B[4001];
int C[4001];
int D[4001];
int sum1[16000001];
int sum2[16000001];
int ans ,r;
void find(int value)
{
	int low = 0, high = r - 1;
	int mid = 0;
	while(low < high)//��֤�ҵ���һ���봫��ֵ��ȵ�λ��
	{
		mid = low + (high - low) / 2;
		if(sum1[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	while(sum1[low] == value && low < r)
	{
		ans++;
		low++;
	}
}
int main()
{
	int row;
	while(~scanf("%d", &row))
	{
		for(int i = 0; i < row; ++i)//n
		{
			scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
		}
		r = 0;
		for(int i = 0; i < row; ++i)//n^2
		{
			for(int j = 0; j < row; ++j)
			{
				sum1[r++] = A[i] + B[j];
				sum2[r - 1] = C[i] + D[j];
			}
		}
		ans = 0;
		std::sort(sum1, sum1 + r);//nlogn
		for(int i = 0; i < r; ++i)//n * nlogn
		{
			find(-sum2[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}