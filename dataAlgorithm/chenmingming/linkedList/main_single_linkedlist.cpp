#include "single_linkedlist.h"
#include <iostream>
#include <string>
int main()
{
    Single_linkedlist<int> intList1(3);
    intList1.printList();
    cout << "����ĳ����ǣ�" << intList1.getLength() << endl;
    intList1.deleteAll();
    cout << "����ĳ����ǣ�" << intList1.getLength() << endl;
    Single_linkedlist<string> strList1('r',3);
    strList1.printList();
    cout << "�����ǿյ���(0:���ǣ�1:��)" << strList1.isEmpty() << endl;
    cout << "����ĵ�2��Ԫ��list[2]�ǣ�" << (strList1.find(2))->_data << endl;
    string str("abc");
    cout << "����İ����ַ���\"abc\"��Ԫ�صĵ�ַ��" << endl;
    strList1.find(str);
    strList1.addHead(str);
    strList1.addTail(str);
    return 0;
}