/*
* Copyright: (c) 2019
*
* �ļ�����:  ACM2785_2.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/5/17  10:24
*/
#include <stdio.h>
#include <algorithm>
int A[4001];
int B[4001];
int C[4001];
int D[4001];
int sum1[16000001];
int sum2[16000001];


//lower_bound(begin,end,num)�ҵ���һ�����ڻ��ߵ���num�����֣��ҵ��󷵻ظ����ֵĵ�ַ�������ڷ���end
//upper_bound(begin,end,num)�ҵ���һ������num�����֣��ҵ����ظ����ֵĵ�ַ���������򷵻�end
//lower_bound��upper_bound�������ö��ֲ��ҵķ�����һ���źõ�������в���
int main()
{
	int row;
	while(~scanf("%d", &row))
	{
		for(int i = 0; i < row; ++i)//n
		{
			scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
		}
		int r = 0;
		for(int i = 0; i < row; ++i)//n^2
		{
			for(int j = 0; j < row; ++j)
			{
				sum1[r++] = A[i] + B[j];
				sum2[r - 1] = C[i] + D[j];
			}
		}
		int ans = 0;
		std::sort(sum1, sum1 + r);//nlogn
		for(int i = 0; i < r; ++i)//n * nlogn
		{
			ans += std::upper_bound(sum1, sum1 + r, -sum2[i]) - std::lower_bound(sum1, sum1 + r, -sum2[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}