/*
* Copyright: (c) 2019
*
* �ļ�����:  BucketSort2.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/22  9:38
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
void print(int *arr, int nLen);
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

/**
* @brief	  ����ʵ�ֵ�Ͱ����
*
* @method:    BucketSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/22  9:40 
*/
void BucketSort(int *arr, int nLen)
{
	int maxvalue = arr[0];
	int minvalue = arr[0];
	for(int i = 1; i < nLen; ++i)
	{
		maxvalue = maxvalue < arr[i] ? arr[i] : maxvalue;
		minvalue = minvalue > arr[i] ? arr[i] : minvalue;
	}
	int bucketNum = nLen;
	//��Ϊ��Щ��ֵ���ܱ�nLen����������ÿ�����+1�����Ա�֤����Ԫ�ض���ֵ�Ͱ��
	int space = (maxvalue - minvalue) / nLen + 1;

	//���붯̬�����¼ÿ��Ͱ��Ԫ�صĸ���
	int *pCount = new int[bucketNum];
	int *pEndIndexofBucket = new int [bucketNum];
	memset(pCount, 0, sizeof(int) * bucketNum);
	memset(pEndIndexofBucket, 0, sizeof(int) * bucketNum);
	int Index = 0;
	for(int i = 0; i < nLen; ++i)
	{
		Index = (arr[i] - minvalue) / space;
		pCount[Index]++;
		pEndIndexofBucket[Index]++;
	}
	//print(pCount, bucketNum);

	//ȷ��ÿ��Ͱ����������
	for(int i = 1; i < bucketNum; ++i)
	{
		pEndIndexofBucket[i] += pEndIndexofBucket[i - 1];
	}
	//print(pEndIndexofBucket, bucketNum);

	//������Ԫ�ذ��շ�Ͱ֮��Ľ������һ����ʱ������
	int *temp = new int[nLen];
	for(int i = 0; i < nLen; ++i)
	{
		Index = (arr[i] - minvalue) / space;
		temp[--pEndIndexofBucket[Index]] = arr[i];
	}
	//print(temp, nLen);

	//��ÿ����Ͱ�ڵ����ݽ�������
	for(int i = 0; i < bucketNum; ++i)
	{
		if(pCount[i] != 0)
		{
			qsort(&temp[pEndIndexofBucket[i]], pCount[i], sizeof(int), cmp);
			//print(temp, nLen);
		}
	}

	memcpy(arr, temp, sizeof(int) * nLen);
}


/**
* @brief
*
* @method:    print
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/22  9:40 
*/
void print(int *arr, int nLen)
{
	for(int i = 0; i < nLen; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	int arr[10] = {2,5,3,0,2,3,0,3,12,1};
	int arr1[10] = {1,1,1,1,1,1,1,1,1,1};
	int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr3[10] = {10,9,8,7,6,5,4,3,2,1};
	int arr4[10] = {115,2,12,9,35,578,1009,892,93,8};
	print(arr, sizeof(arr)/sizeof(arr[0]));
	BucketSort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));

	printf("\n");
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	BucketSort(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));

	printf("\n");
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	BucketSort(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));

	printf("\n");
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	BucketSort(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));

	printf("\n");
	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	BucketSort(arr4,sizeof(arr4)/sizeof(arr4[0]));
	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	return 0;
}