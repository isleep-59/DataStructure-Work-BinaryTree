#include "Stack.h"

Stack::Stack() {
	Elem = (SElemtype*)malloc(STACK_INIT_SIZE * sizeof(SElemtype));
	sz = STACK_INIT_SIZE;
	top = -1;
}

Stack::~Stack() {
	free(Elem);
	top = -1;
	sz = 0;
}

bool Stack::Empty() {
	return top == -1;
}

void Stack::Push(SElemtype data) {
	if (top == sz - 1) {
		Elem = (SElemtype*)realloc(Elem, (sz + STACK_INCREASEMENT) * sizeof(SElemtype));
		sz += STACK_INCREASEMENT;
	}
	Elem[++top] = data;
}

void Stack::Pop() {
	if (Empty()) {
		cout << "ERROR: THE STACK IS EMPTY !" << endl;
		return;
	}
	top--;
}

void Stack::Clear() {
	top = -1;
}

int Stack::Size() {
	return top + 1;
}

SElemtype Stack::Top() {
	return Elem[top];
}