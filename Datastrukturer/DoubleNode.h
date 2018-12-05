#pragma once
#include "Node.h"
template<class T>
class DoubleNode : public Node<T>
{
private:
	
public:
	DoubleNode<T> *prev;
	DoubleNode<T> *next;
	DoubleNode(T data, int key);
	~DoubleNode();
};

template<class T>
DoubleNode<T>::DoubleNode(T data, int key) : Node<T>(data, key)
{
	this->prev = nullptr;
	this->next = nullptr;
}

template<class T>
DoubleNode<T>::~DoubleNode()
{
}

