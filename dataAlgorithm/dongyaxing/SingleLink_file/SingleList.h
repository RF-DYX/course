/**
* ժҪ��	���������ڱ�����ͷ��㡢β��㡣
* �޸ģ�	��Ӳ��ֺ�����������Ϊbool�������ֺ��������ࣻ
*			���ֺ������const�����ⱻ�޸ģ�����������ע�ͣ����������
* �޸����ڣ�2019/3/26
*/

#ifndef _SINGLELIST_H
#define _SINGLELIST_H
#include<Windows.h>
#include<iostream>

struct SNode		//���Ļ�����������
{
	int data;
	SNode* pNext;
};

typedef unsigned int UINT;
typedef SNode* ListNode;		// ��ʾһ�����

class SingleList
{

public:
 	SingleList(void);
 	~SingleList(void);

	bool IsEmpty() const;//�ж������Ƿ�Ϊ��

	UINT GetLength() const;//��ȡ��ǰ����ĳ���

	ListNode GetHeadNode() const;//��ȡ�����ͷ���

	ListNode GetTailNode() const;//��ȡ�����β���

	ListNode GetMidNode() const;//���������м��㣬ż�����ص�һ�����

	void AddHead(const int &data);//�������ͷ�������µĽ��

	void AddTail(const int &data);//�������β�������µĽ��

	ListNode InsertAt(ListNode pos, const int &data);	//��ָ�����ǰ�������ݣ��������½��ĵ�ַ
	bool InsertAt_2(ListNode pos, const int &data);		//��ָ�����ǰ�������ݣ�������bool���ͣ��ɹ�����ture

	ListNode ModifyAt(ListNode pos, const int &data);	//�޸�ָ���������ݣ������ص�ǰ�ڵ�ĵ�ַ
	bool ModifyAt_2(ListNode pos, const int &data);		//�޸�ָ���������ݣ�������bool���ͣ��ɹ�����ture

	ListNode RemoveAt(ListNode pos);		//ɾ��ָ����㣬�����ر�ɾ��������һ���ĵ�ַ
	bool RemoveAt_2(ListNode pos);			//ɾ��ָ����㣬������bool���ͣ��ɹ�����ture

	ListNode RemoveAt(UINT nCountBack);		//ɾ��������n���ڵ㣬�����ر�ɾ��������һ���ĵ�ַ
	bool RemoveAt_2(UINT nCountBack);		//ɾ��������n���ڵ㣬������bool���ͣ��ɹ�����ture

	ListNode Find(const int &data) const;			//�ڵ�ǰ�������ҵ���Ҫ����������ȵĵ�һ�����ĵ�ַ

	void Erase();							//ɾ����������н��

	void PrintList() const;					//��ӡ�������н�������

	void Reverse();							//��ת����
	
private:
	ListNode m_pHead;
	ListNode m_pTail;
	UINT m_nListLen;
};


#endif

