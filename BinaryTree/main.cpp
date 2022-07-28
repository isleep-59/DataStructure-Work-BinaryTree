#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "BiTree.h"

signed main() {
	freopen("in.txt", "r", stdin);

	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": " << endl;
		cout << "(1) ����������" << endl;
		BiTree T;
		T.Create();
		T.Display();
		cout << "(2) �ݹ������������������: " << endl << '\t';
		PreOrderTraverse(T.m_rt); cout << endl;
		cout << "(3) �ݹ������������������: " << endl << '\t';
		InOrderTraverse(T.m_rt); cout << endl;
		cout << "(4) �ǵݹ������������������: " << endl << '\t';
		Stack_InOrderTraverse(T.m_rt); cout << endl;
		cout << "(5) �ݹ������������������: " << endl << '\t';
		PostOrderTraverse(T.m_rt); cout << endl;
		cout << "(6) BFS����������㼶����: " << endl << '\t';
		LevelOrderTraverse(T); cout << endl;
		cout << "(7) �����������Ϊ0�Ľ����: " << endl << '\t';
		cout << T.m_0_Nodes << endl;
		cout << "(8) �����������Ϊ1�Ľ����: " << endl << '\t';
		cout << T.m_1_Nodes << endl;
		cout << "(9) �����������Ϊ2�Ľ����: " << endl << '\t';
		cout << T.m_2_Nodes << endl;
		cout << "(10) ������������еĽ����: " << endl << '\t';
		cout << T.m_all_Nodes << endl;
		cout << "(11) ����������ĸ߶�: " << endl << '\t';
		cout << T.m_height << endl;
		cout << "(12) ���ҶԻ�������: " << endl;
		cout << "�Ի�ǰ: " << endl;
		T.Display();
		cout << endl;
		cout << "�Ի���: " << endl;
		SwapNodes(T.m_rt);
		T.Update();
		T.Display();
		cout << endl << endl;
		cout << "============================================================";
		cout << "============================================================";
		cout << endl << endl << endl << endl;
	}

	return 0;
}