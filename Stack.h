
#ifndef __STACK__
#define __STACK__
#include "StackItem.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Stack {

public:
	Stack();
	~Stack();
	void push(StackItem*);
	StackItem* pop();
	StackItem* top();
	bool isEmpty();

private:
	StackItem* head;
	
};
#endif