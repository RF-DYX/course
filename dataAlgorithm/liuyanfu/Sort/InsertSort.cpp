/*
* Copyright: (c) 2019
*
* �ļ�����:  InsertSort.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/9  11:21
*/
#include <iostream>
using namespace std;
typedef size_t UINT;

/**
* @brief	  ��������
*
* @method:    InsertSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/9  11:22 
*/
//��Ϊ���Ϊ�Ѿ���������У��Ҷ�Ϊ����������С�
void InsertSort(int *arr, int nLen)
{
	int temp = 0;
	for(int i = 1; i< nLen; ++i)
	{
		temp = arr[i];//���������Ԫ�ر�������
		int j = i - 1;
		for(; j >= 0; --j)//
		{
			if(arr[j] > temp)//���ǰ�ߵ�Ԫ�ش�ֱ�ӽ�ǰ�ߵ�Ԫ�ظ�ֵ�����ߵ�Ԫ��
				arr[j+1] = arr[j];
			else
				break;
		}
		arr[j+1] = temp;//����j��Ԫ��С�ڵ��ڴ������Ԫ��ʱ��ֱ�ӽ���j+1��Ԫ�ظ�ֵΪ�������Ԫ��
	}
}


/**
* @brief
*
* @method:    print
* @access:    public 
* @param:     int arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/9  11:08 
*/
void print(int *arr, int nLen)
{
	for(int i = 0;i < nLen; ++i)
	{
		cout << arr[i] << " ";
	}
	cout <<	endl;
}

int main()
{
	int arr[10] = {5, 4, 6, 3, 3, 2, 5, 8, 9, 7};
	int arr1[10] = {1,1,1,1,1,1,1,1,1,1};
	int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr3[10] = {10,9,8,7,6,5,4,3,2,1};
	print(arr, sizeof(arr)/sizeof(arr[0]));
	InsertSort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;

	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	InsertSort(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	cout << endl;

	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	InsertSort(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	cout << endl;

	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	InsertSort(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	return 0;
}