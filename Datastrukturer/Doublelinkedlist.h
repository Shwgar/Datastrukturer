#pragma once
#include "DoubleNode.h"


template<typename...> class Doublelinkedlist;
template<typename T, typename K>
class Doublelinkedlist<T, K>
{
private:
	DoubleNode<T, K> *head;
	DoubleNode<T, K> *tail;
	int list_size;

public:
	Doublelinkedlist();
	~Doublelinkedlist();
	T getHead();
	T getTail();
	int GetCount();
	void InsertFirst(T data, K key);
	void InsertLast(T data, K key);
	bool InsertAfterIndex(T data, K key, int index);
	bool InsertAfterKey(T data, K key, K searchKey);
	T DeleteFirst();
	T DeleteLast();
	T DeleteKey(K key);
	T Search(K key);
};

template<typename T, typename K>
Doublelinkedlist<T, K>::Doublelinkedlist()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->list_size = 0;
}

template<typename T, typename K>
Doublelinkedlist<T, K>::~Doublelinkedlist()
{
	DoubleNode<T, K> *tempNode = nullptr;
	while (this->head != nullptr) {
		tempNode = this->head->next;
		delete[] head;
		this->head = tempNode;
	}
}
template<typename T, typename K>
int Doublelinkedlist<T, K>::GetCount() {
	return this->list_size;
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
void Doublelinkedlist<T, K>::InsertFirst(T data, K key) {
	DoubleNode<T, K> *newNode = new DoubleNode<T, K>(data, key);
	if (this->list_size == 0)
		this->tail = newNode;
	else {
		newNode->next = this->head;
		this->head->prev = newNode;
	}
	this->head = newNode;
	this->list_size++;
}
template<typename T, typename K>
void Doublelinkedlist<T, K>::InsertLast(T data, K key) {
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
}

template<typename T, typename K>
bool Doublelinkedlist<T, K>::InsertAfterIndex(T data, K key, int index) {
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
	return true;
}
template<typename T, typename K>
bool Doublelinkedlist<T, K>::InsertAfterKey(T data, K key, K searchKey) {
	if (this->list_size == 0)
		return false;
	DoubleNode<T, K> *newNode = new DoubleNode<T, K>(data, key);
	DoubleNode<T, K> *tempNode = this->head;

	while (tempNode != nullptr && tempNode->getKey() != searchKey)
		tempNode = tempNode->next;
	if (tempNode == nullptr) return false;

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
	return true;
}
template<typename T, typename K>
T Doublelinkedlist<T, K>::DeleteFirst() {
	if (this->list_size == 0)
		throw std::underflow_error("List is empty");
	DoubleNode<T, K> tempNode = *this->head;
	delete(this->head);
	if (tempNode.next == nullptr) {
		this->tail = nullptr;
		this->head = nullptr;
	}	
	else {
		tempNode.next->prev = nullptr;
		this->head = tempNode.next;
	}
	this->list_size--;
	return tempNode.getData();
}
template<typename T, typename K>
T Doublelinkedlist<T, K>::DeleteLast() {
	if (this->list_size == 0)
		throw std::underflow_error("List is empty");
	DoubleNode<T, K> tempNode = *this->tail;
	delete(this->tail);
	if (tempNode.prev == nullptr) {
		this->head = nullptr;
		this->tail = nullptr;
	}
	else {
		tempNode.prev->next = nullptr;
		this->tail = tempNode.prev;
	}
	this->list_size--;
	return tempNode.getData();
}
template<typename T, typename K>
T Doublelinkedlist<T, K>::DeleteKey(K searchKey) {
	if (this->list_size == 0)
		throw std::underflow_error("List is empty");
	DoubleNode<T, K> *tempNode = this->head;

	while (tempNode != nullptr && tempNode->getKey() != searchKey)
		tempNode = tempNode->next;
	if (tempNode == nullptr) throw std::invalid_argument("Key not found in list");

	DoubleNode<T, K> deleteNode = *tempNode;
	delete(tempNode);
	if (this->list_size == 1) {
		this->head = nullptr;
		this->tail = nullptr;
	}
	else if (deleteNode.next == nullptr) {
		this->tail = deleteNode.prev;
		deleteNode.prev->next = nullptr;
	}
	else if (deleteNode.prev == nullptr) {
		this->head = deleteNode.next;
		deleteNode.next->prev = nullptr;
	}
	else {
		deleteNode.next->prev = deleteNode.prev;
		deleteNode.prev->next = deleteNode.next;
	}
	this->list_size--;
	return deleteNode.getData();
}
template<typename T, typename K>
T Doublelinkedlist<T, K>::Search(K searchKey) {
	if (this->list_size == 0)
		throw std::underflow_error("List is empty");
	DoubleNode<T, K> *tempNode = this->head;
	if (tempNode->getKey() == searchKey)
	{
		return tempNode->getData();
	}
	while (tempNode != nullptr && tempNode->getKey() != searchKey)
	{
		tempNode = tempNode->next;
	}
	if (tempNode == nullptr)
		throw std::invalid_argument("Search key not in list");
	return tempNode->getData();

}