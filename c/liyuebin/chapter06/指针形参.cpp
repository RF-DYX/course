// ָ���β�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//  
//   int   faction1(int a)                 //�����β�
//   {
//   	return a;
//   }
// 
// 
//   
// 

//��ײ�ĺ���
void jiaohu()
{

	int a;
	printf("������һ������\n");
	scanf_s("%d",&a,sizeof(a));

	for (int i = a-1; i >1; i--)
	{
		a = a*i;
	}
	printf("�ײ���%d", a);
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*faction1(50);  */                  //����ʵ��
	jiaohu();
	return 0;
}

