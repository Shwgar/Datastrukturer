#pragma once
#include "Node.h"
template<typename...> class DoubleNode;
template<typename T, typename K>
class DoubleNode<T, K> : public Node<T, K>
{
private:

public:
	DoubleNode<T, K> *prev;
	DoubleNode<T, K> *next;
	DoubleNode(T data, K key);
	~DoubleNode();
};

template<typename T, typename K>
DoubleNode<T, K>::DoubleNode(T data, K key) : Node<T, K>(data, key)
{
	this->prev = nullptr;
	this->next = nullptr;
}

template<typename T, typename K>
DoubleNode<T, K>::~DoubleNode()
{
}

