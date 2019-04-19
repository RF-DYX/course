#include "Sort.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

SortClass::SortClass(void)
{
	memset(arr, 0, sizeof(arr));
	memcpy(temparr, arr, sizeof(temparr));
}

SortClass::~SortClass(void)
{
}
/********************************************************************
* @brief : 		��ʼ�����飬��������
* @author : 	dyx
* @date : 		2019/4/19
* @version : 	
* @inparam :	NUM_SIZE �ܹ���Ҫ���������
* @outparam : 
*********************************************************************/
void SortClass::RandNum()
{
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		//arr[i] = rand()%NUM_SIZE +1;		// Ϊ�������ݳ�ʼ������
		arr[i] = rand()%50 + 1;				// רΪ���������ʼ������
	}
}
/********************************************************************
* @brief : 		����һ����ʱ����temparr����������ԭ������Ȼ����
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::InitTempArr()
{
	memcpy(temparr, arr, sizeof(temparr));
}
/********************************************************************
* @brief : 		����
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
inline void SortClass::swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/********************************************************************
* @brief : 		ð�����򣬴�С����ʱ�临�Ӷ�O(n^2), �ȶ����򣬿ռ临�Ӷ�0
* @author : 	dyx
* @date : 	
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::Bobble()
{
	int temp = 0;
	bool flag = true;
	for (int i = 0; i < NUM_SIZE - 1; ++i)
	{
		flag = true;
		for (int j = 0; j < NUM_SIZE - 1 - i; ++j)
		{
			if (temparr[j] > temparr[j+1])
			{
				swap(temparr[j], temparr[j+1]);
				flag = false;
			}
		}
		if (flag)
		{
			break;
		}
	}
}
/********************************************************************
* @brief : 		�������򣬴�С����ʱ�临�Ӷ�O(n^2), �ȶ����򣬿ռ临�Ӷ�0����ð������
* @author : 	dyx
* @date : 		 
* @version : 	 
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::InsertArr()
{
	int preIndex, current;
	for (int i = 1; i < NUM_SIZE; ++i)
	{
		preIndex = i-1;
		current = temparr[i];
		while(preIndex >= 0 && temparr[preIndex] > current)
		{
			temparr[preIndex + 1] = temparr[preIndex];
			--preIndex;
		}
		temparr[preIndex+1] = current;
	}
}
/********************************************************************
* @brief : 		ѡ�����򣬴�С����ʱ�临�Ӷ�O(n^2), ���ȶ����漰�����������ռ临�Ӷ�0
* @author : 	dyx
* @date : 		 
* @version : 	 
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::Select()
{
	int index;
	int i, j;
	for (j = 0; j < NUM_SIZE - 1; ++j)
	{
		index = j;
		for (i = j + 1; i < NUM_SIZE; ++i)
		{
			if (temparr[i] < temparr[index])
			{
				index = i;
			}
		}
		swap(temparr[index], temparr[j]);
	}
}
/********************************************************************
* @brief : 		�鲢���򡪡��鲢����[O(nlogn), ��ԭ������]
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::MergeSort(int *data, int start, int end, int *result)
{
	if (1 == end - start)		// ��������� ֻ������Ԫ�أ����������Ԫ�ؽ�������
	{
		if (data[start] > data[end])
		{
			int temp = data[start];
			data[start] = data[end];
			data[end] = temp;
		}
		return;
	}
	else if (0 == end - start)		// ֻ��һ��Ԫ�أ�������
	{
		return;
	}
	else
	{
		// �������������䣬�ֱ�����������������
		MergeSort(data, start, (end - start +1)/2+start, result);
		MergeSort(data, (end - start +1)/2+start+1, end, result);
		// ��ʼ�鲢�Ѿ��ź����start��end֮�������
		Merge(data, start, end, result);
		// �����������ݸ��Ƶ�ԭʼ������ȥ
		for (int i = start; i <= end; ++i)
		{
			data[i] = result[i];
		}
	}
}
/********************************************************************
* @brief : 		�鲢���򡪡��鲢
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::Merge(int *data, int start, int end, int *result)
{
	int left_len = (end - start + 1)/2 +1;		// ���Ԫ�ظ���
	int left_index = start;
	int right_index = start + left_len;
	int result_index = start;
	while(left_index < start + left_len && right_index < end+1)
	{
		// ���Ѿ��ź��������������кϲ�
		if (data[left_index] <= data[right_index])
		{
			result[result_index++] = data[left_index++];
		}
		else
			result[result_index++] = data[right_index++];
	}
	while(left_index < start + left_len)
		result[result_index++] = data[left_index++];
	while(right_index < end +1)
		result[result_index++] = data[right_index++];
}
/********************************************************************
* @brief : 		ϣ�����򣬴�С�����ȶ���0(n^2),�����ڲ�������
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::Shell()
{
	int gap = NUM_SIZE/2;
	int temp;
	int preIndex;
	while (gap > 0)
	{
		for (int i = gap; i < NUM_SIZE; ++i)
		{
			temp = temparr[i];
			preIndex = i - gap;
			while(preIndex >= 0 && temparr[preIndex] > temp)
			{
				temparr[preIndex + gap] = temparr[preIndex];
				preIndex -= gap;
			}
			temparr[preIndex+gap] = temp;
		}
		gap/=2;
	}
}
/********************************************************************
* @brief : 		�������򡪡����е㣬����С���ң���
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
int SortClass::Partition(int *Qarr, int left, int right)
{
	int i = left;
	int j = right;
	int temp = Qarr[i];		// �ݴ��ڱ�
	while(i < j)
	{
		while (i < j && Qarr[j] >= temp)
		{	
			j--;
			if (i < j)
			{
				Qarr[i] = Qarr[j];
			}
			//j--;
		}
		while(i < j && Qarr[i] <= temp)
		{	
			i++;
			if (i < j)
			{
				Qarr[j] = Qarr[i];
			}
			//i++;
		}
	}
	Qarr[i] = temp;
	return i;
}
/********************************************************************
* @brief : 		�������򡪡����� O(nlogn)�����ȶ���ԭ������
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
//��������
void SortClass::QuickSort(int *Qarr, int left, int right)
{
	int dp; // ��¼�е�
	if (left < right)
	{
		dp = Partition(Qarr, left, right);
		QuickSort(Qarr, left, dp);
		QuickSort(Qarr, dp + 1, right);
	}
}
/********************************************************************
* @brief : 		Ͱ���򡪡�����������Ĳ���Ͱ��(С����)���õ�������ʵ��
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
ListNode *SortClass::Insert(ListNode *head, int val)
{
	ListNode dummyNode;		// ͷ���֮ǰ���ڱ�,
	ListNode *newNode = new ListNode;
	newNode->mData = val;
	newNode->pNext = NULL;
	dummyNode.pNext = head;
	ListNode *pre, *curr;
	pre = &dummyNode;
	curr = head;
	while (NULL != curr && curr->mData <= val)
	{
		pre = curr;
		curr = curr->pNext;
	}
	newNode->pNext = curr;
	pre->pNext = newNode;
	return dummyNode.pNext;
}
/********************************************************************
* @brief : 		Ͱ���򡪡��ϲ�Ͱ
* @author : 	dyx
* @date : 		 
* @version : 	 
* @inparam : 
* @outparam : 
*********************************************************************/
ListNode *SortClass::MergeBucket(ListNode *head1, ListNode *head2)
{
	ListNode dummyNode;
	ListNode *dummy = &dummyNode;
	while(NULL != head1 && NULL != head2)
	{
		if (head1->mData <= head2->mData)
		{
			dummy->pNext = head1;
			head1 = head1->pNext;
		}
		else
		{
			dummy->pNext = head2;
			head2 = head2->pNext;
		}
		dummy = dummy->pNext;
	}
	if (NULL != head1)
	{
		dummy->pNext = head1;
	}
	if(NULL != head2)
	{
		dummy->pNext = head2;
	}
	return dummyNode.pNext;
}
/********************************************************************
* @brief : 		Ͱ���򡪡�����O(n)  ����ԭ�������ȶ����ʺ϶����������ҷ�ΧС����������
* @author : 	mark
* @date : 		$YEAR$/$MONTH$/$DAY$ $HOUR$:$MINUTE$
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::BucketSort(int *Barr, int n)
{
	vector<ListNode*> bucket(BUCKET_NUM, (ListNode*)(0));
	int min = Barr[0];
	int max = Barr[0];
	for (int i = 1; i < NUM_SIZE; ++i)
	{
		if (min > Barr[i])
		{
			min = Barr[i];
		}
		else if (max < Barr[i])
		{
			max = Barr[i];
		}
	}

	int dis = (max - min)/n + 1;
	int j;
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		ListNode *head;
		j = 0;
		while(Barr[i] >= min)
		{
			if (Barr[i] <= (min + (j + 1)*dis))
			{
				head = bucket.at(j);
				bucket.at(j) = Insert(head, Barr[i]);
				break;
			}
			else
				++j;
		}
	}

	ListNode *head = bucket.at(0);
	for (int i = 1; i < BUCKET_NUM; ++i)
	{
		head = MergeBucket(head, bucket.at(i)); 
	}
	for (int i = 0; i < NUM_SIZE && head != NULL; ++i)
	{
		Barr[i] = head->mData;
		head = head->pNext;
	}
}
/********************************************************************
* @brief : 		��������O(n+k),k�����ݷ�Χ,�ȶ�������ԭ�������ʺ϶����������ҷ�ΧС����������
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::CountSort(int *arr)
{
	// ��������
	int max = arr[0];
	for (int i = 1; i < NUM_SIZE; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	// ���C����
	int *C = new int [max + 1];
	memset(C, 0, sizeof(int)*(max+1));
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		C[arr[i]]++;
	}
	// ֱ�Ӹ��Ƶ�arr, ���ȶ�
	int j = 0;
	for (int i = 0; i <= max; ++i)
	{
		while (C[i] != 0)
		{
			arr[j] = i;
			++j;
			--C[i];
		}
	}
}
/********************************************************************
* @brief : 		�������򡪡��ҵ�������
* @author : 	
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
int SortClass::GetMaxDigit(int *arr, int len)
{
	int digit = 1;
	int base = 10;
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] >= base)
		{
			++digit;
			base*=10;
		}
	}
	return digit;
}
/********************************************************************
* @brief : 		�������򡪡������ʺϵ绰��������ַ��������򣬵�λ��������0
*						�м��õ�Ͱ����ķ���������ԭ�������ȶ��� O(dn),d��ά��
* @author : 	
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::RadixSort(int *arr, int len)
{
	int digit = GetMaxDigit(arr, len);
	int base = 1;
	int *temp = new int[len];
	while(digit--)
	{
		int Count[10] = {0};
		int index = 0;
		for (int i = 0; i < len; ++i)	// �������һλ�Ĵ�С��Ȼ����бȽ�
		{
			index = (arr[i] / base) % 10;
			Count[index]++;
		}
		//���
		for (int i = 1; i < 10; ++i)
		{
			Count[i] += Count[i-1];
		}
		for (int i = len - 1; i >= 0; --i)		// ������һ������֮�󣬵�λ����Ķ���������
		{
			index = (arr[i] / base) %10;
			temp[Count[index] - 1] = arr[i];
			Count[index]--;
		}
		memcpy(arr, temp, sizeof(int)*len);
		base *= 10;
	}
	delete [] temp;
}
/********************************************************************
* @brief : 		��ӡԭʼ����arr
* @author : 	
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::Print()
{
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		if(i%20 == 0)
			cout << endl;
		cout << arr[i] << "  ";
	}
}
/********************************************************************
* @brief : 		��ӡ����֮�������temparr
* @author : 	
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::PrintSort()
{
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		if(i%20 == 0)
			cout << endl;
		cout << temparr[i] << "  ";
	}
}
