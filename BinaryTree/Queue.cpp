#include "Queue.h"

Queue::Queue() {
	Elem = (QElemtype*)malloc(QUEUE_MAX_SIZE * sizeof(QElemtype));
	sz = QUEUE_MAX_SIZE;
	front = rear = 0;
}

Queue::~Queue() {
	free(Elem);
	front = rear = sz = 0;
}

bool Queue::Empty() {
	return front == rear;
}

void Queue::Push(QElemtype data) {
	if((rear + 1) % sz == front) {
		cout << "ERROR: THE QUEUE IS FULL !" << endl;
		return;
	}
	Elem[rear++] = data;
	rear %= sz;
}

void Queue::Pop() {
	if (Empty()) {
		cout << "ERROR: THE QUEUE IS EMPTY !" << endl;
		return;
	}
	front++;
	front %= sz;
}

void Queue::Clear() {
	front = rear = 0;
}

QElemtype Queue::Front() {
	return Elem[front];
}

QElemtype Queue::Back() {
	return Elem[rear];
}

int Queue::Size() {
	return rear - front + sz;
}