#include <iostream>
using namespace std;
// �ݹ飬��ȵ�40������Ҫ7s�����
unsigned int step_1(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
		return step_1(n-1) + step_1(n-2);
}
// ͨ��arr��¼̨��������ʹn=118��Ҳ��˲��������
unsigned int step_2(int n, unsigned int *arr)
{
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	if (arr[n] > 0)
	{
		return arr[n];
	}
	if (n == 1 || n == 0)
	{
		return arr[1];
	}
	else if (n == 2)
	{
		return arr[2];
	}
	else
	{
		arr[n] = step_2(n-1, arr) + step_2(n-2, arr);
	}
	return	arr[n];
}
// ��ѭ��ʵ��
unsigned int step_3(int n)
{
	unsigned int sum;
	unsigned int a = 1, b = 2;
	if (n == 0 || n ==1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
	{
		for (int i = 3; i <= n; ++i)
		{
			sum = a + b;
			a = b;
			b = sum;
		}
		return sum;
	}
}
// ����(��ż)������
/*
����������Ϊ��ţ�ż������Ϊ�ҽţ�ÿ��������š�
n = 1   f��(1) = 1		fż(1) = 0
n = 2	f��(2) = 1		fż(2) = 1
n = 3	f��(3) = 1		fż(3) = 2
n = 4	f��(4) = 3		fż(4) = 2
���ɣ�
	f��(n) = fż(n - 1) + fż(n - 2)
	fż(n) = f��(n - 1) + f��(n - 2)
*/
// ��������ҽŵ���
unsigned int step_4(size_t n)
{
	int left_1 = 1, left_2 = 1;
	int right_1 = 0, right_2 = 1;
	int left = 0;
	int right = 0;
	if (n == 1)
	{
		return right_1;
	}
	else if (n == 2)
	{
		return right_2;
	}
	else
	{
		for (size_t i = 3; i <= n; ++i)
		{
			right = left_1 + left_2;

			left = right_1 + right_2;

			left_1 = left_2;
			left_2 = left;

			right_1 = right_2;
			right_2 = right;
		}
		return right;
	}
}
int main()
{
	std::cout << "������̨������ " ;
	int n;
	cin >> n;
	cout << "��̨���� " << step_1(n) << " �ַ�����" << endl << endl;

	unsigned int arr[110] = {0};	// �˴������鳤�ȣ�Ӧ�ô�������� n���ұ����ʼ��0
	cout << "��̨���� " << step_2(n, arr) << " �ַ�����" << endl << endl;

	cout << "��̨���� " << step_3(n) << " �ַ�����" << endl << endl;
	cout << "��ſ�ʼ���ҽŵ����̨���� " << step_4(n) << " �ַ�����" << endl << endl;
//	system("pause");
	return 0;
}
