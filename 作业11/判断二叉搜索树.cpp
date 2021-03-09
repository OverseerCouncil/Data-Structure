/* 使用前序和中序序列创建，以结点值为关键值 */
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
	bool IsBST(BinTreeNode<T>* sub);
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
bool BinTree<T>::IsBST(BinTreeNode<T>* sub)
{
	bool left, right;
	if (sub->lChild == NULL)
	{
		left = true;
	}
	else
	{
		left = ((IsBST(sub->lChild)) && (sub->data > sub->lChild->data));
	}
	if (sub->rChild == NULL)
	{
		right = true;
	}
	else
	{
		right = ((IsBST(sub->rChild)) && (sub->data < sub->rChild->data));
	}
	return (left && right);
}

int main()
{
	BinTree<int> Tree;
	Tree.PreInPost();
	Tree.InOrderPrint(Tree.root);
	if (Tree.IsBST(Tree.root)==true)
	{
		cout << "是二叉搜索树" << endl;
	}
	else
	{
		cout << "不是二叉搜索树" << endl;
	}
}