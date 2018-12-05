#include <iostream>

#include<string>
#include <vector>
#include "Doublelinkedlist.h"
#include "Linkedlist.h"
#include "SingleNode.h"

void main() {
	std::cout << "hello world" << std::endl;
	std::cout << "hello ladaadad world" << std::endl;
	/*Doublelinkedlist<std::string> stringlist;
	//int * test = new int;
	//*test = 2;
	stringlist.InsertFirst("hej", 1);
	//stringlist.InsertFirst(44, 2);

	std::cout << stringlist.getHead() << " " << stringlist.getTail();

	system("pause");*/

	Linkedlist<int> intlist;
	//int * test = new int;
	//*test = 2;
	intlist.InsertFirst(1, intlist.GetCount());
	intlist.InsertFirst(2, intlist.GetCount());
	//stringlist.InsertFirst(44, 2);

	std::cout << intlist.getHead();

	system("pause");
 

}