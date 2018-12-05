#pragma once
#include "DoubleNode.h"
#include "enums.h"
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
	T* getHead();
	T* getTail();
	LIST_ERRORS Insert(T *data, int index = 0);
};

