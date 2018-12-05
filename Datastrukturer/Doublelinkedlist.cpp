//#include "Doublelinkedlist.h"
//
//template class Doublelinkedlist<int>;
//template<class T>
//Doublelinkedlist<T>::Doublelinkedlist()
//{
//	//this->max_size = max_size;
//	this->head = nullptr;
//	this->tail = nullptr;
//	this->list_size = 0;
//}
//
//template<class T>
//Doublelinkedlist<T>::~Doublelinkedlist()
//{
//	DoubleNode<T> *temp = nullptr;
//	for (int i = 0; i < this->list_size; i++) {
//		temp = this->head->next;
//		delete head;
//		head = temp;
//	}
//}
//template<class T>
//T Doublelinkedlist<T>::getHead() {
//	return this->head->getData();
//}
//template<class T>
//T Doublelinkedlist<T>::getTail() {
//	return this->tail->getData();
//}
//
//template<class T>
//bool Doublelinkedlist<T>::InsertFirst(T data, int key) {
//	DoubleNode<T> *newNode = new DoubleNode<T>(data,key);
//	if (this->list_size == 0)
//		this->tail = newNode;
//	else {
//		newNode->next = this->head;
//		this->head->prev = newNode;
//	}
//	this->head = newNode;
//	this->list_size++;
//	return true;
//}
