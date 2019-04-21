/*
* Copyright: (c) 2019
*
* �ļ�����:  BSearchCycle.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/17  23:10
*/



/**
* @brief
*
* @method:    BSearchCycle
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int right
* @param:     int findNum
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/17  23:15 
*/
int BSearchCycle(int *arr, int low, int high, int value)
{
	int mid = 0;
	while(low <= high)
	{
		mid = low + (high - low) >> 1;
		if(arr[mid] == value)
			return mid;
		else if(arr[mid] > value)
			high = mid -1;
		else
			low = mid + 1;
	}
	return -1;
}


/**
* @brief
*
* @method:    BSearchRecursive
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int right
* @param:     int value
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/17  23:19 
*/
int BSearchRecursive(int *arr, int low, int high, int value)
{
	int mid = low + (high - low) >> 1;
	if(low > high)
		return -1;
	if(arr[mid] == value)
		return mid;
	else if(arr[mid] < value)
		BSearchRecursive(arr, mid + 1, high, value);
	else
		BSearchRecursive(arr, low, mid - 1, value);
}