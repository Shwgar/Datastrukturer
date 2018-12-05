#pragma once
#include "DoubleNode.h"
template<class T>
class Doublelinkedlist
{
private:
	DoubleNode<T> *head;
	DoubleNode<T> *tail;
	int list_size;
	int max_size;
	
public:
	Doublelinkedlist(int max_size = 0);
	~Doublelinkedlist();

};

