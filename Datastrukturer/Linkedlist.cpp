#include "Linkedlist.h"

template <class T>
void Linkedlist<T>::AddToList(T objectType, Node<T> *nextNode)
{
	Node<T> newNode = new Node<T>;
	newNode->data = objectType;

	if (linkedList->count == 0)
	{
		newNode->next = NULL;
		linkedList = newNode;
	}
	else
	{
		newNode->next = linkedList->first;
		linkedList->first = newNode;
	}
}

void DeleteLastFromList(LinkedList *linkedList)
{
	linkedList->last = linkedList->last->previous;
	free(linkedList->last->next->txt);
	linkedList->last->next->previous = NULL;
	free(linkedList->last->next);
	linkedList->last->next = NULL;
}