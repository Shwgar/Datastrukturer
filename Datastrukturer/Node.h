#pragma once
template<class T>
class Node
{
protected:
	T data;
	int key;
public:
	//Node<T> *next;
	Node(T data, int key);
	T getData();
	int getKey();
	virtual ~Node();
};

template<class T>
Node<T>::Node(T data, int key) {
	this->data = data;
	this->key = key;
	// this->next = nullptr;
}
template<class T>
T Node<T>::getData() {
	return this->data;
}
template<class T>
int Node<T>::getKey() {
	return this->key;
}
template<class T>
Node<T>::~Node() {
	//delete this->data;
}

