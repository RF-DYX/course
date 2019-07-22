#include <iostream>
#include <list>

using namespace std;

int result[8] = {0};
int count = 0;

bool isOk(int row, int column)
{
	for(int i = row - 1; i >= 0; --i)
	{
		if(i + result[i] == row + column) //֤�����Ϸ��Ѿ������˻ʺ� ֱ�߷���y = -x + b;
			return false;
		if(result[i] - i == column - row) //֤�����Ϸ��Ѿ������˻ʺ� ֱ�߷���y = x + b;
			return false;
		if(result[i] == column) //֤����ǰ�е����Ϸ��Ѿ������˻ʺ�
			return false;
	}
	return true;
}


void print()
{
	for(int row = 0; row < 8; ++row)
	{
		int column;
		for(column = 0; column < result[row]; ++column)
		{
			cout << "0";
		}
		cout << "#";
		for(column = result[row] + 1; column < 8; ++column)
			cout << "0";
		cout << endl;
	}
	cout << "========" << endl;
}


void cal8Queen(int row)
{
	for(int j = 0; j < 8; ++j)
	{
		if(isOk(row, j))
		{
			result[row] = j;
			if(row == 7)
			{
				++count;
				print();
				result[row] = 0;
				return;
			}
			cal8Queen(row + 1);
			result[row] = 0;
		}

	}
}


int main()
{
	cal8Queen(0);
	cout << "�ڷŵķ�ʽ�� " << count << "��" << endl;
	return 0;
}