#pragma once
#include "Node.h"
#define QElemtype Node*
#define QUEUE_MAX_SIZE 100

class Queue {
private:
	QElemtype *Elem;
	int front, rear, sz;

public:
	Queue();
	~Queue();
	bool Empty();
	void Push(QElemtype);
	void Pop();
	void Clear();
	QElemtype Front();
	QElemtype Back();
	int Size();
};