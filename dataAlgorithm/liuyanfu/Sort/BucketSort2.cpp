/*
* Copyright: (c) 2019
*
* �ļ�����:  BucketSort.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/11  11:22
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* @brief
*
* @method:    compare
* @access:    public 
* @param:     const void * a
* @param:     const void * b
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/12  10:13 
*/
int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}


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
	double minvalue = arr[0];
	double maxvalue = arr[0];
	for(int i = 1;i < nLen; ++i)
	{
		maxvalue = maxvalue >= arr[i] ? maxvalue : arr[i];
		minvalue = minvalue <= arr[i] ? minvalue : arr[i];
	}
	//Ͱ�ĸ���
	int BucketNum = nLen;

	//����Ͱ�ռ�洢Ԫ��
	vector<vector<int> > bucketspace(BucketNum, 0);

	int index = 0;//����Ͱ�ı��

	//ɨ�������е����ݣ��ֱ���ڶ�Ӧ��ŵ�Ͱ��
	for(int i = 0; i< nLen; ++i)
	{
		index = (int)(arr[i] - minvalue)/(maxvalue - minvalue + 1) * BucketNum;//��1��Ϊ�˱�֤Ͱ�ı��С��BucketNum
		bucketspace[index].push_back(arr[i]);
	}

	//��ÿ��Ͱ�ڵ�Ԫ�ؽ�������,�������ݸ�ֵ���������������
	int startpos = 0;
	for(size_t i = 0; i < bucketspace.size(); ++i)
	{
		if(bucketspace[i].empty())
			continue;
		qsort(&bucketspace[i][0], bucketspace[i].size(), sizeof(bucketspace[i][0]), compare);
		memcpy(&arr[startpos],&bucketspace[i][0], sizeof(bucketspace[i][0]) * bucketspace[i].size());
		startpos += bucketspace[i].size();
	}

	////��סͰ�ı����С�������ν�ÿ��Ͱ�ڵ�Ԫ�ظ�ֵ���������������
	//int startpos = 0;
	//for(size_t i = 0; i < bucketspace.size(); ++i)
	//{
	//	if(bucketspace[i].empty())
	//		continue;
	//	memcpy(&arr[startpos],&bucketspace[i][0], sizeof(bucketspace[i][0]) * bucketspace[i].size());
	//	startpos += bucketspace[i].size();
	//}
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
	int arr4[10] = {1,99,29,38,69,69,65,32,21,30};
	print(arr, sizeof(arr)/sizeof(arr[0]));
	BucketSort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;

	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	BucketSort(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	cout << endl;

	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	BucketSort(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	cout << endl;

	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	BucketSort(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	cout << endl;

	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	BucketSort(arr4,sizeof(arr4)/sizeof(arr4[0]));
	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	return 0;
}