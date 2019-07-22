#include <iostream>

#define SIZE 256
#define MAX(x,y) return x < y ? y : x
using namespace std;


//����bc���±���������ַ�����Ӧ��ASCII�������ֵΪ�����ַ���ģʽ���е�λ���±�
void GenerateBC(const char* b, int m, int* bc)
{
	for(int i = 0; i < SIZE; ++i)
	{
		bc[i] = -1;
	}
	for(int i = 0; i < m; ++i)
	{
		bc[b[i]] = i;
	}
}

//����suffix���±����ú�׺�ĳ��ȣ������ֵΪģʽ���п�����ú�׺ƥ���Ӵ�����ʼλ���±�
//����prefix��С�����ú�׺�ĳ��ȣ������ֵ����ú�׺�ܷ���ģʽ����ǰ׺�Ӵ�ƥ��
void GenerateSP(const char* b, int m, int* suffix, bool* prefix)
{
	for(int i = 0; i < m; ++i)
	{
		suffix[i] = -1;
		prefix[i] = false;
	}
	for(int i = 0; i < m; ++i)
	{
		int j = i;
		int k = 0;
		while(j >=0 && b[j] == b[m-1-k])
		{
			--j;
			++k;
			suffix[k] = j + 1;
		}
		if(j < 0)
			prefix[k] = true;
	}
}

int moveBySP(int j, int m, int* suffix, bool* preffix)
{
	int k = m - 1 - j;
	if(suffix[k] != -1)
		return j - suffix[k] + 1;
	for(int r = j + 2; r < m; ++r)
	{
		if(preffix[m-r])
			return r;
	}
	return m;
}


int BM(const char* s, int n, const char* b, int m)
{
	int* bc = new int[SIZE];
	GenerateBC(b, m, bc);
	int* suffix = new int[m];
	int* preffix = new bool[m];
	GenerateSP(b, m, suffix, preffix);
	int i = 0;
	while(i <= n-m)
	{
		for(int j=m-1; j >=0; --j)
		{
			if(s[i+j] != b[j])
				break;
		}
		if(j < 0)
			return i;
		int x = j - bc[s[i+j]];//���ݻ��ַ�����ȷ��������λ��
		int y = 0;
		if(j < m -1)//֤���кú�׺����
		{
			y = moveBySP(j, m, suffix, preffix);
		}
		i += MAX(x,y);
	}
	return -1;
}