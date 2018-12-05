#pragma once
#include "DoubleNode.h"
#include "enums.h"


template<class T>
class Doublelinkedlist
{
private:
	DoubleNode<T> *head;
	DoubleNode<T> *tail;
	int list_size;
	//int max_size; ska inte behövas
	
public:
	Doublelinkedlist();
	~Doublelinkedlist();
	T getHead();
	T getTail();
	bool InsertFirst(T data, int key);


};

template<class T>
Doublelinkedlist<T>::Doublelinkedlist()
{
	//this->max_size = max_size;
	this->head = nullptr;
	this->tail = nullptr;
	this->list_size = 0;
}

template<class T>
Doublelinkedlist<T>::~Doublelinkedlist()
{
	DoubleNode<T> *temp = nullptr;
	for (int i = 0; i < this->list_size; i++) {
		temp = this->head->next;
		delete head;
		head = temp;
	}
}
template<class T>
T Doublelinkedlist<T>::getHead() {
	return this->head->getData();
}
template<class T>
T Doublelinkedlist<T>::getTail() {
	return this->tail->getData();
}

template<class T>
bool Doublelinkedlist<T>::InsertFirst(T data, int key) {
	DoubleNode<T> *newNode = new DoubleNode<T>(data, key);
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
