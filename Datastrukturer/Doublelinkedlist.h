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
	DoubleNode<T, K>* getHead();
	DoubleNode<T, K>* getTail();
	int GetCount();
	bool InsertFirst(T data, K key);
	bool InsertLast(T data, K key);
	bool InsertAfter(T data, K key, int index);


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
int Doublelinkedlist<T, K>::GetCount() {
	return this->list_size;
}
template<typename T, typename K>
DoubleNode<T, K>* Doublelinkedlist<T, K>::getHead() {
	return this->head;
}
template<typename T, typename K>
DoubleNode<T, K>* Doublelinkedlist<T, K>::getTail() {
	return this->tail;
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
template<typename T, typename K>
bool Doublelinkedlist<T, K>::InsertLast(T data, K key) {
	DoubleNode<T, K> *newNode = new DoubleNode<T, K>(data, key);
	if (this->list_size == 0) {
		this->head = newNode;
	}
	else {
		newNode->prev = this->tail;
		this->tail->next = newNode;
	}
	this->tail = newNode;
	this->list_size++;
	return true;
}

template<typename T, typename K>
bool Doublelinkedlist<T, K>::InsertAfter(T data, K key, int index) {
	if (this->list_size == 0 || index < 1 || index > list_size)
		return false;
	DoubleNode<T, K> *newNode = new DoubleNode<T, K>(data, key);
	DoubleNode<T, K> *tempNode = this->head;
	for (int i = 1; i < index; i++) {
		tempNode = tempNode->next;
	}
	if (tempNode->next != nullptr) {
		newNode->next = tempNode->next;
		tempNode->next->prev = newNode;
	}
	else {
		tail = newNode;
	}
	tempNode->next = newNode;
	newNode->prev = tempNode;
	this->list_size++;
}