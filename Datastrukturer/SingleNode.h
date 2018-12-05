#pragma once
#include "Node.h"
template<typename...> class SingleNode;
template<typename T, typename K>
class SingleNode<T, K> : public Node<T, K>
{
private:

public:
	SingleNode(T data, T key);
	~SingleNode();
	SingleNode<T> *next;
};


template<typename T, typename K>
SingleNode<T, K>::SingleNode(T data, T key) : Node<T>(data, key)
{
	this->next = nullptr;
}

template<typename T, typename K>
SingleNode<T, K>::~SingleNode()
{
}

