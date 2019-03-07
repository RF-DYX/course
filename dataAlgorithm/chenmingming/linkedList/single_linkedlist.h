#ifndef LINKEDLIST_SINGLE_LINKEDLIST_H
#define LINKEDLIST_SINGLE_LINKEDLIST_H

#include<iostream>
using namespace std;

template <class ElemType> struct LinkNode      //�ڵ���
{
    ElemType _data;    //�ڵ������
    LinkNode* _next;    //ָ��ýڵ����һ���ڵ��ָ��
    LinkNode(): _next(NULL)
    {
        cout << "please enter data: ";
        cin >> _data;
    }
    LinkNode(const ElemType &d, LinkNode* p = NULL) : _data(d), _next(p) {}
    ~LinkNode(){}
};
template <class ElemType> class Single_linkedlist
{
    LinkNode<ElemType> *p_head = NULL;   //��βָ��
    LinkNode<ElemType> *p_tail = NULL;
    int listlength = 0; //������
public:
    Single_linkedlist(int len = 0); //���캯��(˳�����)
    Single_linkedlist(char reverse, int len = 0); //���캯��(�������)
    ~Single_linkedlist()    //��������
    {
//        deleteAll();  //����д��䣡�����ڴ��ͷŴ��󣡣���
    }

    void deleteAll();   //ɾ�����нڵ�
    void* get_p_head() const //����ͷ�ڵ��λ�ã���ͷָ��
    {
        return p_head;
    }
    void* get_p_tail() const //����Ϊ�ڵ��λ�ã���βָ��
    {
        return p_tail;
    }
    int getLength() const //����������
    {
        return listlength;
    }
    bool isEmpty() const    //�ж������Ƿ�Ϊ��
    {
        return listlength == 0;
    }
    ElemType getCurData(LinkNode<ElemType>* p) const  //���ص�ǰ�ڵ����������
    {
        return p->_data;
    }
    void addHead(const ElemType &data);    //������ͷ�����Ԫ��
    void addTail(const ElemType &data);     //������β�����Ԫ��
    LinkNode<ElemType>* find(int m) const; //���±����
    LinkNode<ElemType>* find(ElemType &data) const; //��Ԫ��ֵ����
    void printList() const; //��ӡ��������

};

#include "single_linkedlist.cpp"
#endif //LINKEDLIST_SINGLE_LINKEDLIST_H
