#include "Stack.h"

// constructor
Stack::Stack() {
	// initializes head as NULL at first 
	this->head = NULL;
}

void Stack::push(StackItem* item) {
	bool dummy = true;
	int n = 0;
	// creates a temp pointer with dummy variables that will be changed
	StackItem* temp = new StackItem(dummy, n);

	//temp takes the data from item pointer and becomes the head 
	temp->op = item->op;
	temp->isOperator = item->isOperator;
	temp->n = item->n;
	temp->next = head;
	head = temp;
}

StackItem* Stack::pop() {

	// if the stack is empty, then an error message will be shown to user
	if (isEmpty()) {
		std::cout << "The stack is empty." << std::endl;
	}
	else {

		// create a temp pointer, move the head to next element and delete the temp pointer
		StackItem* temp = head;
		head = head->next;
		return temp;
		delete temp;
	}
}

StackItem* Stack::top() {

	// if the stack is empty, then an error message will be shown to user
	if (isEmpty()) {
		std::cout << "The stack is empty." << std::endl;
	}

	// simply return the head
	else {
		return this->head;
	}
}

bool Stack::isEmpty() {

	// checks if the stack is empty or not by looking at the head
	return (this->head == NULL);
}

Stack::~Stack() {

	StackItem* i = this->head;
	// pop function is called until there is no element in the stack
	while (head != NULL) {
		StackItem* temp = i->next;
		delete i;
		i = temp;
	}
}