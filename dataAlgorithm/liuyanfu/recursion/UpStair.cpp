/*
* Copyright: (c) 2019
*
* �ļ�����:  UpStair.cpp	
* �ļ���ʶ��
* ժ	Ҫ�� ��̨������
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/23  9:45
*/

#include <iostream>
#include <windows.h>
using namespace std;

/*
����������������n��̨�ף�ÿ��һ��ֻ������1������2��̨�ס��������n��̨���ж������߷�
˼·��
��1�����õݹ�ķ�ʽ�������f(n)����Ϊһ��������1������2��̨�ף�
	 ���Ե�����1��ʱ��ʣ��n-1��̨�ף�����2��ʱ��ʣ��n-2��̨�ף����f(n) = f(n - 1) + f(n - 2)(n > 2)
*/

/*
* @brief	���õݹ���������
*
* @method:    SolveStep
* @access:    public 
* @param:     size_t nStair
* @Return:    size_t
* @author:    RF_LYF
* @since:   2019/4/23  9:57 
*/
//�÷�������̨�׵ĸ�������һ��ֵ��ʱ������ٶȺ���
DWORD SolveStep(size_t nStair)
{
	if(nStair <= 0)
		return 0;
	else if(nStair < 3 && nStair > 0)
		return nStair;
	else
		return SolveStep(nStair - 1) + SolveStep(nStair -2);
}


/**
* @brief	������һ�ַ����У��ö������ظ������˺ܶ�飬���Ժ�Ӱ��ִ��Ч�ʣ�
*			����f(5) = f(4) + f(3);��f(4) = f(3) + f(2); f(3) = f(2) + f(1);������f(4)��f(3)��Ҫ������2��
*			��˱����������Զ����µĶ�̬�滮��ʽ�������
*
* @method:    SolveStepOpti
* @access:    public 
* @param:     size_t nStair
* @param:     int * Counter
* @Return:    ULONG
* @author:    RF_LYF
* @since:   2019/4/23  10:33 
*/
DWORD SolveStepOpti(size_t nStair, int *Counter)
{
	if(0 !=Counter[nStair])
		return Counter[nStair];
	if(nStair <= 0)
		return 0;
	else if(nStair > 0 && nStair < 3)
	{
		return Counter[nStair] = nStair;
	}
	else
	{
		Counter[nStair] = SolveStepOpti(nStair - 1, Counter) + SolveStepOpti(nStair - 2, Counter);
		return Counter[nStair];
	}
}


/**
* @brief	����ѭ��������⣬�Ե����ϵĶ�̬�滮�������
*
* @method:    SolveStepOpti2
* @access:    public 
* @param:     size_t nStair
* @Return:    DWORD
* @author:    RF_LYF
* @since:   2019/4/23  10:52 
*/
DWORD SolveStepOpti2(size_t nStair)
{
	if(nStair <= 0)
		return 0;
	else
	{
		DWORD step = 0;
		DWORD fstep = 1;
		DWORD ffstep = 0;
		for(size_t i = 1; i <= nStair; ++i)
		{
			step = fstep + ffstep;
			ffstep = fstep;
			fstep = step;
		}
		return step;
	}
}

/*
��̨������ı������⣬����n��̨�ף�ͬ��ÿ�ο粽������1��̨�׻���2��̨�ף�����ָ����һ�ο粽ʱ�������ţ�
��ô�������n��̨�����ÿ������ŵ��߷��ж����֣�
���������������ʵ��������ǣ�����n��̨�������������꣬�ж������߷�
*/


/**
* @brief	 �ݹ鷨ʵ��
*
* @method:    SolveStepOddEven
* @access:    public 
* @param:     int nStair
* @param:     size_t nStep(������¼����)
* @param:     DWORD& nCountOdd(������¼�������߷�����Ŀ)
* @param:     DWORD& nCountEven(������¼ż�����߷�����Ŀ)
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/23  11:28 
*/
void SolveStepOddEven(int nStair, size_t nStep, DWORD& nCountOdd, DWORD& nCountEven)
{
	
	if(nStair < 0)
		return;
	else if(nStair == 0)
	{
		if(nStep % 2 == 1)
			++nCountOdd;
		else
			++nCountEven;
		return;
	}
	else
	{
		++nStep;
		SolveStepOddEven(nStair - 1, nStep, nCountOdd, nCountEven);
		SolveStepOddEven(nStair - 2, nStep, nCountOdd, nCountEven);
	}
}


