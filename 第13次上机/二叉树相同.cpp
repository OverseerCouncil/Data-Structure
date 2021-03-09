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
	BinTreeNode<T>* nodeCreate(vector<T>Value);
	bool isSameTree_recursion(BinTreeNode<T>* p, BinTreeNode<T>* q);
	bool isSameTree_no_recursion(BinTreeNode<T>* p, BinTreeNode<T>* q);
};

template<typename T>
void BinTree<T>::create()
{
	int Input;
	vector<T> Value;
	while (cin >> Input)
	{
		Value.push_back(Input);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	root = nodeCreate(Value);
	cin.clear();
}

template<typename T>
BinTreeNode<T>* BinTree<T>::nodeCreate(vector<T>Value)
{
	Value.push_back(-1);
	queue<BinTreeNode<T>*> Q;
	BinTreeNode<T>* p = new BinTreeNode<T>(Value[0]);
	Q.push(p);
	BinTreeNode<T>* curL, * curR, * cur;
	for (int i = 1; i < Value.size() - 1; i = i + 2)
	{
		cur = Q.front();
		Q.pop();
		if (Value[i] != -1)
		{
			curL = new BinTreeNode<T>(Value[i]);
			cur->lChild = curL;
			Q.push(curL);
		}
		if (Value[i + 1] != -1)
		{
			curR = new BinTreeNode<T>(Value[i + 1]);
			cur->rChild = curR;
			Q.push(curR);
		}
	}
	return p;
}

template<typename T>
bool BinTree<T>::isSameTree_recursion(BinTreeNode<T>* p, BinTreeNode<T>* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	if (p->data != q->data)
	{
		return false;
	}
	return isSameTree_recursion(p->lChild, q->lChild) && isSameTree_recursion(p->rChild, q->rChild);
}

template<typename T>
bool BinTree<T>::isSameTree_no_recursion(BinTreeNode<T>* p, BinTreeNode<T>* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	queue<BinTreeNode<T>*> que1;
	queue<BinTreeNode<T>*> que2;
	que1.push(p);
	que2.push(q);
	int curNum1 = 0;
	int curNum2 = 0;
	bool flag = true;
	while (!que1.empty() && !que2.empty())
	{
		curNum1 = que1.size();
		curNum2 = que2.size();
		if (curNum1 != curNum2)
		{
			flag = false;
			break;
		}
		int curCount1 = 0;
		int curCount2 = 0;
		while (curCount1 < curNum1 && curCount2 < curNum2)
		{
			curCount1++;
			curCount2++;
			p = que1.front();
			que1.pop();
			q = que2.front();
			que2.pop();
			if (p->data != q->data)
			{
				flag = false;
				break;
			}
			if (p->lChild == NULL && q->lChild != NULL || p->lChild != NULL && q->lChild == NULL || p->rChild == NULL && q->rChild != NULL || p->rChild != NULL && q->rChild == NULL)
			{
				flag = false;
				break;
			}
			if (p->lChild)
			{
				que1.push(p->lChild);
			}
			if (p->rChild)
			{
				que1.push(p->rChild);
			}
			if (q->lChild)
			{
				que2.push(q->lChild);
			}
			if (q->rChild)
			{
				que2.push(q->rChild);
			}
		}
		if (flag == false)
		{
			break;
		}
	}
	if (flag == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	BinTree<int> Tree1;
	BinTree<int> Tree2;
	Tree1.create();
	Tree2.create();
	if (Tree1.isSameTree_recursion(Tree1.root, Tree2.root))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	if (Tree1.isSameTree_no_recursion(Tree1.root, Tree2.root))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
}