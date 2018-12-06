#pragma once
#include <exception>

template<typename T>
class Queue
{
public:
	Queue(const int capacity);
	~Queue();

	T PopFront();
	T Peek() const;
	void PushBack(T objectType);

	bool IsFull() const;
	bool IsEmpty() const;	
	
private:
	T* queue;
	unsigned int size;
	unsigned int rear;
	unsigned int front;
	const unsigned int capacity;
};


template<typename T>
Queue<T>::Queue(const int capacity) : capacity(capacity)
{
	size = 0;
	front = 0;
	rear = capacity - 1;
	queue = new T[capacity];
}


template<typename T>
Queue<T>::~Queue()
{
	delete queue;
}


template<typename T>
T Queue<T>::Peek() const
{
	if (IsEmpty())
		throw std::underflow_error("Queue is empty.");
	
	return queue[front];
}


template<typename T>
T Queue<T>::PopFront()
{
	if (IsEmpty())
		throw std::underflow_error("Queue is empty.");

	T objectToReturn = queue[front];
	front = (front + 1) % capacity;
	size--;

	return objectToReturn;
}


template<typename T>
void Queue<T>::PushBack(T object)
{
	if (IsFull())
		throw std::overflow_error("Queue is full.");
	
	rear = (rear + 1) % capacity;
	queue[rear] = object;
	size++;
}


template<typename T>
bool Queue<T>::IsFull() const
{
	return (size == capacity);
}


template<typename T>
bool Queue<T>::IsEmpty() const
{
	return (size == 0);
}