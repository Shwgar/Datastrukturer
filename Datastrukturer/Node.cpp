#include "Node.h"


template<class T>
 Node<T>::Node(T data) {
	 this->data = data;
}
template<class T>
T Node<T>::getData() {
	return this->data;
}
template<class T>
 Node<T>::~Node() {
	 delete this->data;
	 delete this->next;
}
