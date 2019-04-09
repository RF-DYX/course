/*
* Copyright: (c) 2019
*
* �ļ�����:  MergeSort.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/9  17:15
*/

#include <iostream>
using namespace std;


/**
* @brief	  �ϲ���������
*
* @method:    Merge
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int mid
* @param:     int right
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/9  21:42 
*/
void Merge(int *arr, int left, int mid, int right)
{
	int *pTemp = new int[right - left + 1];
	int lf = left;
	int rg = mid + 1;
	int begin = 0;
	while(lf <= mid && rg <= right)
	{
		if(arr[lf] <= arr[rg])
			pTemp[begin++] = arr[lf++];
		else
			pTemp[begin++] = arr[rg++];
	}
	while(lf <= mid)
	{
		pTemp[begin++] = arr[lf++];
	}
	while(rg <= right)
	{
		pTemp[begin++] = arr[rg++];
	}

	int temp = left;
	for(int i = 0;i< (right -left + 1); ++i)
	{
		arr[temp++] = pTemp[i];
	}
	delete []pTemp;
}


/**
* @brief	  ��һ�����л��ֳ���������
*
* @method:    Divide
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int right
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/9  21:43 
*/
void Divide(int *arr, int left, int right)
{
	if(left >= right)//�ݹ���˳�����
		return;
	int mid = (left + right) / 2;
	Divide(arr, left, mid);
	Divide(arr, mid + 1, right);
	Merge(arr, left, mid, right);
}


/**
* @brief	  �鲢����
*
* @method:    MergeSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/9  17:16 
*/
void MergeSort(int *arr, int nLen)
{
	Divide(arr, 0, nLen -1);
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
	MergeSort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;

	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	MergeSort(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	cout << endl;

	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	MergeSort(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	cout << endl;

	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	MergeSort(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	return 0;
}