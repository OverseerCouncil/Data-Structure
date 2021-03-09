#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template<typename T>
class BinTreeNode
{
public:
	T data;
	BinTreeNode* lChild, * rChild;
	BinTreeNode(const T& t) :data(t), lChild(NULL), rChild(NULL) {};
};

template<typename T>
class BinTree
{
public:
	BinTreeNode<T>* root;
	void create();
	BinTreeNode<T>* nodeCreate(vector<T>Value, int len, int locate);
	void SwapTree(BinTreeNode<T>* opr);
};

template<typename T>
void BinTree<T>::create()
{
	int Input;
	int loc = 0;
	vector<T> Value;
	while (cin >> Input)
	{
		Value.push_back(Input);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	root = nodeCreate(Value, Value.size(), loc);
}

template<typename T>
BinTreeNode<T>* BinTree<T>::nodeCreate(vector<T>Value, int len, int locate)
{
	if (Value.empty()) { return NULL; }
	BinTreeNode<T>* p = NULL;
	if (locate < len && Value[locate] != -1)
	{
		p = new BinTreeNode<T>(Value[locate]);
		p->lChild = nodeCreate(Value, len, 2 * locate + 1);
		p->rChild = nodeCreate(Value, len, 2 * locate + 2);
	}
	return p;
}

template<typename T>
void BinTree<T>::SwapTree(BinTreeNode<T>* opr)
{
	BinTreeNode<T>* temp = new BinTreeNode<T>;
	if (opr)
	{
		temp = opr->rChild;
		opr->rChild = opr->lChild;
		opr->lChild = temp;
		SwapTree(opr->lChild);
		SwapTree(opr->rChild);
	}
	else
	{
		return;
	}
}

int main()
{
	BinTree<int> Tree;
	Tree.create();
	Tree.SwapTree(Tree.root);
}