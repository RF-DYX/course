/*
* Copyright: (c) 2019
*
* �ļ�����:  FindLoopArrIndex.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/23  23:03
*/

#include <iostream>
using namespace std;

/**
* @brief	��ѭ����������ֳɶ�����������ٷֱ���ж���
*
* @method:    FindLoopArrValue
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @param:     int value
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/23  23:04 
*/
int FindLoopArrValue(int *arr, int nLen, int value)
{
	int low = 0;
	int high = nLen - 1;
	int mid = 0;
	while(low <= high)
	{
		mid = low + ((high - low) >> 1);
		if(arr[mid] == value)
			return mid;
		if(arr[low] <= arr[mid])//֤���������
		{
			if(arr[low] <= value && arr[mid] > value)
				high = mid - 1;
			else
				low = mid + 1;
		}
		else//(mid, high)������ģ���Ϊ��arr[left] > arr[mid]ʱ��mid�϶������ֵλ�õĺ��
		{
			if(arr[mid] < value && arr[high] >= value)
				low = mid + 1;
			else
				high = mid - 1;
		}

	}
	return -1;
}


int main()
{
	int arr[] = {4,5,6,7,8,1,2,3};
	cout << FindLoopArrValue(arr, 8, 2) << endl;
	return 0;
}