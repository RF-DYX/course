#include "single_linkedlist.h"
#include <iostream>
int main()
{
    Single_linkedlist<int> intList1(1);
    intList1.printList();
    Single_linkedlist<double> doubleList1(3);
    doubleList1.printList();
    Single_linkedlist<string> strList1('r',3);
    strList1.printList();
    return 0;
}