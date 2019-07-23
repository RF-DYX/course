#include <iostream>
#include <set>
using namespace std;

#define MaxWeight 52
/****************************************************************
* @brief : 		0-1�������⣨���ݣ�
* @author : 	dyx
* @date : 		2019/7/23 14:46
* @version : 	ver 1.0
* @inparam : 
* @outparam :	���ѡ����ĸ���Ʒ
*****************************************************************/
int count = 0;
set<int> a;
void fill_1(int i, int curWeight, int *bag, int N, int &maxWeightInBag)
{
	//cout << ++count << endl;		// ���ڼ�¼�˳�����ݵ��õĴ���
	if (curWeight == MaxWeight || i == N)	// ������ļ��ޣ�������������Ʒ�������
	{
		if (curWeight > maxWeightInBag)		// �ж��Ƿ�Ȱ��ڵ�ֵ��
		{
			maxWeightInBag = curWeight;
		}
		return;
	}
	fill_1( i + 1, curWeight, bag, N, maxWeightInBag);	// ��ѡ��ǰi��Ʒ��curWeight������
	if (curWeight + bag[i] <= MaxWeight)	// ѡ��ǰi��Ʒ��curWeight����
	{
		//cout << bag[i] << endl;
		//a.insert(bag[i]);
		fill_1(i + 1, curWeight + bag[i], bag, N, maxWeightInBag);
	}
}


/****************************************************************
* @brief : 		0-1�������⣬���ÿ����Ʒ�ļ�ֵ
* @author : 	dyx
* @date : 		2019/7/23 15:04
* @version : 	ver 1.0
* @inparam : 
* @outparam :	
*****************************************************************/
void fill_2(int i, int curWeight, int curValue, int *bag, int *val, int N, int &weightInBag, int &maxVal)
{
	if (curWeight == MaxWeight || i == N)	// �ﵽ�������ޣ����������������Ʒ
	{
		if (curValue > maxVal)
		{
			maxVal = curValue;
			weightInBag = curWeight;
		}
		return;
	}
	fill_2(i + 1, curWeight, curValue, bag, val, N, weightInBag, maxVal);
	if (curWeight + bag[i] <= MaxWeight)
	{
		fill_2(i + 1, curWeight + bag[i], curValue + val[i],bag,val, N, weightInBag, maxVal);
	}
}


