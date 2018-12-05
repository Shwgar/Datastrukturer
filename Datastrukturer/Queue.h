#pragma once

template <class T>
class Queue
{
public:
	Queue(T objectType, int capacity);
	~Queue();

private:
	//T* queue;
	int capacity;
};

