#include <iostream>
#include "Huffman.h"
using namespace std;


void Great_Huffman(HTNode* HT, UINT n)
{
	UINT k, j;
	UINT w;
	BYTE ch;
	UINT m = 2*n -1;
	//����n���ַ�����Ȩֵ
	for(k = 0; k < n; ++k)
	{
		cout << "Input char and weight: ";
		cin >> ch >> w;
		HT[k].character = ch;
		HT[k].weight = w;
		HT[k].Parent = HT[k].lChild = HT[k].rChild = 0; //��ʼ��
	}

	//��ʼ������������Ҷ��n-1���ڵ�
	for(k = n; k < m; ++k)
	{
		HT[k].character = '\0';
		HT[k].weight = 0;
		HT[k].Parent = HT[k].lChild = HT[k].rChild = 0;
	}

	//�����շ�����
	UINT Min_w1, Min_w2; //�����洢Ȩֵ��С������ֵ
	UINT p1, p2;			//����Ȩֵ��Ӧ���±�
	//���ѭ�����ڹ����µĽڵ�
	for(k = n; k < m; ++k)
	{
		Min_w1 = Min_w2 = MAXINT;
		p1 = p2 = 0; //��ʼ���±�
		//�ڲ�ѭ������Ѱ�ҹ����½ڵ��������СȨ�ڵ�
		for(j = 0; j < k; ++j)
		{
			if(HT[j].Parent == 0) //��������Ҷ��δ�ϲ�
			{
				if(HT[j].weight < Min_w1)//������СȨ
				{
					Min_w2 = Min_w1;
					p2 = p1;
					Min_w1 = HT[j].weight;
					p1 = j;
				}
				else if(HT[j].weight < Min_w2)//���Ĵ�СȨ
				{
					Min_w2 = HT[j].weight;
					p2 = j;
				}
			}
		}
		HT[p1].Parent = HT[p2].Parent = k;
		HT[k].lChild = p1;
		HT[k].rChild = p2;
		HT[k].weight = HT[p1].weight + HT[p2].weight;
	}
}

//���ַ��ĳ�������Ϊ�ڵ��Ȩֵ��������֤����Ƶ�ʸߵĵ��ַ�ʹ�õĶ�����λ�ĸ����٣�
//������Ƶ�ʵ͵��ַ�ʹ�õĶ�����λ����
void Huffman_Code(HTNode* HT, UINT n)
{
	UINT k;
	int sp, fp;
	char* HF = new char[n];
	int p;
	for(k = 0; k < n; ++k)
	{
		sp = n - 1;
		p = k;
		fp = HT[k].Parent;
		//��Ҷ������ֱ�����ڵ�
		while(fp != 0)
		{
			if(HT[fp].lChild == p) //�����ǰ�ڵ���������
				HF[sp] = '0';
			else
				HF[sp] = '1';
			sp--;
			p = fp;
			fp = HT[fp].Parent;
		}
		//��ʾ����
		cout << HT[k].character << ": ";
		sp++;
		while(sp < n)
		{
			cout << HF[sp];
			sp++;
		}
		cout << endl;
	}
}

int main()
{
	HTNode HT[7]; 
	Great_Huffman(HT, 4);
	Huffman_Code(HT, 4);
	return 0;
}