/****************************************************************
* @brief : 		0-1�������⣨�����Ż���
* @author : 	dyx
* @date : 		2019/7/23 15:48
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
bool memary[7][76];
int times = 0;
void fill_3(int i, int curWeight, int *bag, int N, int &weightInBag)
{
	//cout << ++times << endl;		// ���ڵ��ô˳�����ݵ��õĴ���
	if (curWeight == MaxWeight || i == N)
	{
		if (curWeight > weightInBag)
		{
			weightInBag = curWeight;
		}
		return;
	}
	//------��Ӵ洢֮�󣬼����˵��ô���---
	if (memary[i][curWeight])
	{
		return;
	}
	memary[i][curWeight] = true;
	//---^^^^--------------
	fill_3(i + 1, curWeight, bag, N, weightInBag);
	if (curWeight+bag[i] <= MaxWeight)
	{
		fill_3(i + 1, curWeight + bag[i], bag, N, weightInBag);
	}
}



/****************************************************************
* @brief : 		0-1������dp��
* @author : 	dyx
* @date : 		2019/7/23 16:36
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
bool states[7][MaxWeight + 1];		// Ĭ��false
int fill_dp(int *bag, int N)
{
	states[0][0] = true;	// ��һ����������
	if (bag[0] <= MaxWeight)
	{
		states[0][bag[0]] = true;		// ��һ����Ʒ��
	}
	for (int i = 1; i < N; ++i)		// ��̬�滮״̬ת��
	{
		for (int j = 0; j <= MaxWeight; ++j)	// ���ѵ�i����Ʒ���뱳��
		{
			if (states[i - 1][j] == true)
			{
				states[i][j] = states[i - 1][j];	// ����һ�е�״̬����������i������Ʒ��
			}
		}
		for (int j = 0; j + bag[i] <= MaxWeight; ++j)
		{
			if (states[i - 1][j] == true)
			{
				states[i][j + bag[i]] = true;		// �ѵ�i����Ʒ���뱳��
			}
		}
	}
	for (int i = MaxWeight; i >= 0; --i)	// �����һ�У��Ӻ���ǰ�����صı�������Ʒ�����
	{
		if (states[N - 1][i] == true)
		{
			return i;
		}
	}
	return 0;
}

/****************************************************************
* @brief : 		0-1�������⣬�Ż��ռ䣬ʹ��һά����
* @author : 	dyx
* @date : 		2019/7/23 18:47
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
bool states_2[MaxWeight + 1];
int fill_dp_2(int *bag, int N)
{
	states_2[0] = true;		// ��һ����Ʒ���Ž�����
	if (bag[0] <= MaxWeight)
	{
		states_2[bag[0]] = true;	// ��һ���Ž�����
	}
	for (int i = 1; i < N; ++i)		// ��̬�滮״̬ת��
	{
		for (int j = MaxWeight-bag[i]; j >= 0; --j)
		{
			if (states_2[j] == true)
			{
				states_2[j + bag[i]] = true;
			}
		}
	}
	for (int i = MaxWeight; i >= 0; --i)		// ������
	{
		if (states_2[i] == true)
		{
			return i;
		}
	}
	return 0;
}

/****************************************************************
* @brief : 		0-1�������⣬������ֵ����̬�滮
* @author : 	dyx
* @date : 		2019/7/23 19:22
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
int fill_dp_val(int *bag, int *val, int N)
{
	int *state = new int [MaxWeight + 1];
	for (int i = 0; i < MaxWeight + 1; ++i)		// ��ʼ��state;
	{
		state[i] = -1;
	}
	state[0] = 0;		// ��һ�����ţ���ֵ0����state
	if (bag[0] <= MaxWeight)
	{
		state[bag[0]] = val[0];		// ��һ�����뱳��
	}
	for (int i = 1; i < N; ++i)		// ��̬�滮��״̬ת��
	{
		for (int j = MaxWeight - bag[i]; j >= 0; --j)
		{
			if (state[j] >= 0)
			{
				int v = state[j] + val[i];
				if (v > state[j + bag[i]])
				{
					state[j + bag[i]] = v;	// ֻ���ֵ����
				}
			}
		}
	}
	// �ҳ����ֵ
	int maxval = -1;		// �������ֵ
	for (int i = 0; i <= MaxWeight; ++i)
	{
		if (state[i] > maxval)
		{
			maxval = state[i];
		}
	}
	delete []state;
	return maxval;
}

int main()
{
	const int N = 7;
	int bag[N] = {21, 13, 22, 11, 15, 12, 16};
	int val[N] = {16, 21, 52, 36, 45, 42, 31};
	// ���ݣ�0-1�������
	int maxWeightInBag = 0;
	fill_1(0, 0, bag, N, maxWeightInBag);
	cout << "����װ�������������ǣ� " << maxWeightInBag << endl;
	//for (set<int>::iterator it = a.begin(); it != a.end(); ++it)
	//{
	//	cout << *it << endl;	// ��������set�洢��ӵ�ֵ�����ǽ������
	//}
	fill_3(0, 0, bag, N, maxWeightInBag);
	cout << "����װ�������������ǣ� " << maxWeightInBag << endl;
	// ���ݣ�0-1��ֵ���
	int weightInBag = 0;
	int maxVal = 0;
	fill_2(0, 0, 0, bag, val, N, weightInBag, maxVal);
	cout << "����װ�������������ǣ�" << weightInBag << endl;
	cout << "����װ�������ļ�ֵ�ǣ�" << maxVal << endl;
	// ��̬��0-1�������
	cout << "����װ�������������ǣ� " << fill_dp(bag, N) << endl;
	cout << "����װ�������������ǣ� " << fill_dp_2(bag, N) << endl;
	cout << "����װ�������ļ�ֵ�ǣ� " << fill_dp_val(bag, val, N) <<endl;
//	system("pause");
	return 0;
}
