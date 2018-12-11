#pragma once
#include <exception>

template<typename T>
class Stack
{
public:
	Stack(const unsigned int capacity);
	~Stack();

	T Pop();
	T Peek() const;
	void Push(T object);

	bool IsFull() const;
	bool IsEmpty() const;

private:
	T* stack;
	int top;
	const unsigned int capacity;
};


template<typename T>
Stack<T>::Stack(const unsigned int capacity) : capacity(capacity)
{
	top = -1;
	stack = new T[capacity];
}


template<typename T>
Stack<T>::~Stack() 
{
	delete[] stack;
}


template<typename T>
T Stack<T>::Pop()
{
	if (IsEmpty())
		throw std::underflow_error("Stack is empty.");
	
	return stack[top--];
}


template<typename T>
T Stack<T>::Peek() const
{
	if (IsEmpty())
		throw std::underflow_error("Stack is empty.");

	return stack[top];
}


template<typename T>
void Stack<T>::Push(T object)
{
	if (IsFull())
		throw std::overflow_error("Stack is full.");

	stack[++top] = object;
}


template<typename T>
bool Stack<T>::IsFull() const
{
	return (top == (capacity - 1));
}


template<typename T>
bool Stack<T>::IsEmpty() const
{
	return (top == -1);
}
