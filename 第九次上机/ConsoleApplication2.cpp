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
	void recursive_f(BinTreeNode<T>* root);
	void non_recursive_f(BinTreeNode<T>* root);
	void printBinTreeList(BinTreeNode<T>* root);
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
void BinTree<T>::recursive_f(BinTreeNode<T>* p)
{
	if (p == NULL)return;
	recursive_f(p->lChild);
	recursive_f(p->rChild);
	BinTreeNode<T>* temp = p->rChild;
	p->rChild = p->lChild;
	p->lChild = NULL;
	while (p->rChild)p = p->rChild;
	p->rChild = temp;
}

template<typename T>
void BinTree<T>::non_recursive_f(BinTreeNode<T>* p)
{
	if (p == NULL)return;
	BinTreeNode<T>* cur = p;
	while (cur)
	{
		if (cur->lChild)
		{
			BinTreeNode<T>* q = cur->lChild;
			while (q->rChild)q = q->rChild;
			q->rChild = cur->rChild;
			cur->rChild = cur->lChild;
			cur->lChild = NULL;
		}
		cur = cur->rChild;
	}
}

template<typename T>
void BinTree<T>::printBinTreeList(BinTreeNode<T>* p)
{
	if (p != NULL)
	{
		cout << p->data<<" ";
		if (p->lChild != NULL || p->rChild != NULL)
		{
			printBinTreeList(p->lChild);
			printBinTreeList(p->rChild);
		}
	}
}

int main()
{
	BinTree<int> Tree;
	Tree.create();
	Tree.recursive_f(Tree.root);
	Tree.printBinTreeList(Tree.root);
}