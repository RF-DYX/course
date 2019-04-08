/*
�ŶӶ��е�Ӧ�ó�����������ѧУ���ٿ���ᣬҪ��ȫУ����ѧ���԰༶Ϊ��λ�ڲٳ����ϡ�
���������ÿ���༶�ڲٳ��϶����Լ��Ķ��顣
���������ͬѧС����С��ٵ���һ�ᣬ����С�������ǰ༶��λ���ҵ�ͬѧ�����˶���ĺ�ߣ�
��С�������ǰ༶��λ���ϲ�û�п����ˣ�����Ȼ�������ǰ��һ�����ģ�����ô����վ�ڰ༶��λ������Ϊ��ͷ��

*/

#include <stdio.h>
#include <queue>
#include <string>
using namespace std;
int Element[1000000];
char command[10];
int data;

int main()
{
	int teamNum = 0;
	int teamLen = 0;
	int temp = 0;
	int teamNo = 0;
	int nTimes = 1;
	while(scanf_s("%d", &teamNum) && teamNum)
	{
		queue<int> Team[1000];
		queue<int> TeamOrder; 
		for(teamNo = 0; teamNo < teamNum; ++teamNo)
		{
			scanf_s("%d", &teamLen);
			while(teamLen--)
			{
				scanf_s("%d", &temp);
				Element[temp] = teamNo;
			}
		}
		printf("Scenario #%d\n", nTimes++);		
		while(scanf_s("%s", &command, 10) && strncmp(command, "S", 1))
		{
			if(strncmp(command, "E", 1) == 0)
			{
				scanf_s("%d", &data);
				if(Team[Element[data]].empty())
				{
					TeamOrder.push(Element[data]);
				}
				Team[Element[data]].push(data);
			}
			if(strncmp(command, "D", 1) == 0)
			{
				printf("%d\n", Team[TeamOrder.front()].front());
				Team[TeamOrder.front()].pop();
				if(Team[TeamOrder.front()].empty())
					TeamOrder.pop();
			}
		}
		printf("\n");
	}
	return 0;
}