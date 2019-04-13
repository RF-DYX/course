#ifndef _TEST_H
#define _TEST_H
#include <iostream>
#define NUM_SIZE 500

using namespace std;

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
	void MergeSort(int *data, int start, int end, int *result);

	void Shell();			// ϣ��

	void Print();
	void PrintSort();
	

private:
	inline void swap(int &a, int &b);
};

#endif
