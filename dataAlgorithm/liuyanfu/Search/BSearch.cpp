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


/**
* @brief      ���ҵ�һ��ֵ���ڸ���ֵ��Ԫ��
*
* @method:    bsearchfirst
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @param:     int value
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/19  21:44 
*/
int bsearchfirst(int *arr, int nLen, int value)
{
	int low = 0;
	int high = nLen - 1;
	int mid = 0;
	while(low <= high)
	{
		mid = low + (high - low) >> 1;
		if(arr[mid] > value)
			high = mid - 1;
		else if(arr[mid] < value)
			low = mid + 1;
		else
		{
			if(mid == 0 || arr[mid - 1] != value)
				return mid;
			else
				high = mid - 1;
		}
	}
	return -1;
}



/**
* @brief	  �������һ��ֵ���ڸ���ֵ��Ԫ��
*
* @method:    bsearchlast
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @param:     int value
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/19  21:47 
*/
int bsearchlast(int *arr, int nLen, int value)
{
	int low = 0;
	int high = nLen - 1;
	int mid = 0;
	while(low <= high)
	{
		mid = low + (high - low) >> 1;
		if(arr[mid] > value)
			high = mid - 1;
		else if(arr[mid] < value)
			low = mid + 1;
		else
		{
			if(mid == nLen -1 || arr[mid + 1] != value)
				return mid;
			else
				low = mid + 1;
		}
	}
	return -1;
}


/**
* @brief	���ҵ�һ�����ڵ��ڸ���ֵ��Ԫ��
*
* @method:    bsearchfirstge
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @param:     int value
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/19  22:13 
*/
int bsearchfirstge(int *arr, int nLen, int value)
{
	int low = 0;
	int high = nLen - 1;
	int mid = 0;
	while(low <= high)
	{
		mid = low + (high - low) >> 1;
		if(arr[mid] < value)
			low = mid + 1;
		else
		{
			if(mid == 0 || arr[mid -1] < value)
				return mid;
			else
				high = mid - 1;
		}		
	}
	return -1;
}


/**
* @brief	�������һ��С�ڵ��ڸ���ֵ��Ԫ��
*
* @method:    bsearchlastle
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @param:     int value
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/19  22:23 
*/
int bsearchlastle(int *arr, int nLen, int value)
{
	int low = 0;
	int high = nLen - 1;
	int mid = 0;
	while(low <= high)
	{
		mid = low + (high - low) >> 1;
		if(arr[mid] > value)
			high = mid - 1;
		else
		{
			if(mid == nLen - 1 || arr[mid + 1] > value)
				return mid;
			else
				low = mid + 1;
		}
	}
	return -1;
}