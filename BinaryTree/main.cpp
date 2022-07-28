#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "BiTree.h"

signed main() {
	freopen("in.txt", "r", stdin);

	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": " << endl;
		cout << "(1) 以先序建树：" << endl;
		BiTree T;
		T.Create();
		T.Display();
		cout << "(2) 递归输出二叉树先序序列: " << endl << '\t';
		PreOrderTraverse(T.m_rt); cout << endl;
		cout << "(3) 递归输出二叉树中序序列: " << endl << '\t';
		InOrderTraverse(T.m_rt); cout << endl;
		cout << "(4) 非递归输出二叉树中序序列: " << endl << '\t';
		Stack_InOrderTraverse(T.m_rt); cout << endl;
		cout << "(5) 递归输出二叉树后序序列: " << endl << '\t';
		PostOrderTraverse(T.m_rt); cout << endl;
		cout << "(6) BFS输出二叉树层级序列: " << endl << '\t';
		LevelOrderTraverse(T); cout << endl;
		cout << "(7) 输出二叉树度为0的结点数: " << endl << '\t';
		cout << T.m_0_Nodes << endl;
		cout << "(8) 输出二叉树度为1的结点数: " << endl << '\t';
		cout << T.m_1_Nodes << endl;
		cout << "(9) 输出二叉树度为2的结点数: " << endl << '\t';
		cout << T.m_2_Nodes << endl;
		cout << "(10) 输出二叉树所有的结点数: " << endl << '\t';
		cout << T.m_all_Nodes << endl;
		cout << "(11) 输出二叉树的高度: " << endl << '\t';
		cout << T.m_height << endl;
		cout << "(12) 左右对换二叉树: " << endl;
		cout << "对换前: " << endl;
		T.Display();
		cout << endl;
		cout << "对换后: " << endl;
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