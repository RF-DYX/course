#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include "BinarySearch.h"
using namespace std;


int main()
{
	std::cout << "�������ƽ������" << endl << endl;
	double val1 = 15.0;
	double val2 = 0.6;
	double val3 = 49.0;
	double val4 = 0.7;
	std::cout << "������⣺"<< endl;
	std::cout << val1 << "��ƽ������ : "  <<FindRoot(val1) << endl;
	std::cout << val2 << "��ƽ������ : " <<FindRoot(val2) << endl;
	std::cout << val3 << "��ƽ������ : " <<FindRoot(val3) << endl;
	std::cout << val4 << "��ƽ������ : " <<FindRoot(val4) << endl << endl << endl;
	std::cout << "��ʽ���:"<< endl;
	std::cout << val1 << "��ƽ������ : " <<fixed << setprecision (7) <<Squre(val1) << endl;
	std::cout << val2 << "��ƽ������ : " <<fixed << setprecision (7) <<Squre(val2) << endl;
	std::cout << val3 << "��ƽ������ : " <<fixed << setprecision (7) <<Squre(val3) << endl;
	std::cout << val4 << "��ƽ������ : " <<fixed << setprecision (7) <<Squre(val4) << endl << endl;


	int arr[20] = {1,2,3,4,5,6,7,8,8,8,9,9,10,10,11,12,14,14,15,16};
	std::cout << "�������У�����ĳ�������������±꣺" << endl;
	std::cout << "�������飺" <<endl;
	for (int i = 0; i < 20; ++i)
	{
		std::cout << arr[i] << "  ";
	}
	cout << endl << endl;

	cout << "����һ��8������������"<< BioSearch(arr, 20, 8) << endl;
	cout << "����һ��13������������"<< BioSearch(arr, 20, 13) << endl << endl;

	cout << "���ҵ�һ��8��˳����ң�������������" << BioSearch_1(arr, 20, 8) << endl;
	cout << "���ҵ�һ��8�����ֲ��ң�������������" << BioSearch_2(arr, 20, 8) << endl;
	cout << "�������һ��ֵ8������������" << BioSearch_3(arr, 20, 8) << endl << endl;

	cout << "���ҵ�һ�����ڵ��ڸ���ֵ��Ԫ�أ�����������" << BioSearch_4(arr, 20, 13) << endl;
	cout << "�������һ��С�ڵ��ڸ���ֵ��Ԫ�أ�����������" << BioSearch_5(arr, 20, 13) << endl;

//	system("pause");
	return 0;
}
