#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

// ����ŷ����þ���
int Vector(int *arr1, int *arr2, int len)
{
	int d = 0;
	for (int i = 0; i < len; ++i)
	{
		d += (arr1[i] - arr2[2])*(arr1[i] - arr2[2]);
	}
	return (int)sqrt((double)d);
}
// �ҳ����ƶ���ߵ���
int similar(int *arr, int len)
{
	int max = 0;
	int index = 0;
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}
	return index;
}

int main()
{
	// �����index,��Ӧ�ĸ�������
	// ����arr[index]��ֵ����Ӧϲ���̶�
	// �ҳ���zhang���͸�����ζ�����Ƶ�
	string songs[5] = {"love", "lonely", "hero", "she", "you"};
	char ch[5] = {'a', 'b', 'c', 'd', 'e'};
	int a[5] = {4,2,-1,0,1};
	int b[5] = {2,-1,3,0,5};
	int c[5] = {1,4,1,0,5};
	int d[5] = {0,4,-1,2,1};
	int e[5] = {4,0,3,3,-1};
	int result[4];
	result[0] = Vector(a, b, 5);
	result[1] = Vector(a, c, 5);
	result[2] = Vector(a, d, 5);
	result[3] = Vector(a, e, 5);

	int index = similar(result, 4);
	
	cout << "��a��ζ���Ƶ��ǣ� " << ch[index + 1] << endl;

//	system("pause");
	return 0;
}
