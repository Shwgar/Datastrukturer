#pragma once
#include "Node.h"
template<class T>
class SingleNode : public Node<T>
{
private:

public:
	SingleNode<T> *next;
	SingleNode(T data, int key);
	~SingleNode();
};

template<class T>
SingleNode<T>::SingleNode(T data, int key) : Node<T>(data, key)
{
	this->next = nullptr;
}

template<class T>
SingleNode<T>::~SingleNode()
{
}
