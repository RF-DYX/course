/*
* Copyright: (c) 2019
*
* �ļ�����:  BucketSort.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/11  23:15
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
* @brief
*
* @method:    BucketSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/11  11:54 
*/


/**
* @brief
*
* @method:    compare
* @access:    public 
* @param:     const void * a
* @param:     const void * b
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/11  23:45 
*/
int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}


/**
* @brief	  ð������
*
* @method:    BubbleSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/9  10:40 
*/
void BubbleSort(int* arr, int nLen)
{
	int temp = 0;
	for(int i = 0;i < nLen - 1; ++i)
	{
		for(int j = 0;j < nLen - i - 1; ++j)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/*
Ͱ�����Ӧ�ó�����
��1���������ڻ��ֳɶ��Ͱ�����д���
��2��Ͱ��Ͱ֮������Ȼ�Ĵ�С˳��
��3��������ÿ��Ͱ�ķֲ������ȽϾ���
ʵ�ֹ��̣�
��1��ȷ��Ͱ�����ݵķ�Χ������С�����ֵ
��2��ȷ��Ҫ�����е����ݻ��ֵ�����Ͱ��
��3��ɨ���������ݣ������ݻ��ֵ���Ӧ��Ͱ��
��4���ֱ��ÿ��Ͱ�е����ݽ�������
��5���ӵ�һ��Ͱ��ʼ�����ν�Ͱ�ڵ����ݷ���������
*/

void BucketSort(int *arr, int nLen)
{
	int minvalue = arr[0];
	int maxvalue = arr[0];
	for(int i = 1;i < nLen; ++i)
	{
		maxvalue = maxvalue >= arr[i] ? maxvalue : arr[i];
		minvalue = minvalue <= arr[i] ? minvalue : arr[i];
	}

	if(maxvalue == minvalue)
		return;

	int BucketNum = nLen;//Ͱ�ĸ���
	vector<vector <int> > vv(BucketNum, 0);

	int index = 0;
	double width = (double)(maxvalue - minvalue + 1)/BucketNum;
	for(int i = 0;i < nLen; ++i)
	{
		index = (int)(arr[i] - minvalue)/width; 
		vv[index].push_back(arr[i]);
	}

	for(size_t i =0; i < vv.size(); ++i)
	{
		//qsort(&vv[i][0], vv[i].size(), sizeof(vv[0][0]),compare);
		if(vv[i].empty())
			continue;
		BubbleSort(&vv[i][0], vv[i].size());
	}

	int i = 0;
	while(i < nLen)
	{
		for(size_t m =0; m < vv.size(); ++m)
		{
			for(size_t n = 0; n < vv[m].size(); ++n)
			{
				arr[i++] = vv[m][n];
				if(i == nLen)
					break;
			}
			if(i == nLen)
				break;
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
	print(arr, sizeof(arr)/sizeof(arr[0]));
	BucketSort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;
	return 0;
}