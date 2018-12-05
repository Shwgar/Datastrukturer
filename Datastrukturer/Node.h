#pragma once
template<class T>
class Node
{
protected:
	T *data;
	Node *next;
public:
	Node(T data);
	T getData();
	~Node();
};

