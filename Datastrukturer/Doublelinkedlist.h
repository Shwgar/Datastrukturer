#pragma once
#include "Node.h"
template<class T>
class Doublelinkedlist
{
private:
	
public:
	typedef struct Node Node;
	struct Node {
		int id;
		char *txt;
		struct Node *next, *prev;
	};

	typedef struct {
		struct Node *head, *tail;
		int counter;
		int maxsize;
	} LinkedList;
	Doublelinkedlist();
	~Doublelinkedlist();
};

