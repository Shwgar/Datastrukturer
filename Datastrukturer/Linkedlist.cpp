#include "Linkedlist.h"



Linkedlist::Linkedlist()
{


}


Linkedlist::~Linkedlist()
{
}

#include "LinkedList.h"

void AddToList(LinkedList *linkedList, int id, const char *txt)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->id = id;
	newNode->txt = (char*)malloc(sizeof(char) * strlen(txt) + 1);
	strcpy(newNode->txt, txt);

	if (linkedList->count == 0)
	{
		newNode->next = NULL;
		newNode->previous = NULL;
		linkedList->first = newNode;
		linkedList->last = newNode;
	}
	else
	{
		linkedList->first->previous = newNode;
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