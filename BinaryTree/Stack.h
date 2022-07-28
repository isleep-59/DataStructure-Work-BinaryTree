#pragma once
#include "Node.h"
#define SElemtype Node*
#define STACK_INIT_SIZE 100
#define STACK_INCREASEMENT 50

class Stack {
private:
	SElemtype* Elem;
	int sz, top;

public:
	Stack();
	~Stack();
	bool Empty();
	void Push(SElemtype);
	void Pop();
	void Clear();
	int Size();
	SElemtype Top();
};