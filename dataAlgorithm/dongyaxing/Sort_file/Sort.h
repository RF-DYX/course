#ifndef _SORT_H
#define _SORT_H
#include <iostream>
#include <vector>
#define NUM_SIZE 500		// ��Ҫ������������
#define BUCKET_NUM 10		// 10��Ͱ
using namespace std;
/********************************************************************
* @brief : 		����Ͱ����
* @author : 	dyx
* @date : 		2019/4/19
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
struct ListNode
{
	ListNode* pNext;
	int mData;
};

class SortClass
{
//private:
public:
	int arr[NUM_SIZE];
	int temparr[NUM_SIZE];
public:
	SortClass(void);
	~SortClass(void);

	void RandNum();
	void InitTempArr();

	void Bobble();			// ð������
	void InsertArr();		// ��������
	void Select();			// ѡ������

	void Merge(int *data, int start, int end, int *result);
	void MergeSort(int *data, int start, int end, int *result);		// �鲢����

	void Shell();			// ϣ������

	int Partition(int *arr, int left, int right);
	void QuickSort(int *arr, int left, int right);		// ��������

	void Partition_2(int *arr, int left, int right, int &sentinel, int &offset);
	void QuickSort_2(int *arr, int left, int right);		// �Ľ��Ŀ���

	void CountSort(int *arr);		// ��������

	ListNode *Insert(ListNode *head, int val);		// ����Ͱ
	ListNode *MergeBucket(ListNode *head1, ListNode *head2);	// �鲢Ͱ
	void BucketSort(int *arr, int n);		// Ͱ����

	int GetMaxDigit(int *arr, int len);
	void RadixSort(int *arr, int len);		// ��������

	void HeapSort();		// ������

	void Print();
	void PrintSort();
	

private:
	inline void swap(int &a, int &b);
	ListNode *mNode;
};

#endif
