#include "Stack.h"

#include <iostream>
#include <sstream>
#include <string>


Stack::Stack() {
	this->head = NULL;	
}

Stack::~Stack() {
	delete this->head;
}

bool Stack::isEmpty() {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

StackItem* Stack::top() {
	if (head != NULL) {
		return head;
	}
		return NULL;
}

StackItem* Stack::pop() {
    while (head != NULL) {
	    StackItem* popped = head->next;
	    StackItem* result = head;
	    head = popped;
	    return result;
    }
	    return NULL;
}

void Stack::push(StackItem* item) {
	if (head == NULL) {
		head = item;
	}
	else {
		StackItem* node = head;
		head = item;
		head->next = node;
				
		}
	}






