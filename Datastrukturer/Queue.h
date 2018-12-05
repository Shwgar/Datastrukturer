#pragma once
#include <iostream>
#include <exception>

template<class T>
class Queue
{
public:
	Queue(int capacity);
	~Queue();

	T Peek();
	T PopFront();
	void PushBack(T objectType);

	void PrintFrontRear();
	void PrintQueue();

private:
	bool IsFull();
	bool IsEmpty();

	T* queue;
	int front;
	int rear;
	int size;
	unsigned int capacity;
};


template<class T>
Queue<T>::Queue(int capacity) : capacity(capacity)
{
	this->size = 0;
	this->front = 0;
	this->rear = capacity - 1;
	this->queue = new T[capacity];
}


template<class T>
Queue<T>::~Queue()
{
	delete this->queue;
}


template<class T>
T Queue<T>::Peek()
{
	if (this->size > 0)
	{
		return this->queue[front];
	}
}


template<class T>
T Queue<T>::PopFront()
{
	if (IsEmpty())
	{
		throw std::underflow_error("Queue is empty.");
	}

	T objectToReturn = this->queue[front];
	this->front = (this-> front + 1) % this->capacity;
	this->size -= 1;

	return objectToReturn;
}


template<class T>
void Queue<T>::PushBack(T objectType)
{
	if (not this->IsFull())
	{
		this->rear = (this->rear + 1) % this->capacity;
		queue[rear] = objectType;
		this->size += 1;
	}
}


template<class T>
void Queue<T>::PrintFrontRear()
{
	std::cout << "Size: " << this->size << std::endl;
	std::cout << "Front: " << this->front << std::endl;
	std::cout << "Rear: " << this->rear << std::endl << std::endl;
}


template<class T>
void Queue<T>::PrintQueue()
{
	for (int i = 0; i < (int)this->capacity; i++)
	{
		std::cout << queue[i] << " ";
	}

	std::cout << std::endl;
}


template<class T>
bool Queue<T>::IsFull()
{
	std::cout << "Size: " << this->size << " Capacity: " << this->capacity << std::endl;
	return (this->size == this->capacity);
}


template<class T>
bool Queue<T>::IsEmpty()
{
	return (this->size == 0);
}