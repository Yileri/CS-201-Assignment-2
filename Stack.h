#ifndef __STACK__
#define __STACK__

#include "StackItem.h"

class Stack {

	StackItem* head;

public:
	Stack();
	~Stack();
	void push(StackItem* item);
	StackItem* pop();
	StackItem* top();
	bool isEmpty();
};

#endif
