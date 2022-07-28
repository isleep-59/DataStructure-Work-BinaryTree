#include "BiTree.h"

BiTree::BiTree() {
	m_rt = NULL;
	m_height = m_0_Nodes = m_1_Nodes = m_2_Nodes = m_all_Nodes = 0;
}

Node* PreOrderBuild() {
	char data; cin >> data;
	if (data == '#') {
		return NULL;
	}
	
	Node* rt = new Node(data);
	rt->child_l = PreOrderBuild();
	rt->child_r = PreOrderBuild();
	return rt;
}

void PreOrderTraverse(Node* rt) {
	if (!rt)
		return;

	cout << rt->m_data << ' ';
	PreOrderTraverse(rt->child_l);
	PreOrderTraverse(rt->child_r);
}

void InOrderTraverse(Node* rt) {
	if (!rt)
		return;

	InOrderTraverse(rt->child_l);
	cout << rt->m_data << ' ';
	InOrderTraverse(rt->child_r);
}

void Stack_InOrderTraverse(Node* rt) {
	Stack s;
	while (rt || !s.Empty()) {
		while (rt) {
			s.Push(rt);
			rt = rt->child_l;
		}

		if (!s.Empty()) {
			rt = s.Top();
			s.Pop();
			cout << rt->m_data << ' ';
			rt = rt->child_r;
		}
	}
}

void PostOrderTraverse(Node* rt) {
	if (!rt)
		return;

	PostOrderTraverse(rt->child_l);
	PostOrderTraverse(rt->child_r);
	cout << rt->m_data << ' ';
}

void LevelOrderTraverse(BiTree T) {
	Queue q;
	for (q.Push(T.m_rt); !q.Empty(); q.Pop()) {
		Node* tmp = q.Front();

		cout << tmp->m_data << ' ';
		if (tmp->child_l) {
			q.Push(tmp->child_l);
		}
		if (tmp->child_r) {
			q.Push(tmp->child_r);
		}
	}
}

int Count_0_Nodes(Node* rt) {
	if (!rt)
		return 0;

	int ret = Count_0_Nodes(rt->child_l) + Count_0_Nodes(rt->child_r);
	if (!rt->child_l && !rt->child_r)
		ret += 1;
	return ret;
}

int Count_1_Nodes(Node* rt) {
	if (!rt)
		return 0;

	int ret = Count_1_Nodes(rt->child_l) + Count_1_Nodes(rt->child_r);
	if (!rt->child_l ^ !rt->child_r)
		ret += 1;
	return ret;
}

int Count_2_Nodes(Node* rt) {
	if (!rt)
		return 0;

	int ret = Count_2_Nodes(rt->child_l) + Count_2_Nodes(rt->child_r);
	if (rt->child_l && rt->child_r)
		ret += 1;
	return ret;
}

int Count_all_Nodes(Node* rt) {
	if (!rt)
		return 0;

	int ret = Count_all_Nodes(rt->child_l) + Count_all_Nodes(rt->child_r);
	return ret + 1;
}

void SwapNodes(Node* rt) {
	if (!rt) {
		return;
	}
	Node* tmp = rt->child_l;
	rt->child_l = rt->child_r;
	rt->child_r = tmp;
	SwapNodes(rt->child_l);
	SwapNodes(rt->child_r);
}

int GetDepth(Node* rt) {
	if (!rt) {
		return 0;
	}

	int depth_l = GetDepth(rt->child_l);
	int depth_r = GetDepth(rt->child_r);
	return (depth_l > depth_r ? depth_l : depth_r) + 1;
}

void BiTree::Update() {
	Queue q;
	for (q.Push(m_rt); !q.Empty(); q.Pop()) {
		Node* tmp = q.Front();
		Pair pos = tmp->m_pos;
			int increase = 2 * pow(2, m_height - pos.first - 1);

		if (tmp->child_l) {
			tmp->child_l->m_pos = Pair{ pos.first + 1, pos.second - increase };
			q.Push(tmp->child_l);
		}
		if (tmp->child_r) {
			tmp->child_r->m_pos = Pair{ pos.first + 1, pos.second + increase };
			q.Push(tmp->child_r);
		}
	}
}

void BiTree::Create() {
	m_rt = PreOrderBuild();
	m_height = GetDepth(m_rt);
	m_0_Nodes = Count_0_Nodes(m_rt);
	m_1_Nodes = Count_1_Nodes(m_rt);
	m_2_Nodes = Count_2_Nodes(m_rt);
	m_all_Nodes = Count_all_Nodes(m_rt);
	m_rt->m_pos = Pair{ 1, 2 * (int)pow(2, m_height - 1) };
	Update();
}

void BiTree::Display() {
	Queue q;
	char G[100][100];
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			G[i][j] = ' ';

	for (q.Push(m_rt); !q.Empty(); q.Pop()) {
		Node* tmp = q.Front();
		Pair pos = tmp->m_pos;
		G[2 * pos.first - 1][pos.second] = tmp->m_data;

		if (tmp->child_l) {
			q.Push(tmp->child_l);
			for (int i = tmp->child_l->m_pos.second; i < pos.second; ++i) {
				G[2 * pos.first - 1][i] = '-';
			}
			G[2 * pos.first][tmp->child_l->m_pos.second] = '|';
		}
		if (tmp->child_r) {
			q.Push(tmp->child_r);
			for (int i = tmp->child_r->m_pos.second; i > pos.second; --i) {
				G[2 * pos.first - 1][i] = '-';
			}
			G[2 * pos.first][tmp->child_r->m_pos.second] = '|';
		}
	}
	for (int i = 1; i <= 2 * m_height; ++i) {
		for (int j = 0; j < 100; ++j) {
			cout << G[i][j];
		}
		cout << endl;
	}
}