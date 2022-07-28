#pragma once
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

class BiTree {
public:
	Node* m_rt;
	int m_height, m_0_Nodes, m_1_Nodes, m_2_Nodes, m_all_Nodes;

	BiTree();
	void Create();
	void Display();
	void Update();
};

Node* PreOrderBuild();
void PreOrderTraverse(Node*);
void InOrderTraverse(Node*);
void Stack_InOrderTraverse(Node*);
void PostOrderTraverse(Node*);
void LevelOrderTraverse(BiTree);
int Count_0_Nodes(Node*);
int Count_1_Nodes(Node*);
int Count_2_Nodes(Node*);
int Count_all_Nodes(Node*);
void SwapNodes(Node*);
int GetDepth(Node*);
int GetBreath(Node*);