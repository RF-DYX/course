/*
* Copyright: (c) 2019
*
* �ļ�����:  RadixSort.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/12  13:03
*/

#include <iostream>

using namespace std;
void print(int *arr, int nLen);
/**
* @brief	  ��ȡ���λ��
*
* @method:    GetMaxDigit
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/12  22:44 
*/
int GetMaxDigit(int *arr, int nLen)
{
	int digit = 1;
	int base = 10;
	for(int i = 0;i < nLen; ++i)
	{
		if(arr[i] >= base)
		{
			++digit;
			base *= 10;
		}
	}
	return digit;
}
/**
* @brief      ��������
*
* @method:    RadixSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/12  13:34 
*/

/*
�����������ó�����
��1����������Ҫ����Ҫ���Էָ�����ġ�λ������������λ֮���еݽ���ϵ��
	 ���a���ݵĸ�λ��b���ݴ���ʣ�µĵ�λ�Ͳ��ñȽ���
��2��ÿһλ�����ݷ�Χ����̫��Ҫ���������������㷨�����򣬷�����������ʱ�临�ӶȾ��޷�����O(n)��
*/
void RadixSort(int *arr, int nLen)
{
	int digit = GetMaxDigit(arr, nLen);
	int base = 1;
	int *temp = new int[nLen];
	while(digit--)
	{
		int Count[10] = {0};
		int index = 0;
		for(int i = 0;i < nLen; ++i)
		{
			index = (arr[i] / base) % 10;
			Count[index]++;
		}

		for(int i = 1;i < nLen; ++i)
		{
			Count[i] += Count[i - 1];
		}

		for(int i = nLen - 1;i >= 0; --i)//������һ������֮�󣬵�λ����Ķ���������
		{
			index = (arr[i] / base) % 10;
			temp[Count[index] -1] = arr[i];
			Count[index]--;
		}
		memcpy(arr, temp, sizeof(int)*nLen);
		//print(arr, nLen);
		base *= 10;
	}
	delete []temp;
	
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
	int arr[10] = {15, 4, 13, 33, 23, 24, 5, 83, 19, 74};
	int arr1[10] = {1,1,1,1,1,1,1,1,1,1};
	int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr3[10] = {10,9,8,7,6,5,4,3,2,1};
	print(arr, sizeof(arr)/sizeof(arr[0]));
	RadixSort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;

	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	RadixSort(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	cout << endl;

	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	RadixSort(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	cout << endl;

	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	RadixSort(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));

	return 0;
}