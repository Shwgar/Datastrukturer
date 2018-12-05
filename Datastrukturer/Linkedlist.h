#pragma once
#include "Node.h"

template <class T>
class Linkedlist
{
private:
	int size;
	Node<T> head;

	
public:
	Linkedlist()
	{
		this->size = 0;
		head = nullptr;
	}

	void Insert(T objectType, Node *nextNode)
	{
		Node<T> newNode = new Node<T>;
		newNode->data = objectType;

		if (this->size == 0)
		{
			newNode->next = NULL;
			this->head = newNode;
		}
		else
		{
			newNode->next = linkedList->first;
			linkedList->first = newNode;
		}
	}
	void Delete(int position);
};

//insertion (plats) = 0 läggs först
//deletion (plats)
//