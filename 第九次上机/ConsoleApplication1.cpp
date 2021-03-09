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
	void print_layer_mean_value();
	BinTreeNode<T>* nodeCreate(vector<T>Value, int len, int locate);
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
void BinTree<T>::print_layer_mean_value()
{
	queue<BinTreeNode<T>*> Q;
	BinTreeNode<T>* p = root;
	Q.push(p);
	int num, temp, i;
	while (!Q.empty())
	{
		num = Q.size();
		temp = 0;
		for (i = 0; i < num; i++)
		{
			p = Q.front();
			Q.pop();
			if (p->lChild != NULL) { Q.push(p->lChild); }
			if (p->rChild != NULL) { Q.push(p->rChild); }
			temp += p->data;
		}
		cout << (double)temp / (double)num << " ";
	}
}

int main()
{
	BinTree<int> Tree;
	Tree.create();
	Tree.print_layer_mean_value();
}