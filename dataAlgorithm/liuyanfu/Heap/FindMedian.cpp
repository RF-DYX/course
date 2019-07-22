/*
* Copyright: (c) 2019
*
* �ļ�����:  FindMedian.cpp	
* �ļ���ʶ��
* ժ	Ҫ����������λ����������Է����ֳ���
*			��1����һ�龲̬�����е���λ��
*			��2����һ�鶯̬�����е���λ��
*	���ھ�̬���ݶ��ԣ�����ֻ��Ҫ�������Ƚ�������ʱ�临�Ӷ���O(nlogn),���ҵ���λ��ʱ�临�Ӷ�ΪO(1);
*	���ڶ�̬���ݶ��ԣ����ÿ����һ�����ݶ������ݽ�������֮���ٻ�ȡ��λ�������ʱ�临�ӶȽ���O(nlogn * n),
*	��Ȼ���ܽ��ܣ�������ǲ��öѵķ������������⣬����ֻ��Ҫά�������ѣ�һ��Ϊ�󶥶ѣ�һ��ΪС���ѣ�
*	Ҫ��֤�󶥶ѵĶѶ�Ԫ��С��С���ѵĶѶ�Ԫ�أ�������֮��ĸ���������1��ͨ�����ַ�ʽ����ȡ��̬������
*	����λ����ʱ�临�Ӷ���O(nlogn)
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/6/12  15:37
*/

#include "FindMedian.h"


FindMedian::FindMedian(void)
{
}


FindMedian::~FindMedian(void)
{
}


/**
* @brief	��̬ά��һ���󶥶�max_heap��һ��С����min_heap���������Ѹ��Դ�š�һ�롱���ݣ�
*			�����һ����ָ�����ѵ�size()���С�ڵ���1����ά��max_heap�ĶѶ� <= min_heap�ĶѶ�
*
* @method:    addNum
* @access:    public 
* @param:     const int & data
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/12  14:49 
*/
void FindMedian::addNum(const int& data)
{
	if(max_heap.empty())
	{
		max_heap.heap_push(data);
		return;
	}
	if(max_heap.size() == min_heap.size())
	{
		if(data < max_heap.heap_top())
		{
			max_heap.heap_push(data);
			return;
		}
		else
		{
			min_heap.heap_push(data);
			return;
		}
	}
	else if(max_heap.size() > min_heap.size())
	{
		if(data < max_heap.heap_top())
		{
			min_heap.heap_push(max_heap.heap_top());
			max_heap.heap_pop();
			max_heap.heap_push(data);
			return;
		}
		else
		{
			min_heap.heap_push(data);
			return;
		}
	}
	else
	{
		if(data < min_heap.heap_top())
		{
			max_heap.heap_push(data);
			return;
		}
		else
		{
			max_heap.heap_push(min_heap.heap_top());
			min_heap.heap_pop();
			min_heap.heap_push(data);
			return;
		}
	}
}


/**
* @brief
*
* @method:    findMedian
* @access:    public 
* @Return:    int
* @author:    RF_LYF
* @since:   2019/6/12  15:10 
*/
int FindMedian::findMedian()
{
	if(max_heap.size() >= min_heap.size())
		return max_heap.heap_top();
	else
		return min_heap.heap_top();		
}