#pragma once
#include "Node.h"
template<class T>
class DoubleNode : public Node
{
private:
	
public:
	Node<T> *prev;
	DoubleNode(T data);
	~DoubleNode();
};

