#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct BiTNode
{
	int data;
	struct BiTNode *lp, *rp;
}BiTNode, *BiTree;

/*
* �ݹ���Ҷ�����������Ҳ�ж����������T���Ƿ����key
* ָ��fָ��T��˫�ף����ʼ����ֵΪNULL
* �����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE
* ����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE
*/
bool SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)
	{
		*p = f;
		return false;
	}
	else if (key == T->data)
	{
		*p = T;
		return true;
	}
	else if (key < T->data)
	{
		return SearchBST(T->lp, key, T, p);
	}
	else
	{
		return SearchBST(T->rp, key, T, p);
	}
}


/****************************************************************
* @brief : 		��������(����)�����Ĳ��뷽��
* @author : 	dyx
* @date : 		2019/7/2 9:45
* @version : 	ver 1.0
* @inparam :    T ������ͷ���ָ�룬key:Ҫ���������
* @outparam :	bool���Ƿ����ɹ�
*****************************************************************/
bool InsertBST(BiTree *T, int key)
{
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p))		//���Ҳ��ɹ����Ų��롣�����ж��Ƿ����ݿ��� ���ڴ����ݡ�
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lp = s->rp = NULL;
		if (!p)
		{
			*T = s;					// û�н�㣬ֱ����Ϊ�����
		}
		else if (key < p->data)
		{
			p->lp = s;				// s��Ϊ���ҵ����һ����������
		}
		else
		{
			p->rp = s;				// s��Ϊ���ҵ����һ����������
		}
		return true;
	}
	else
		return false;				// �����д˽�㣬���������
}

/****************************************************************
* @brief : 		ɾ��ĳ�����
* @author : 	dyx
* @date : 		2019/7/2 9:49
* @version : 	ver 1.0
* @inparam :	T��Ҫɾ���Ľ��
* @outparam :	bool���Ƿ�ɾ���ɹ�
*****************************************************************/
bool Delete(BiTree *p)
{
	BiTree q,s;
	bool flag = false;
	if ((*p)->rp == NULL)		// ֻ��������
	{
		q = *p;
		*p = (*p)->lp;
		free(q);
		flag = true;
	}
	else if ((*p)->lp == NULL)		// ֻ��������
	{
		q = *p;
		*p = (*p)->rp;
		free(q);
		flag = true;
	}
	else						// ����������������
	{
		q = *p;
		s = (*p)->lp;
		while(s->rp)
		{
			q = s;
			s = s->rp;
		}
		(*p)->data = s->data;
		if (q!=*p)
		{
			q->rp = s->lp;
		}
		else
		{
			q->lp = s->lp;
		}
		free(s);
		flag = true;
	}
	return flag;
}

/****************************************************************
* @brief : 		�ݹ�ɾ��ĳ������ĳ��ֵ
* @author : 	dyx
* @date : 		2019/7/2 9:51
* @version : 	ver 1.0
* @inparam :	T�����ĸ���㡣key:Ҫɾ����ֵ
* @outparam :	bool���Ƿ�ɾ���ɹ�
*****************************************************************/
bool DeleteBST(BiTree *T, int key)
{
	if (!*T)
	{
		return false;
	}
	else
	{
		if (key == (*T)->data)
		{
			return  Delete(T);
		}
		else if (key <(*T)->data)
		{
			return DeleteBST(&(*T)->lp, key);
		}
		else
		{
			return DeleteBST(&(*T)->rp, key);
		}
	}
}


/****************************************************************
* @brief : 		ǰ���ӡ��������Ƿ���ȷ
* @author : 	dyx
* @date : 		2019/7/2 9:52
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void preOrderPrint(BiTree T)
{
	if (!T)
	{
		return;
	}
	cout << T->data << " ";
	preOrderPrint(T->lp);
	preOrderPrint(T->rp);
}

int main()
{
	int i;
	int a[10] = {62,88,58,47,35,73,51,99,37,93};
	BiTree T = NULL;
	for(i = 0; i < 10; ++i)
	{
		InsertBST(&T, a[i]);
	}

	cout << endl;
	cout << InsertBST(&T,73) << endl;
	cout << InsertBST(&T,56) << endl;
	preOrderPrint(T);
	cout << endl;

	DeleteBST(&T,35);
	preOrderPrint(T);
	cout << endl;
//	system("pause");
	return 0;
}

