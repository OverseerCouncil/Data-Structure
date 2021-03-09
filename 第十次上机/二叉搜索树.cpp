#include<iostream>
#include<vector>

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
	vector<T> VLR, LVR;
	BinTreeNode<T>* createBT(T* VLR, T* LVR, int n);
	void PreInPost();
	void InOrderPrint(BinTreeNode<T>* sub);
	void PostOrderPrint(BinTreeNode<T>* sub);
	BinTreeNode<T>* DeleteSuperX(BinTreeNode<T>* cur, int x);
};

template<class T>
BinTreeNode<T>* BinTree<T>::createBT(T* VLR, T* LVR, int n)
{
	if (n == 0)return NULL;
	int k = 0;
	while (VLR[0] != LVR[k])k++;
	BinTreeNode<T>* t = new BinTreeNode<T>(VLR[0]);
	t->lChild = createBT(VLR + 1, LVR, k);
	t->rChild = createBT(VLR + k + 1, LVR + k + 1, n - k - 1);
	return t;
}

template<class T>
void BinTree<T>::PreInPost()
{
	int Input;
	while (cin >> Input)
	{
		VLR.push_back(Input);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	while (cin >> Input)
	{
		LVR.push_back(Input);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	root = createBT(VLR.data(), LVR.data(), VLR.size());
}

template<class T>
void BinTree<T>::InOrderPrint(BinTreeNode<T>* sub)
{
	if (sub != NULL)
	{
		InOrderPrint(sub->lChild);
		cout << sub->data << " ";
		InOrderPrint(sub->rChild);
	}
	return;
}

template<class T>
void BinTree<T>::PostOrderPrint(BinTreeNode<T>* sub)
{
	if (sub != NULL)
	{
		PostOrderPrint(sub->lChild);
		PostOrderPrint(sub->rChild);
		cout << sub->data << " ";
	}
	return;
}

template<class T>
BinTreeNode<T>* BinTree<T>::DeleteSuperX(BinTreeNode<T>* cur, int x)
{
	BinTreeNode<T>* p;
	if (cur->lChild != NULL)
	{
		cur->lChild = DeleteSuperX(cur->lChild, x);
	}
	if (cur->rChild != NULL)
	{
		cur->rChild = DeleteSuperX(cur->rChild, x);
	}
	if (cur->data >= x)
	{
		p = cur->lChild;
		delete cur;
		return p;
	}
	else
	{
		return cur;
	}
}

int main()
{
	BinTree<int> Tree;
	int x;
	cin >> x;
	Tree.PreInPost();
	Tree.DeleteSuperX(Tree.root, x);
	Tree.InOrderPrint(Tree.root);
	cout << endl;
	Tree.PostOrderPrint(Tree.root);
}