#include "ACMatch.h"
#include <queue>

AC::AC(void)
{
	root = new ACNode('/');		// ��ʼ�������
}

AC::~AC(void)
{
	clear();
}

/****************************************************************
* @brief : 		����ģʽ��
* @author : 	dyx
* @date : 		2019/8/26 19:20
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
template<typename Iterator>
void AC::insert(Iterator begin, Iterator end)
{
	ACNode *cur = root;
	int i;
	for (i = 0; begin != end; ++begin, ++i)
	{
		int index = *begin - 'a';
		if (cur->child[index] == 0)		// �ӽ��Ϊ0��������½����
		{
			cur->child[index] = new ACNode(*begin);		
			++cur->nodeNum;
		}
		cur = cur->child[index];		// �ӽڵ㲻Ϊ0����������ӽڵ���ӽڵ�
	}
	cur->isEndingChar = true;
	cur->length = i;		// ��ʾ��ǰ����ӽڵ�ĳ���
};

void AC::insert(const char* text)
{
	insert(text, text + strlen(text));
}

/****************************************************************
* @brief : 		�����Ƿ���ģʽ��
* @author : 	dyx
* @date : 		2019/8/26 19:19
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
template<typename Iterator>
bool AC::find(Iterator begin, Iterator end)
{
	ACNode* cur = root;
	for (; begin != end; ++begin)
	{
		int index = *begin - 'a';
		if (cur->child[index] == 0)
		{
			return false;
		}
		cur = cur->child[index];
	}
	return cur->isEndingChar;
}

bool AC::find(const char* pattern)
{
	return find(pattern, pattern + strlen(pattern));
}

/****************************************************************
* @brief : 		����Trie����ʧ��ָ�룬�൱��KMP��next����
* @author : 	dyx
* @date : 		2019/8/26 19:00
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void AC::buildFailurePointer()
{
	queue<ACNode> que;
	root->pFail = NULL;
	que.push(*root);
	while (!que.empty())
	{
		ACNode p = que.front();
		que.pop();
		for (int i = 0; i < 26; ++i)
		{
			ACNode *pc = p.child[i];
			if (pc == NULL)
			{
				continue;
			}
			if (p == *root)
			{
				pc->pFail = root;
			}
			else
			{
				ACNode *q = p.pFail;
				while (q != NULL)
				{
					ACNode *qc = q->child[pc->data - 'a'];
					if (qc != NULL)
					{
						pc->pFail = qc;
						break;
					}
					q = q->pFail;
				}
				if (q == NULL)
				{
					pc->pFail = root;
				}
			}
			que.push(*pc);
		}
	}
}


/****************************************************************
* @brief : 		ƥ��ģʽ��
* @author : 	dyx
* @date : 		2019/8/26 19:08
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
template<typename Iterator>
void AC::match(Iterator begin, Iterator end, PosSet *ret)
{
	ACNode* cur = root;
	for (int i = 0; begin != end; ++begin, ++i)
	{
		int index = *begin - 'a';
		while(cur->child[index] == 0 && cur != root)		// û�к����Ҳ��Ǹ���㣬��ȥ������ʧЧ���
		{
			cur = cur->pFail;
		}
		cur = cur->child[index];
		if (cur == 0)
		{
			cur = root;
		}
		ACNode *pTemp = cur;
		while(pTemp != root)
		{
			if (pTemp->isEndingChar == true)
			{
				ret->vPos.push_back(i - pTemp->length + 1);
				ret->vLen.push_back(pTemp->length);
			}
			pTemp = pTemp->pFail;
		}
	}
}


/****************************************************************
* @brief : 		ƥ�����
* @author : 	dyx
* @date : 		2019/8/26 19:13
* @version : 	ver 1.0
* @inparam :  �ַ������׵�ַ��
* @outparam : ret ���� ƥ�䵽���ַ�����λ�úͳ���
*****************************************************************/
void AC::match(const char* text, PosSet* ret)
{
	match(text, text + strlen(text), ret);
}


/****************************************************************
* @brief : 		��ս��
* @author : 	dyx
* @date : 		2019/8/26 19:14
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void AC::clear_node(ACNode cur)
{
	for(int i = 0; i < 26; ++i)
	{
		if (cur.child[i] == 0)
		{
			continue;
		}
		clear_node(*cur.child[i]);
		delete cur.child[i];
		cur.child[i] = 0;
		if (--cur.nodeNum == 0)		// ������--
		{
			break;
		}
	}

}

/****************************************************************
* @brief : 		���all
* @author : 	dyx
* @date : 		2019/8/26 19:15
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void AC::clear()
{
	clear_node(*root);
	for (int i = 0; i < 26; ++i)
	{
		root->child[i] = 0;
	}
}

/****************************************************************
* @brief : 		��ӡ�����
* @author : 	dyx
* @date : 		2019/8/26 19:15
* @version : 	ver 1.0
* @inparam :	����
* @outparam :	�������ģʽ������������������**
*****************************************************************/
void AC::print(const char* text)
{
	string str(text, text + strlen(text));
	PosSet ret;
	match(text, text + strlen(text), &ret);
	for (size_t i = 0; i < ret.vPos.size(); ++i)
	{
		string stemp(ret.vLen[i], '*');		// *�ĳ���
		str = str.replace(ret.vPos[i], ret.vLen[i], stemp.c_str());	//��ʼλ�ã��滻���ȣ��滻����
	}
	cout << str.c_str() << endl;
}