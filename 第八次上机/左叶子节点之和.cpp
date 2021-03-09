/* 采用第一题方式构建二叉树 */
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

template<class T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T>* leftChild, * rightChild;
	BinTreeNode() :leftChild(NULL), rightChild(NULL) {};
	BinTreeNode(T x, BinTreeNode<T>* l = NULL, BinTreeNode<T>* r = NULL) :data(x), leftChild(l), rightChild(r) {};
};

template<class T>
class BinaryTree
{
protected:
	BinTreeNode<T>* root;
	vector<T> VLR, LVR;
	T RefValue;
	void postOrder(BinTreeNode<T>* Tree);
	void destroy(BinTreeNode<T>* subTree);
	void visit(BinTreeNode<T>*& Node) { cout << Node->data << " "; }
public:
	BinaryTree() :root(NULL) {};
	BinaryTree(T value) :RefValue(value), root(NULL) {};
	~BinaryTree() { destroy(root); }
	BinTreeNode<T>* createBT(T* VLR, T* LVR, int n);
	void PreInPost();
	int sumOfLeftLeaves(BinTreeNode<T>* root);
	void sumLeft();
};

template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T>* subTree)
{
	if (subTree != NULL)
	{
		destroy(subTree->leftChild);
		destroy(subTree->rightChild);
		delete subTree;
	}
}

template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T>* subTree)
{
	if (subTree != NULL)
	{
		postOrder(subTree->leftChild);
		postOrder(subTree->rightChild);
		visit(subTree);
	}
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::createBT(T* VLR, T* LVR, int n)
{
	if (n == 0)return NULL;
	int k = 0;
	while (VLR[0] != LVR[k])k++;
	BinTreeNode<T>* t = new BinTreeNode<T>(VLR[0]);
	t->leftChild = createBT(VLR + 1, LVR, k);
	t->rightChild = createBT(VLR + k + 1, LVR + k + 1, n - k - 1);
	return t;
}

template<class T>
void BinaryTree<T>::PreInPost()
{
	int Input;
	cout << "输入前序排列" << endl;
	while (cin >> Input)
	{
		VLR.push_back(Input);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	cout << "输入中序排列" << endl;
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
int BinaryTree<T>::sumOfLeftLeaves(BinTreeNode<T>* Tree)
{
	if (Tree == NULL)return 0;
	int sum = 0;
	stack<BinTreeNode<T>> Stack;
	Stack.push(*Tree);
	BinTreeNode<T> cur;
	while (!Stack.empty())
	{
		cur = Stack.top();
		Stack.pop();
		if (cur.rightChild != NULL)
		{
			if (cur.leftChild != NULL || cur.rightChild->rightChild == NULL)
			{
				Stack.push(*cur.rightChild);
			}
		}
		if (cur.leftChild != NULL)
		{
			if (cur.leftChild->leftChild == NULL && cur.leftChild->rightChild == NULL)
			{
				sum += cur.leftChild->data;
			}
			else
			{
				Stack.push(*cur.leftChild);
			}
		}
	}
	return sum;
}

template<class T>
void BinaryTree<T>::sumLeft()
{
	cout << sumOfLeftLeaves(root);
}

int main()
{
	BinaryTree<int> Tree;
	Tree.PreInPost();
	Tree.sumLeft();
}