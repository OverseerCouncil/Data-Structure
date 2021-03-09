#include<iostream>
#include<vector>
#include<algorithm>

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
	void FreqSum();
	int SumSub(BinTreeNode<T>* sub, vector<T>& res);
	BinTreeNode<T>* nodeCreate(vector<T>Value, int len, int locate);
};

template<typename T>
void BinTree<T>::create()
{
	int Input;
	int loc = 0;
	vector<T> Value;
	int num;
	cin >> num;
	cin.get();
	while (cin >> Input)
	{
		Value.push_back(Input);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	root = nodeCreate(Value, num, loc);
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
void BinTree<T>::FreqSum()
{
	vector<T> result;
	SumSub(root, result);
	sort(result.begin(), result.end());
	int max = 1;
	int k = 1;
	for (int i = 0; i < result.size(); i = i + k)
	{
		for (k = 1; k < result.size() - i; k++)
		{
			if (result[k] != result[i])
			{
				max = (k > max) ? k : max;
				break;
			}
		}
	}
	for (int j = 0; j < result.size(); j++)
	{
		if (result[j] == result[j + max - 1])
		{
			cout << result[j] << " ";
		}
	}
}

template<typename T>
int BinTree<T>::SumSub(BinTreeNode<T>* sub, vector<T>& res)
{
	int left = 0;
	int right = 0;
	if (sub->lChild != NULL)
	{
		left = SumSub(sub->lChild, res);
	}
	if (sub->rChild != NULL)
	{
		right = SumSub(sub->rChild, res);
	}
	int x = left + right + sub->data;
	res.push_back(x);
	return x;
}

int main()
{
	BinTree<int> Tree;
	Tree.create();
	Tree.FreqSum();
}