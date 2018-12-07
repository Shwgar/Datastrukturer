#pragma once
#include "SingleNode.h"
#include "enums.h"

template<typename...> class Linkedlist;
template<typename T, typename K>
class Linkedlist<T, K>
{
private:
	SingleNode<T, K> *head;
	int list_size;

public:
	Linkedlist();
	~Linkedlist();
	SingleNode<T, K>* getHead();
	int GetCount();
	bool InsertFirst(T data, K key);
	bool InsertAfterIndex(T data, K key, int indexnr);
	bool InsertAfterKey(T data, K insertKey, K searchKey);
	bool DeleteIndex(int indexnr);
	bool DeleteKey(K searchKey);
	T Search(K searchKey);
};

template<typename T, typename K>
Linkedlist<T, K>::Linkedlist()
{
	this->head = nullptr;
	this->list_size = 0;
}

template<typename T, typename K>
Linkedlist<T, K>::~Linkedlist()
{
	SingleNode<T, K> *temp = nullptr;
	for (int i = 0; i < this->list_size; i++) {
		temp = this->head->next;
		delete head;
		head = temp;
	}
}

template<typename T, typename K>
int Linkedlist<T, K>::GetCount() {
	return this->list_size;
}

template<typename T, typename K>
SingleNode<T, K>* Linkedlist<T, K>::getHead() {
	return this->head;
}


template<typename T, typename K>
bool Linkedlist<T, K>::InsertFirst(T data, K key) {
	SingleNode<T, K> *newNode = new SingleNode<T, K>(data, key);
	if (this->list_size != 0)
	{
		newNode->next = this->head;
	}
	this->head = newNode;
	this->list_size++;

	return true;
}

template<typename T, typename K>
bool Linkedlist<T, K>::InsertAfterIndex(T data, K key, int indexnr)
{
	if (indexnr > list_size) return false;
	int index = 0;
	SingleNode<T, K> *newNode = new SingleNode<T, K>(data, key);
	SingleNode<T, K> *tempNode = this->getHead()->next;
	for (int i = 1; i < indexnr; i++)
	{
		if (indexnr == 2)
		{
			newNode->next = tempNode;
			this->head->next = newNode;
			this->list_size++;
			return true;
		}
		else if (i < indexnr)
		{
			tempNode = tempNode->next;
		}
		else if (i == indexnr)
		{
			newNode->next = tempNode->next;
			tempNode->next = newNode;
			this->list_size++;
			return true;
		}

	}
}

template<typename T, typename K>
bool Linkedlist<T, K>::InsertAfterKey(T data, K insertKey, K searchKey)
{

	int index = 0;
	SingleNode<T, K> *newNode = new SingleNode<T, K>(data, insertKey);
	SingleNode<T, K> *tempNode = this->getHead();
	for (int i = 0; i < list_size; i++)
	{
		if (i == 0 && searchKey == tempNode->getKey())
		{
			newNode->next = tempNode;
			this->head->next = newNode;
			this->list_size++;
			return true;
		}
		else if (searchKey == tempNode->getKey())
		{
			newNode->next = tempNode->next;
			tempNode->next = newNode;
			this->list_size++;
			return true;
		}
		else
		{
			if (tempNode->next == nullptr)
			{
				return false;
			}
			tempNode = tempNode->next;
		}

	}
}
template<typename T, typename K>
bool Linkedlist<T, K>::DeleteIndex(int indexnr)
{
	SingleNode<T, K> *tempNode = this->getHead();
	SingleNode<T, K> *preNode;
	int counter = 1;
		if (counter == indexnr && counter == 1)
		{
			this->head = tempNode->next;
			delete tempNode;
			delete preNode;
		}
		while (counter != indexnr && tempNode != NULL)
		{
			preNode = tempNode;
			tempNode = tempNode->next;
			counter++;
		}
		if (tempNode == NULL) return false;
		preNode->next = tempNode->next;
		delete tempNode;
		return true;
}

template<typename T, typename K>
bool Linkedlist<T, K>::DeleteKey(K searchKey)
{
	SingleNode<T, K> *tempNode = this->getHead();
	SingleNode<T, K> *preNode;
	if (tempNode->getKey() == searchKey)
	{
		this->head = tempNode->next;
		delete tempNode;
		delete preNode;
	}
	while (tempNode != NULL && tempNode->getKey() != searchKey)
	{
		preNode = tempNode;
		tempNode = tempNode->next;
	}
	if (tempNode == NULL) return false;
	preNode->next = tempNode->next;
	delete tempNode;
	return true;
}

template<typename T, typename K>
T Linkedlist<T, K>::Search(K searchKey)
{
	SingleNode<T, K> *tempNode = this->getHead();
	if (tempNode->getKey() == searchKey)
	{
		return tempNode->getData();
	}
	while (tempNode != NULL && tempNode->getKey() != searchKey)
	{
		tempNode = tempNode->next;
	}
	if (tempNode == NULL) return NULL;
	return tempNode->getData();

}

