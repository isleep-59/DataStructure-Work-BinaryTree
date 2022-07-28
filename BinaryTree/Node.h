#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Pair {
	int first, second;
};

class Node {
public:
	char m_data;
	Pair m_pos;
	Node* child_l;
	Node* child_r;

	Node(char data = '#');
};