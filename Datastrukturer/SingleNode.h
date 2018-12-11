#pragma once
#include "Node.h"
template<typename...> class SingleNode;
template<typename T, typename K>
class SingleNode<T, K> : public Node<T, K>
{
private:

public:
	SingleNode(T data, K key);
	~SingleNode();
	SingleNode<T, K> *next;
};


template<typename T, typename K>
SingleNode<T, K>::SingleNode(T data, K key) : Node<T, K>(data, key)
{
	this->next = nullptr;
}

template<typename T, typename K>
SingleNode<T, K>::~SingleNode()
{
}
