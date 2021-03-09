#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
#include<queue>
#include<string>

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
	void getMinDif()
	{
		int res = INT_MAX, pre = -1;
		stack<BinTreeNode<T>*> st;
		BinTreeNode<T>* p = root;
		while (p || !st.empty())
		{
			while (p)
			{
				st.push(p);
				p = p->lChild;
			}
			p = st.top();
			st.pop();
			if (pre != -1)
			{
				res = min(res, p->data - pre);
			}
			pre = p->data;
			p = p->rChild;
		}
		cout << res;
	}

};

template<typename T>
void BinTree<T>::create()
{
	ifstream in;
	in.open("input_12_1.txt");
	int i = 0;
	vector<T> Value;
	string Temp;
	do
	{
		in >> Temp;
		if (Temp!="null")
		{
			Value.push_back(atoi(Temp.c_str()));
		}
		else
		{
			Value.push_back(-1);
		}
	} while (in.get() != '\n');
	inFile.close();
	root = nodeCreate(Value);
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


int main()
{
	BinTree<int> Tree;
	Tree.create();
	Tree.getMinDif();
}