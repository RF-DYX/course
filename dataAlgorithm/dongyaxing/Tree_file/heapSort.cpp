#include <iostream>
#include <stdlib.h>
using namespace std;

/*
* �ѽṹ��
* ������ȫ���������������һ�㣬����ȫ�����ģ������һ���㶼����
* ÿ����������ڵ��ڣ�����С�ڵ��ڣ���������ÿ������ֵ
* ��ȫ���������ʺ�������洢
*/
#define MAXSIZE 10
typedef struct SqList
{
	int r[MAXSIZE + 1];
	int length;
	SqList()
	{
		length = 0;
	}
}SqList;


/****************************************************************
* @brief : 		������������λ��
* @author : 	dyx
* @date : 		2019/7/2 17:08
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/****************************************************************
* @brief : 		����������r[s-m]�����ݣ�ʹ֮��Ϊһ���󶥶�
* @author : 	dyx
* @date : 		2019/7/2 16:55
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void HeapAdjust(SqList *L, int s, int m)//4.9
{
	int temp, j;
	temp = L->r[s];		// ��ǰ���4
	for(j = 2*s; j <= m; j*=2)		// j = 2s��Ϊ��ǰ�����ӽ��
	{
		if (j < m && L->r[j] < L->r[j+1])	// ���Źؼ��ֽϴ�ĺ��ӽ������ɸѡ
		{
			++j;							// j Ϊ�ؼ����нϴ�ļ�¼���±�
		}
		if (temp >= L->r[j])
		{
			break;							// rcӦ������λ��s��
		}
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp;			// ����
}


/****************************************************************
* @brief : 		��˳���L���ж�����
* @author : 	dyx
* @date : 		2019/7/2 17:12
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void HeapSort(SqList *L)
{
	int i;
	for (i = L->length/2; i > 0; --i)		// ��L�е�r����һ���󶥶�
	{
		HeapAdjust(L, i, L->length);
	}
	for (i = L->length; i > 1; --i)
	{
		swap(L, 1, i);						// ���Ѷ���¼�͵�ǰδ�����������е����һ����¼����
		HeapAdjust(L, 1, i-1);						// ��L->r[1...i-1]���µ���Ϊ����
	}
}

/****************************************************************
* @brief : 		��ӡ���
* @author : 	dyx
* @date : 		2019/7/2 17:31
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void print(SqList *L)
{
	for (int i = 1; i < L->length; ++i)
	{
		cout << L->r[i] << " ";
	}
	cout << endl;
}

int main()
{
	// ��ʼ��
	int arr[10] = {0,50,10,90,30,70,40,80,60,20};
	SqList sl;
	sl.r[0] = 0;
	for (int i = 1; i < 10; ++i)
	{
		sl.r[i] = arr[i];
		++sl.length;
	}
	// ��ӡ���ԭʼ����
	print(&sl);
	cout << endl;
	// ������
	HeapSort(&sl);
	//��ӡ������
	print(&sl);
//	system("pause");
	return 0;
}
