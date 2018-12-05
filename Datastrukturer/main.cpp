#include <iostream>
#include<string>
#include <vector>
#include "Doublelinkedlist.h"

void main() {
	std::cout << "hello world" << std::endl;
	std::cout << "hello ladaadad world" << std::endl;
	Doublelinkedlist<std::string> stringlist;
	//int * test = new int;
	//*test = 2;
	stringlist.InsertFirst("hej", 1);
	//stringlist.InsertFirst(44, 2);

	std::cout << stringlist.getHead() << " " << stringlist.getTail();

	system("pause");
 

}