#pragma once
template<class T>
class Node
{
protected:
	T *data;
public:
	Node<T> *next;
	Node(T data);
	T getData();
	~Node();
};

