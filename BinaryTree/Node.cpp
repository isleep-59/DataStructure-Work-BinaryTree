#include "Node.h"

Node::Node(char data) {
	m_data = data;
	m_pos = { 0, 0 };
	child_l = NULL;
	child_r = NULL;
}