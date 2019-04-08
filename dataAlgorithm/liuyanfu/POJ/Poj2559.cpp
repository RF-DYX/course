#include <stdio.h>
#include <stack>
struct pos
{
	long long x;
	long long y;
};
using namespace std;

int main()
{
	long long n = 0;
	long long a = 0;
	pos point;
	pos temp;
	while(scanf_s("%I64d", &n) && n)
	{
		stack<pos> stk;
		long long maxarea = 0;
		for(long long i = 0; i < n; ++i)
		{
			scanf_s("%I64d", &a);
			point.x = 1;
			point.y = a;
			temp.x = 0;
			if(stk.empty() || (stk.top()).y < a)
				stk.push(point);
			else
			{
				while(!stk.empty() && stk.top().y >= a)
				{
					stk.top().x += temp.x;
					if(maxarea < stk.top().x * stk.top().y)
						maxarea = stk.top().x * stk.top().y;
					temp.x = stk.top().x;
					stk.pop();
				}
				stk.push(point);
				stk.top().x += temp.x;
			}
		}
		temp.x = 0;
		while(!stk.empty())
		{
			stk.top().x += temp.x;
			if(maxarea < stk.top().x * stk.top().y)
				maxarea = stk.top().x * stk.top().y;
			temp.x = stk.top().x;
			stk.pop();
		}
		
		printf("%I64d\n", maxarea);
	}
	return 0;
}


/*   //�������ķ�ʽ���������������ҳ�������ֵ�����з�ʽ�㷨��ʱ�临�Ӷ�ΪO(N^2)
int n = 0;
int arr[ARRMAXLEN] = {0};
while(cin >> n && n)	//������0��ʱ���˳�ѭ��
{
for(int i = 0; i < n; ++i) //��ÿ�е����ݶ���洢��������
{
cin >> arr[i];
}
int maxarea = 0;
int minheight = 0;
for(int i = 0; i < n; ++i)
{
minheight = arr[i];
int temparea = 0;
for(int j = i + 1; j < n; ++j)
{
minheight = Min(minheight, arr[j]);
temparea = minheight * ((j - i) + 1);
if(temparea > maxarea)
maxarea = temparea;
}
}

cout << maxarea << endl;
}
*/
