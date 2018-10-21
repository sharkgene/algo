#include <iostream>
#include "DList.h"
#include "SList.h"
#include "Node.h"

int main()
{
	Slist<float> ls1;
	ls1.add(1.1);
	//ls1.add(0.1);
	ls1.add(6);
	//ls1.add(3.3);
    ls1.show();
    //ls1.ascSort();
    //ls1.show();
	std::cout << "copy ls1 to ls2 " << std::endl;
	Slist<float> ls2(ls1);
	std::cout << "show ls2 " << std::endl;
	ls2.show();
	std::cout << "reverse  ls2 " << std::endl;
	ls2.reverse();
	std::cout << "show ls2 " << std::endl;
	ls2.show();
	ls2.resShow();
	std::cout << "ls2 size" << std::endl;
	std::cout << ls2.size() << std::endl;
	std::cout << "ls2 find 0" << std::endl;
	std::cout << ls2.find(0) << std::endl;
	std::cout << "ls2 remove 6" << std::endl;
	ls2.remove(6);
	std::cout << "show ls1 " << std::endl;
	ls1.show();
	std::cout << "show ls2 " << std::endl;
    ls2.show();
}
 

