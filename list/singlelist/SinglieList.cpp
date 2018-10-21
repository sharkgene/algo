#include "SingleList.h"

int main() 
{
    SingleList<int> sl;
    sl.headAdd(1);
    sl.tailAdd(2);
    sl.tailAdd(3);
    sl.tailAdd(4);
    sl.tailAdd(5);
    sl.tailAdd(6);
    sl.tailAdd(7);
    sl.tailAdd(8);
    auto node = sl.EntryNodeofLoop();
    std::cout << "loop node is " << node << std::endl;
    sl.LoopList(4);
    node = sl.EntryNodeofLoop();
    std::cout << "loop node is " << node << std::endl;
    
    if (node != nullptr)
        sl.UnLoopList(node);
    node = sl.EntryNodeofLoop();
    std::cout << "loop node is " << node << std::endl;

    node = sl.findList(8);
    node = sl.findList(9);

    /*
    SingleList<int> sl;
    std::cout << "print" << std::endl;
    sl.reverse();
    sl.printList();
    std::cout << "print" << std::endl;
    sl.tailAdd(2);
    sl.tailAdd(4);
    sl.tailAdd(6);
    sl.headAdd(1);
    sl.printList();
    sl.reverse();
    sl.printList();
    sl.sortList();
    sl.printList();

    SingleList<int> s2;
    s2.tailAdd(1);
    s2.tailAdd(9);
    s2.tailAdd(3);
    s2.tailAdd(8);
    s2.sortList();
    s2.printList();
    std::cout << "merge list" << std::endl;
    sl.mergeList(s2);
    sl.printList();
    sl.middleOfList();
    auto re = sl.findList(9);
    std::cout << re->data << std::endl;
    sl.findList(19);
    */
}