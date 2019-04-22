/*
* Copyright: (c) 2019
*
* �ļ�����:  POJ1442.cpp 
* �ļ���ʶ��
* ժ	Ҫ�� ���ȶ���
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/16  13:29
*/

/*
��������Ϊ���ʱ�ǰ����������С�ģ�������ڶ�С�����ķ�ʽ����ģ��൱���������һ�����������е�ֵ��
����Ϊ������в��ǹ̶�����ģ����ǲ��ϵ��ڸ��£��������������޷�ʵ�ֵġ����ǿ��������ȶ���������

�����������ȶ��У�һ�������洢ǰkС������������ǰ��С���ں���һ�����ȶ��е�k+1С����������
С����ǰ�������ں�ÿ���õ�һ���������жϵ�һ�����ȶ����е���������k�����������k����
��ֱ�Ӱ������ѹ�뵽��һ�����У������k�����ж�������͵�һ�����ȶ����еĵ�һ�����Ĵ�С��
����ȵ�һ�����󣬾�ѹ��ڶ������ȶ��У�����ȵ�һ����С���Ͱѵ�һ�����ȶ��еĶ���Ԫ�ص���ѹ��ڶ������У�
���������ѹ���һ�����ȶ��С�
���ʱ�������һ�����ȶ������Ԫ�ظ���С��k�����Ȱѵڶ������ȶ�����Ķ���Ԫ�ص���ѹ���һ�����ȶ��У�
Ȼ�������һ�����ȶ��еĶ���Ԫ�أ������k������ֱ�������һ�����ȶ��еĶ���Ԫ�ء�

*/
//#include<cstdio>
//#include<queue>
//using namespace std;
//int a[30010], u[30010];
//
//int main()
//{
//	int n, m, i, j, k, x, ans;
//	while(~scanf("%d%d",&m,&n))
//	{	
//		priority_queue<int, vector<int>, less<int> > que1;  //�����е�Ԫ�شӴ�С����
//		priority_queue<int, vector<int>, greater<int> > que2;   //�����е�Ԫ�ش�С��������
//		for(i = 1; i <= m; i++)
//			scanf("%d",&a[i]);
//		for(j = 1; j <= n; j++)
//			scanf("%d",&u[j]);
//		i = 0;
//		j = k = 1;
//		while(j <= n)
//		{
//			if(i == u[j])  //������kС����
//			{
//				j++;
//				if(que1.size() < k) //que1���Ԫ�ز���k��
//				{
//					x = que2.top();
//					que1.push(x);
//					que2.pop();
//				}
//				ans = que1.top(); 
//				printf("%d\n",ans);
//				k++;  //ÿ�ε���һ������k��ֵ��Ҫ��1
//			}
//			else
//			{
//				i++;
//				//que1���Ԫ�ز���k��
//				if(que1.size() < k) 
//				{
//					que2.push(a[i]); 
//					x = que2.top();	
//					que2.pop();
//					que1.push(x);  //�Ȱ�a[i]ѹ��que2���ٴ�que2��ȡ����Сֵ��ѹ��que1
//				}
//				//���que1��Ԫ�شﵽk������Ҫѹ����е�ֵ��que1�еĵ�ǰ���ֵ��˵��que1�е�ǰ�����ֵ�����ǵ�kС
//				else if(que1.top() > a[i])
//				{ 
//					x = que1.top();
//					que1.pop();
//					que2.push(x);
//					que1.push(a[i]);
//				}
//				//que1�е�Ԫ�ظ����ﵽk������Ҫѹ����е�ֵ��que1�еĵ�ǰ���ֵС��˵��que1�е�ǰ�����ֵ�����ǵ�kС�����a[i]ֱ��ѹ��que2��
//				else
//				{
//					que2.push(a[i]);
//				}
//			}
//		}
//	}
//	return 0;
//
//}

#include <stdio.h>
#include <queue>
using namespace std;
int data[30001];
int command[30000];
int main()
{
	int AddNum = 0;
	int GetNum = 0;
	scanf_s("%d%d", &AddNum, &GetNum);
	priority_queue<int, vector<int>, less<int> > bigque;
	priority_queue<int, vector<int>, greater<int> > smallque;
	for(int i = 0; i < AddNum; ++i)
	{
		scanf_s("%d", &data[i]);
	}
	for(int j = 0; j < GetNum; ++j)
	{
		scanf_s("%d", &command[j]);
	}
	int i = 0;
	int j = 0;
	size_t k = 1;
	int x = 0;
	while(j < GetNum)
	{
		if(i == command[j])
		{
			if(bigque.size() < k)
			{
				x = smallque.top();
				bigque.push(x);
				smallque.pop();
			}
			printf("%d\n", bigque.top());
			k++;
			j++;
		}
		else
		{
			if(bigque.size() < k)
			{
				smallque.push(data[i]);
				x = smallque.top();
				smallque.pop();
				bigque.push(x);
			}
			else if(bigque.top() > data[i])
			{
				x = bigque.top();
				bigque.pop();
				smallque.push(x);
				bigque.push(data[i]);
			}
			else
				smallque.push(data[i]);
			i++;
		}
	}

	return 0;
}