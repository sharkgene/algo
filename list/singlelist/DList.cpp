#include "DList.h"

int main()
{
    DList<int> dl;
    dl.PrintList();
    dl.TailAdd(1); 
    dl.TailAdd(2); 
    dl.PrintList();
    dl.HeadAdd(0);
    dl.ReversePrintList();
    dl.LastN(2);
    dl.LastN(3);
    dl.LastN(4);
}