/**
* @brief	��̬�滮 + ѭ������
*
* @method:    SolveStepOddOpti
* @access:    public 
* @param:     int nStair
* @param:     DWORD& nCountOdd(������¼�������߷�����Ŀ)
* @param:     DWORD& nCountEven(������¼ż�����߷�����Ŀ)
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/23  14:05 
*/
void SolveStepOddEvenOpti(int nStair, DWORD& nCountOdd, DWORD& nCountEven)
{
	if(nStair <= 0)
		return;
	else if(nStair == 1)
	{
		nCountOdd = 1;
		nCountEven = 1;
	}
	else
	{
		DWORD *pFOdd = new DWORD[nStair + 1];
		DWORD *pFEven = new DWORD[nStair + 1];
		pFOdd[0] = 0,pFOdd[1] = 1;
		pFEven[0] = 1,pFEven[1] = 0;
		for(int i = 2; i <= nStair; ++i)
		{
			pFOdd[i] = pFEven[i - 1] + pFEven[i - 2];
			pFEven[i] = pFOdd[i - 1] + pFOdd[i - 2];
		}
		nCountOdd = pFOdd[nStair];
		nCountEven = pFEven[nStair];
		delete []pFOdd;
		delete []pFEven;
	}
}


/*
̨������������һ��̨���ܹ���n�������ÿ�ο�����1�ף�2�ס���n�ף����ܹ��ж�����������
���������
��1������1��̨��ʱf(1) = 1
��2������2��̨��ʱf(2) ��Ϊ2�ַ�ʽ����һ����1��ʣ��f(1)���������ڶ�����2��ֻ��1�����������
		f(2) = f(2 - 1) + f(2 -2) = f(1) + 1
��3������3��̨��ʱf(3) ��Ϊ3�ַ�ʽ����1������1��ʣ��f(2)����������2������2��ʣ��f(1)����������3������3��ֻ��һ�����������
		f(3) = f(2) + f(1) + f(0) 
��4������4��̨��ʱf(4) ��Ϊ4�ַ�ʽ����1������1��ʣ��f(3)����������2������2��ʣ��f(2)����������3������3��ʣ��f(1)��������
	 ��4������4��ֻ��һ�����������f(4) = f(3) + f(2) + f(1) + f(0)
��5������n��̨��ʱ��������f(n) = f(n-1)+ f(n-2) + f(n-3) + ����+ f(1) + f(0)
��6����n-1��̨��ʱ��f(n-1) = f(n-2) + f(n-3) + ����+ f(0)
��7��f(n) - f(n-1) = f(n-1),����f(n) = 2f(n-1),�ù�ʽ��Ϊ���ƹ�ʽ
*/

long long SolveStepUpdate(int nStair)
{
	if(nStair <= 0)
		return 0;
	else if(nStair == 1)
		return 1;
	else
	{
		long long step = 0;
		long long fstep = 1;
		for(int i = 2; i <= nStair; ++i)
		{
			step = 2 * fstep;
			fstep = step;
		}
		return step;
	}
}
int main()
{
	size_t nStairNum = 0;
	while(cin >> nStairNum && nStairNum)
	{
		//int *p = new int[nStairNum + 1];
		//memset(p, 0, sizeof(int) * (nStairNum + 1));
		/*cout<< nStairNum << "��̨����" << SolveStep(nStairNum) << "���߷�" << endl;*/
		//cout<< nStairNum << "��̨����" << SolveStepOpti(nStairNum, p) << "���߷�" << endl;
		//cout<< nStairNum << "��̨����" << SolveStepOpti2(nStairNum) << "���߷�" << endl;
		//delete []p;

		/*DWORD nCountOdd = 0;
		DWORD nCountEven = 0;
		SolveStepOddEven(nStairNum, 0, nCountOdd, nCountEven);
		cout<< nStairNum << "��̨���������߷���" << nCountOdd << "���߷�" << endl;
		cout<< nStairNum << "��̨��ż�����߷���" << nCountEven << "���߷�" << endl;*/
		cout<< nStairNum << "��̨����" << SolveStepUpdate(nStairNum) << "���߷�" << endl;
		
	}
	return 0;
}