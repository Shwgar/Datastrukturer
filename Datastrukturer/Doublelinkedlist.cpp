#include "Doublelinkedlist.h"


template<class T>
Doublelinkedlist<T>::Doublelinkedlist(int max_size)
{
	this->max_size = max_size;
}

template<class T>
Doublelinkedlist<T>::~Doublelinkedlist()
{
}
template<class T>
T* Doublelinkedlist<T>::getHead() {
	return this->head->data;
}
template<class T>
T* Doublelinkedlist<T>::getTail() {
	return this->tail->data;
}

template<class T>
LIST_ERRORS Doublelinkedlist<T>::Insert(T *data, int index) {

	


	if (linkedlist->counter >= linkedlist->maxsize)
		RemoveLast(linkedlist);
	Node * newnode = NewNode(id, txt);
	if (linkedlist->counter != 0) {
		newnode->next = linkedlist->head;
		linkedlist->head->prev = newnode;
	}
	if (linkedlist->counter == 0) {
		linkedlist->tail = newnode;
	}
	linkedlist->head = newnode;
	linkedlist->counter += 1;
}
