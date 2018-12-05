#pragma once
#include "DoubleNode.h"
#include "enums.h"


template<typename...> class Doublelinkedlist;
template<typename T, typename K>
class Doublelinkedlist<T, K>
{
private:
	DoubleNode<T, K> *head;
	DoubleNode<T, K> *tail;
	int list_size;
	//int max_size; ska inte behövas
	
public:
	Doublelinkedlist();
	~Doublelinkedlist();
	T getHead();
	T getTail();
	bool InsertFirst(T data, K key);


};

template<typename T, typename K>
Doublelinkedlist<T, K>::Doublelinkedlist()
{
	//this->max_size = max_size;
	this->head = nullptr;
	this->tail = nullptr;
	this->list_size = 0;
}

template<typename T, typename K>
Doublelinkedlist<T, K>::~Doublelinkedlist()
{
	DoubleNode<T, K> *temp = nullptr;
	for (int i = 0; i < this->list_size; i++) {
		temp = this->head->next;
		delete head;
		head = temp;
	}
}
template<typename T, typename K>
T Doublelinkedlist<T, K>::getHead() {
	return this->head->getData();
}
template<typename T, typename K>
T Doublelinkedlist<T, K>::getTail() {
	return this->tail->getData();
}

template<typename T, typename K>
bool Doublelinkedlist<T, K>::InsertFirst(T data, K key) {
	DoubleNode<T, K> *newNode = new DoubleNode<T, K>(data, key);
	if (this->list_size == 0)
		this->tail = newNode;
	else {
		newNode->next = this->head;
		this->head->prev = newNode;
	}
	this->head = newNode;
	this->list_size++;
	return true;
}
