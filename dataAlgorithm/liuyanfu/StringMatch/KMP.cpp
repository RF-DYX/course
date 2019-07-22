#include <iostream>

using namespace std;

//����next���±�����ǰ׺��β�ַ����±꣬����ֵ������Ŀ�����
//��ǰ׺�ĺ�׺�Ӵ�ƥ���ǰ׺�Ӵ��Ľ�β�ַ��±�
void GenerateNexts(const char* b, int m, int* next)
{
	for(int i = 0; i < m; ++i)
	{
		next[i] = -1;
	}
	int k = -1;
	for(int i = 1; i < m; ++i)
	{
		while(k != -1 && b[k+1] != b[i])
		{
			k = next[k];
		}
		if(b[k+1] == b[i])
			++k;
		next[i] = k;
	}
}


int KMP(const char* s, int n, const char* b, int m)
{
	int* next = new int[m];
	GenerateNexts(b,m, next);
	int j = 0;
	for(int i = 0; i < n; ++i)
	{
		while(j > 0 && s[i] != b[j])
			j = next[j - 1] + 1;
		if(s[i] == b[j])
			++j;
		if(j == m)
			return i - m + 1;
	}
	return -1;
}


int main()
{

	return 0;
}