/* 采取前序中序序列创建两个二叉树，以二叉树结点值为关键值，将合并后二叉树放在第一个树 */
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
	void TwoInOne(BinTreeNode<T>* t1, BinTreeNode<T>* t2);
	void Insert(const T& e1, BinTreeNode<T>*& ptr);
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
void BinTree<T>::Insert(const T& e1, BinTreeNode<T>*& ptr)
{
	if (ptr == NULL)
	{
		ptr = new BinTreeNode<T>(e1);
		return;
	}
	else if (e1 < ptr->data)
	{
		Insert(e1, ptr->lChild);
	}
	else if (e1 > ptr->data)
	{
		Insert(e1, ptr->rChild);
	}
	else
	{
		return;
	}
}

template<class T>
void BinTree<T>::TwoInOne(BinTreeNode<T>* t1, BinTreeNode<T>* t2)
{
	if (t2 != NULL)
	{
		Insert(t2->data, t1);
		TwoInOne(t1, t2->lChild);
		TwoInOne(t1, t2->rChild);
	}
}

int main()
{
	BinTree<int> Tree1, Tree2;
	Tree1.PreInPost();
	Tree2.PreInPost();
	Tree1.TwoInOne(Tree1.root, Tree2.root);
	Tree1.InOrderPrint(Tree1.root);
}