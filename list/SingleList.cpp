#include "SingleList.h"

int main() 
{
    SingleList<float> sl;
    sl.insert(0.2, 0.5);
    sl.append(1.1);
    sl.append(2.2);
    sl.append(3.3);
    sl.insert(2.2, 2.5);
    sl.insert(2.7, 2.8);
    sl.PrintList();
    Node<float> *node = sl.getHead();
    sl.ReversePrintList(node);
    std::cout << "reverse print ok" << std::endl;
    SingleList<float> s2 = sl;
    std::cout << "The new list is :" << std::endl;
    s2.PrintList();
    s2.reverse();
    sl.PrintList();
    std::cout << "after reverse s2" << std::endl;
    s2.PrintList();
    std::cout << "sl compare s2 " << sl.compare(s2) << std::endl;
    s2.headDelete();
    s2.headDelete();
    s2.PrintList();
    std::cout << "after delete 2" << std::endl;
    s2.reverse();
    s2.PrintList();
    std::cout << "reverse again" << std::endl;
    s2.headDelete();
    s2.reverse();
    s2.PrintList();
    /*
    sl.headAdd(0.8);
    sl.PrintList();
    sl.tailDelete();
    sl.PrintList();
    sl.append(4.4);
    sl.PrintList();
    sl.remove(3.3);
    //sl.headDelete();
    sl.PrintList();
    sl.headAdd(9.9);
    sl.PrintList();
    sl.remove(9.9);
    sl.PrintList();
    */
}