#pragma once
#include "SingleNode.h"
#include "enums.h"


template<class T>
class Linkedlist
{
private:
	SingleNode<T> *head;
	int list_size;

public:
	Linkedlist();
	~Linkedlist();
	SingleNode<T> getHead();
	int GetCount();
	bool InsertFirst(T data, int key);


};

template<class T>
Linkedlist<T>::Linkedlist()
{
	this->head = nullptr;
	this->list_size = 0;
}

template<class T>
Linkedlist<T>::~Linkedlist()
{
	SingleNode<T> *temp = nullptr;
	for (int i = 0; i < this->list_size; i++) {
		temp = this->head->next;
		delete head;
		head = temp;
	}
}

template<class T>
int Linkedlist<T>::GetCount() {
	return this->list_size;
}

template<class T>
SingleNode<T> Linkedlist<T>::getHead() {
	return *this->head;
}


template<class T>
bool Linkedlist<T>::InsertFirst(T data, int key) {
	SingleNode<T> *newNode = new SingleNode<T>(data, key);
	if (this->list_size != 0)
	{
		newNode->next = this->head;
	}
	this->head = newNode;
	this->list_size++;

	return true;
}
