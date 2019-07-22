/*
* Copyright: (c) 2019
*
* �ļ�����:  ACM2255.cpp	
* �ļ���ʶ��
* ժ	Ҫ�� ��֪ǰ����������������˳���ع�����������ӡ����������
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/6/3  10:47
*/

#include <stdio.h>
#include <string.h>

char pre[100];
char mid[100];

void postorder(int s1, int s2, int n)
{
	int pos = s2;
	if(n <= 0)
		return;
	while(mid[pos] != pre[s1])
		pos++;
	postorder(s1+1, s2, pos-s2);
	postorder(s1+pos-s2+1, pos+1, n-pos-1+s2);
	printf("%c", pre[s1]);
}


int main()
{
	while(~scanf("%s%s",pre, mid))
	{
		int len = strlen(pre);
		postorder(0,0,len);
		printf("\n");
	}
	return 0;
}