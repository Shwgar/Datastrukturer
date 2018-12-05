#pragma once
#include "Node.h"
template<class T>
class SingleNode : public Node<T>
{
private:

public:
	SingleNode(T data, T key);
	~SingleNode();
	SingleNode<T> *next;
};

template<class T>
SingleNode<T>::SingleNode(T data, T key) : Node<T>(data, key)
{
	this->next = nullptr;
}

template<class T>
SingleNode<T>::~SingleNode()
{
}
