/*
* Copyright: (c) 2019
*
* �ļ�����:  CountSort.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/12  11:00
*/

#include <iostream>


using namespace std;
void print(int *arr, int nLen);

/**
* @brief	  ��������(�ð汾���ݶ��Ǵ�0��ʼ�洢�Ļ��˷Ѻܶ�ռ䣬����ʵ�ֲ��и���)
*
* @method:    CountSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/12  11:01 
*/

/*
����������Ͱ�����һ����������Ͱ�ĸ�����Ԫ�ط�Χ��ͬ��
���Ͱ�ı�ž���Ԫ�ص�ֵ��Ͱ�ڴ洢���Ǹ�Ԫ�س��ֵĴ�����
��������Ӧ�ó�����
��1�����ݷ�Χ���Ǻܴ�ĳ����У�������ݷ�Χk��Ҫ���������n��ܶ࣬�ǾͲ��ʺ��ü�������̫�˷ѿռ�
��2�����ݾ�Ϊ�Ǹ����������Ҫ������������������ͣ�Ҫ�����ڲ��ı���Դ�С������£�ת��Ϊ�Ǹ�����
*/
void CountSort(int *arr, int nLen)
{
	if(nLen <= 1)
		return;
	//ȷ�����ݵķ�Χ
	int maxvalue = arr[0];
	for(int i = 1;i < nLen; ++i)
	{
		maxvalue = maxvalue >= arr[i] ? maxvalue : arr[i];
	}

	//����һ����̬���飬������¼ÿ�����ݳ��ֵĴ���
	int *countTimes = new int[maxvalue + 1];
	//memset(countTimes, 0, sizeof(int) * (maxvalue + 1));
	for(int i = 0;i <= maxvalue; ++i)
	{
		countTimes[i] = 0;
	}

	for(int i = 0;i < nLen; ++i)
	{
		countTimes[arr[i]]++;
	}
	//��������Ԫ�ص�ֵ����¼���������������е�λ��
	for(int i = 1;i <= maxvalue; ++i)
	{
		countTimes[i] += countTimes[i - 1];
	}

	//������ʱ���������洢�����Ľ��
	int *ResultArr = new int[nLen];
	//for(int i = nLen - 1;i >=0; --i)
	for(int i = 0;i < nLen; ++i)
	{
		ResultArr[countTimes[arr[i]] -1] = arr[i];
		countTimes[arr[i]]--;
	}

	//���������鸳ֵ������������
	memcpy(arr, ResultArr, sizeof(int) * nLen);

	//�ͷŶ�̬����
	delete []countTimes;
	delete []ResultArr;
}

void CountSort2(int *arr, int nLen)
{
	if(nLen < 2)
		return;
	int maxvalue = arr[0];
	int minvalue = arr[0]; 
	for(int i = 1; i < nLen; ++i)
	{
		maxvalue = maxvalue < arr[i] ? arr[i] : maxvalue;
		minvalue = minvalue > arr[i] ? arr[i] : minvalue;
	}

	int *ptemp = new int[maxvalue - minvalue + 1];
	memset(ptemp, 0, sizeof(int) * (maxvalue - minvalue + 1));
	int Index = 0;
	for(int i = 0; i < nLen; ++i)
	{
		Index = arr[i] - minvalue;
		ptemp[Index]++;
	}
	//print(ptemp, maxvalue - minvalue + 1);
	int j = 0;
	for(int i = minvalue; i <= maxvalue; ++i)
	{
		while(ptemp[i - minvalue]--)
		{
			arr[j] = i;
			j++;
		}
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
	int arr4[10] = {15, 4, 13, 33, 23, 24, 5, 83, 19, 74};
	print(arr, sizeof(arr)/sizeof(arr[0]));
	CountSort2(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;

	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	CountSort2(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	cout << endl;

	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	CountSort2(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	cout << endl;

	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	CountSort2(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	cout << endl;

	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	CountSort2(arr4,sizeof(arr4)/sizeof(arr4[0]));
	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	return 0;
}
