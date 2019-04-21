/*
* Copyright: (c) 2019
*
* �ļ�����:  POJ1035.cpp	
* �ļ���ʶ��
* ժ	Ҫ��
*
* ��	���� 1.0
* ��	�ߣ� RF_LYF
* ��������:	 2019/4/18  16:35
*/


/*
��Ŀ���⣺���ȸ���һ���ֵ��ʣ��ⲿ�ֵ���������Ϊdictionary�����ݡ��ٸ���һ���ֵ��ʣ���Ҫ����ȥ�ж��ⲿ�ֵ��ʵ���ȷ�ԣ�
����ⲿ������ĵ��ʣ�������dictionary�в鵽������ʾ����ƴд��ȷ�������dictionary�в鲻��������ͨ�����ַ�ʽ���ı��
���ʺ�ȥdictionary�в��ң��ҵ����ڸõ��ʵĺ�����ʾ�任����Բ��ҵ��ĵ��ʡ���������任Ҳ�޷��ҵ�����˵���õ��ʴ�ĺܳ��ס�
*/
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;
int FindIndex(char p[][16], int raw, string str);

char dict[10001][16] = {0};
char word[51][16] = {0};
int nDictLen = 0;

struct cmp
{
	bool operator()(string &s1, string &s2)
	{
		return FindIndex(dict, nDictLen, s1) > FindIndex(dict, nDictLen, s2);
	}
};

/**
* @brief
*
* @method:    FindIndex
* @access:    public 
* @param:     char p[][16]
* @param:     int raw
* @param:     char * pstr
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/19  0:07 
*/
int FindIndex(char p[][16], int raw, string str)
{
	for(int i = 0; i < raw; ++i)
	{
		if(strcmp(p[i], str.c_str()) == 0)
			return i;
	}
}
/**
* @brief
*
* @method:    IsCorrect
* @access:    public 
* @param:     char p[][16]
* @param:     int raw
* @param:     char * pstr
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/4/18  17:18 
*/
bool IsCorrect(char p[][16], int raw, char *pstr)
{
	int nstrLen = strlen(pstr);
	for(int i = 0; i < raw; ++ i)
	{
		if(strlen(p[i]) != nstrLen)
			continue;
		else
		{
			if(strcmp(p[i], pstr) == 0)
				return true;
		}
	}
	return false;
}


/**
* @brief
*
* @method:    DeleteOne
* @access:    public 
* @param:     char p[][16]
* @param:     int raw
* @param:     char * pstr
* @param:     priority_queue<char *
* @param:     vector<char * >
* @param:     greater<char * > > & que
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/18  17:46 
*/
void DeleteOne(char p[][16], int raw, char *pstr, priority_queue<string, vector<string>, cmp > &que)
{
	int nstrLen = strlen(pstr);
	char stemp[16] = {0};
	for(int i = 0; i < nstrLen; ++i)
	{
		memcpy(stemp, pstr, i);
		memcpy(stemp + i, &pstr[i + 1], nstrLen - 1 - i);
		if(IsCorrect(p, raw, stemp))
			que.push(stemp);
	}
}


/**
* @brief
*
* @method:    InsertOne
* @access:    public 
* @param:     char p[][16]
* @param:     int raw
* @param:     char * pstr
* @param:     priority_queue<char *
* @param:     vector<char * >
* @param:     greater<char * > > & que
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/18  17:47 
*/
void InsertOne(char p[][16], int raw, char *pstr, priority_queue<string, vector<string>, cmp > &que)
{
	char ch = 'a';
	int nstrLen = strlen(pstr);
	char stemp[16] = {0};
	for(int i = 0; i < 26; ++i)
	{
		for(int j = 0; j <= nstrLen; ++j)
		{
			memcpy(stemp, pstr, j);
			memcpy(stemp + j, &ch, 1);
			memcpy(stemp + j + 1, &pstr[j], nstrLen - j);
			if(IsCorrect(p, raw, stemp))
				que.push(stemp);
		}
		ch++;
	}
}


/**
* @brief
*
* @method:    ReplaceOne
* @access:    public 
* @param:     char p[][16]
* @param:     int raw
* @param:     char * pstr
* @param:     priority_queue<char *
* @param:     vector<char * >
* @param:     greater<char * > > & que
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/18  21:38 
*/
void ReplaceOne(char p[][16], int raw, char *pstr, priority_queue<string, vector<string>, cmp > &que)
{
	char ch = 'a';
	int nstrLen = strlen(pstr);
	char stemp[16] = {0};
	char str[16] = {0};
	memcpy(str, pstr, nstrLen);
	for(int i = 0; i < 26; ++i)
	{
		for(int j = 0; j < nstrLen; ++j)
		{
			str[j] = ch;
			memcpy(stemp, str, nstrLen);
			if(IsCorrect(p, raw, stemp))
				que.push(stemp);
			memcpy(str, pstr, nstrLen);
		}
		ch++;
	}
}

int main()
{
	while(scanf("%s",dict[nDictLen]) && strcmp(dict[nDictLen], "#"))
		nDictLen++;
	int nWordLen = 0;
	while(scanf("%s", word[nWordLen]) && strcmp(word[nWordLen], "#"))
		nWordLen++;
	priority_queue<string, vector<string>, cmp> upque;
	for(int i = 0; i < nWordLen; ++i)
	{
		if(IsCorrect(dict, nDictLen, word[i]))
			printf("%s is correct\n", word[i]);
		else
		{
			DeleteOne(dict, nDictLen, word[i], upque);
			InsertOne(dict, nDictLen, word[i], upque);
			ReplaceOne(dict, nDictLen, word[i], upque);
			printf("%s: ", word[i]);
			while(!upque.empty())
			{
				printf("%s ", upque.top().c_str());
				upque.pop();
			}
			printf("\n");
		}
	}
	return 0;
}